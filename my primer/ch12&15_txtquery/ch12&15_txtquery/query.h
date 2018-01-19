//
//  query.h
//
//
//  Created by ellen on 12/2/16.
//  Copyright © 2016 ellen. All rights reserved.
//

#ifndef query_h
#define query_h
#include <iostream>
#include <string>
#include <memory>
#include "textquery.h"

class Query_base {
    friend class Query;
protected:
    using line_no = TextQuery::line_no;
    virtual ~Query_base() = default;
    
private:
    virtual QueryResult eval(const TextQuery&) const = 0;
    
    virtual std::string rep() const = 0;
};

/**
 * @brief The WordQuery class
 *The only class that actually performs a query on the given TextQuery object.
 *No public members defined in this class. All operation are through the friend
 *class Query.
 */
class WordQuery : public Query_base{
    //class Query uses the wordquery constructor
    friend class Query;
    WordQuery(const std::string& s): query_word(s)
    { std::cout << "WordQuery::WordQuery(" + s + ")\n";}
    
    
    QueryResult eval(const TextQuery &t) const override
    {   return t.query(query_word); }
    std::string rep() const override
    {
        std::cout << "WordQuery::rep()\n";
        return query_word;
    }
        
    std::string query_word;
};

/**
 * @brief interface class to manage the Query_base inheritance hierachy
 */

class Query {
    friend Query operator ~(const Query& );
    friend Query operator &(const Query&, const Query& );
    friend Query operator |(const Query&, const Query& );
public:
    // build a new wordquery
    Query(const std::string &s) : q(new WordQuery(s))
    {  std::cout << "Query::Query(const std::string& s) where s="+s+"\n"; }
    
    //interface functions : call the corresponding query_base operatopns
    QueryResult eval(const TextQuery& t) const
    {  return q->eval(t);}
    std::string rep() const
    {  std::cout << "Query::rep() \n";
       return q->rep();
    }
    
private:
    // constructor only for friends
    Query(std::shared_ptr<Query_base> query) :  q(query)
    {  std::cout << "Query::Query(std::shared_ptr<Query_base> query)\n"; }
    
    std::shared_ptr<Query_base> q;
};

inline std::ostream& operator <<(std::ostream& os, const Query& query)
{
    return os << query.rep();  //make a virtual call through its Query_base pointer to rep()
}

/**
 * @brief The BinaryQuery class
 *An abstract class holds data needed by the query types that operate on two operands
 */
        
class BinaryQuery : public Query_base
{
protected:
    BinaryQuery(const Query& l, const Query& r, std::string s): lhs(l), rhs(r), opSym(s)
    {  std::cout << "BinaryQuery::BinaryQuery()  where s=" + s + "\n";}
    
    std::string rep() const override
    {
        std::cout << "BinaryQuery::rep()\n";
        return "(" + lhs.rep() + " " + opSym + " " + rhs.rep() + ")" ;
    }
        
    Query lhs, rhs;
    std::string opSym;
};

        

        
class OrQuery : public BinaryQuery
{
    friend Query operator |(const Query&, const Query&);
    
    OrQuery(const Query &left, const Query &right) : BinaryQuery(left, right, "|")
    { std::cout << "OrQuery::OrQuery\n";}
    
    QueryResult eval(const TextQuery&) const override;
};
        
inline Query operator |(const Query &lhs, const Query &rhs)
{   return std::shared_ptr<Query_base>(new OrQuery(lhs, rhs)); }


        
class AndQuery : public BinaryQuery
{
    friend Query operator &(const Query&, const Query&);
    AndQuery(const Query &left, const Query &right) : BinaryQuery(left, right, "&")
    { std::cout << "AndQuery::AndQuery()\n"; }
    
    // inherits rep()  &  define eval()
    QueryResult eval(const TextQuery&) const override;
};
        
inline Query operator &(const Query &lhs, const Query &rhs)
{   return std::shared_ptr<Query_base>(new AndQuery(lhs, rhs)); }


class NotQuery : public Query_base
{
    friend Query operator ~(const Query& operand);
    NotQuery(const Query& q) : query(q)
    {  std::cout << "NotQuery::NotQuery()\n"; }
    
    std::string rep() const override
    {   std::cout << "NotQuery::rep()\n";
        return "~(" + query.rep() + ")"; }
    QueryResult eval(const TextQuery &) const override;
    
    Query query;
};
        
inline Query operator ~(const Query& operand)
{   return std::shared_ptr<Query_base>(new NotQuery(operand)); }
        

        
        
        





#endif /* query_h */
