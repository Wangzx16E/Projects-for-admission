//
//  query.cpp
//  ch12&15_txtquery
//
//  Created by ellen on 12/4/16.
//  Copyright © 2016 ellen. All rights reserved.
//

#include <algorithm>
#include "query.h"

QueryResult AndQuery::eval(const TextQuery &text) const
{
    QueryResult left = lhs.eval(text), right = rhs.eval(text);
    
    std::shared_ptr<std::set<line_no>> ret_lines = std::make_shared<std::set<line_no>>();
    
    //write the intersection of two ranges to a destination iterator
    std::set_intersection(left.begin(), left.end(), right.begin(), right.end(),
                          std::inserter(*ret_lines, ret_lines->begin()));
    
    return QueryResult(rep(), ret_lines, left.get_file());
}

QueryResult OrQuery::eval(const TextQuery &text) const
{
    QueryResult right = rhs.eval(text), left = lhs.eval(text);
    
    std::shared_ptr<std::set<line_no>> ret_lines =
             std::make_shared<std::set<line_no>>(left.begin(), left.end());
    ret_lines->insert(right.begin(), right.end());
    
    return QueryResult(rep(), ret_lines, left.get_file());
    
}

QueryResult NotQuery::eval(const TextQuery &text) const
{
    QueryResult result = query.eval(text);
    
    std::shared_ptr<std::set<line_no>>
          ret_lines = std::make_shared<std::set<line_no>>();
    
    std::set<TextQuery::line_no>::iterator
           begin = result.begin(), end = result.end();
    
    StrBlob::size_type sz = result.get_file().size();
    
    for(std::size_t n = 0; n != sz; ++n)
    {
        if(begin == end || *begin != n)
            ret_lines->insert(n);
        else if (begin != end)
            ++begin;
    }
    
    return QueryResult(rep(), ret_lines, result.get_file());
    
}
