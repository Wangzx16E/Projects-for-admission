//
//  StrBlob.h
//
//
//  Created by ellen on 12/3/16.
//  Copyright © 2016 ellen. All rights reserved.
//

#ifndef StrBlob_h
#define StrBlob_h


#include <string>
#include <vector>
#include <initializer_list>
#include <memory>
#include <stdexcept>
// forward declaraiton needed for friend declaration in strblob
class StrBlobPtr;

class StrBlob
{
    friend class StrBlobPtr;
public:
    typedef std::vector<std::string>::size_type size_type;
    
    //constructors
    StrBlob() : data(std::make_shared<std::vector<std::string>>()) {};
    StrBlob(std::initializer_list<std::string> il);
    
    //size operations
    size_type size() const { return data->size();}
    bool empty() const { return data->empty();}
    
    //add and remove elements
    void push_back(const std::string &t) { data->push_back(t);}
    void pop_back();
    
    //interface to StrBlobPtr
    StrBlobPtr begin();
    StrBlobPtr end();
    
private:
    std::shared_ptr<std::vector<std::string>> data;
    void check(size_type i, const std::string &msg) const; // throw msg if data[i] invalid
};
//constructor
inline StrBlob::StrBlob(std::initializer_list<std::string> il): data(std::make_shared<std::vector<std::string>>(il)) {}

//StrBlobPtr throws an exception on attempts to access a nonexistent elmetn
class StrBlobPtr
{
    friend bool eq(const StrBlobPtr&, const StrBlobPtr&);
public:
    StrBlobPtr(): curr(0) {}
    StrBlobPtr(StrBlob &a, size_t sz = 0): wptr(a.data), curr(sz) {}
    //newly overloaded
    StrBlobPtr(const StrBlob &a, const size_t sz = 0): wptr(a.data), curr(sz) {}
    
    std::string& deref() const;
    StrBlobPtr& incr();    //prefix version
    StrBlobPtr& decr();    //prefix version
    private:
    //check returns a shared_ptr to the vector if the check succeeds
    std::shared_ptr<std::vector<std::string>> check(std::size_t, const std::string&) const;
    //store a weak_ptr, which means the underlying vector might be destroyed
    std::weak_ptr<std::vector<std::string>> wptr;
    std::size_t curr;
    
};
inline
std::shared_ptr<std::vector<std::string>>
StrBlobPtr::check(std::size_t i, const std::string &msg) const
{
    auto ret = wptr.lock();   // is the vector still around?
    if (!ret)
        throw std::runtime_error("unbound StrBlobPtr");
    
    if (i >= ret->size())
        throw std::out_of_range(msg);
    return ret; // otherwise, return a shared_ptr to the vector
}

inline std::string& StrBlobPtr::deref() const
{
    auto p = check(curr, "dereference past end");
    return (*p)[curr];
}

inline StrBlobPtr& StrBlobPtr::incr()
{
    check(curr, "increment past end of StrBlobPtr");
    ++curr;
    return *this;
}
inline StrBlobPtr& StrBlobPtr::decr()
{
    --curr;
    check(-1, "decrement past begin of StrBlobPtr");
    return *this;
}
inline StrBlobPtr StrBlob::begin()
{
    return StrBlobPtr(*this);
}
inline StrBlobPtr StrBlob::end()
{
    auto ret = StrBlobPtr(*this, data->size());
    return ret;
}
inline bool eq(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
    auto l = lhs.wptr.lock(), r = rhs.wptr.lock();
    if (l == r)   return (!r || rhs.curr == rhs.curr); //same vector? - both null ? / same element?
    else return false;
}
inline bool neq(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
    return !eq(lhs,rhs);
}

#endif /* StrBlob_h */
