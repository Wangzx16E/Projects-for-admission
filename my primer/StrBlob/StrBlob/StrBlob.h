//
//  StrBlob.h
//  StrBlob
//
//  Created by ellen on 11/27/16.
//  Copyright © 2016 ellen. All rights reserved.
//

#ifndef StrBlob_h
#define StrBlob_h

#include <string>
#include <vector>
#include <initializer_list>
#include <memory>
#include <exception>
using namespace std;

class StrBlobPtr;
class ConstStrBlobPtr;

class StrBlob{
public:
    typedef vector<string>::size_type size_type;
    friend class StrBlobPtr;
    friend class ConstStrBlobPtr;
    
    StrBlobPtr begin();
    StrBlobPtr end();
    
    StrBlob() : data(make_shared<vector<string>>()) {};
    StrBlob(initializer_list<string> il) : data(make_shared<vector<string>>(il)) {}
    
    size_type size() const { return data->size();}
    bool empty() const { return data->empty(); }
    
    void push_back(const string &t) { data->push_back(t); }
    void pop_back(){
        check(0, "pop_back on empty StrBlob");
        data->pop_back();
    }
    string& front(){
        check(0, "front on empty StrBlob");
        return data->front();
    }
    string& back(){
        check(0, "back on empty StrBlob");
        return data->back();
    }
    const string& front() const {
        check(0, "front on empty StrBlob");
        return data->front();
    }
    const string& back() const {
        check(0, "back on empty StrBlob");
        return data->back();
    }

private:
    shared_ptr<vector<string>> data;
    void check(size_type i, const string &msg) const{
        if(i >= data->size()) throw out_of_range(msg);
    }
};

class StrBlobPtr{
public:
    StrBlobPtr(): curr(0) {};
    StrBlobPtr(StrBlob &a, size_t sz = 0): wptr(a.data), curr(sz) {}
    
    bool operator!=(const StrBlobPtr& p) { return  p.curr != curr; }
    string& deref() const {
        auto p = check(curr, "dereference past end");
        return (*p)[curr];
    }
    StrBlobPtr& incr() {
        check(curr, "increment past end of StrBlobPtr");
        ++curr;
        return *this;
    }
private:
    shared_ptr<vector<string>> check(size_t i, const string &msg) const {
        auto ret = wptr.lock();
        if (!ret) throw runtime_error("unbound StrBlobPtr");
        if (i >= ret -> size()) throw out_of_range(msg);
        return ret;
    }
    weak_ptr<vector<string>> wptr;
    size_t curr;
};

class ConstStrBlobPtr{
public:
    ConstStrBlobPtr(): curr(0) {};
    ConstStrBlobPtr(const StrBlob &a, size_t sz = 0): wptr(a.data), curr(sz) {}
    
    bool operator!=(ConstStrBlobPtr& p) { return  p.curr != curr; }
    const string& deref() const {
        auto p = check(curr, "dereference past end");
        return (*p)[curr];
    }
    ConstStrBlobPtr& incr() {
        check(curr, "increment past end of StrBlobPtr");
        ++curr;
        return *this;
    }
private:
    shared_ptr<vector<string>> check(size_t i, const string &msg) const {
        auto ret = wptr.lock();
        if (!ret) throw runtime_error("unbound StrBlobPtr");
        if (i >= ret -> size()) throw out_of_range(msg);
        return ret;
    }
    weak_ptr<vector<string>> wptr;
    size_t curr;
};


StrBlobPtr StrBlob::begin()
{
    return StrBlobPtr(*this);
}
StrBlobPtr StrBlob::end()
{
    return StrBlobPtr(*this, data->size());
}
#endif /* StrBlob_h */
