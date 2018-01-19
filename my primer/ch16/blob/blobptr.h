//
//  blobptr.h
//  new
//
//  Created by ellen on 12/5/16.
//  Copyright © 2016 ellen. All rights reserved.
//

#ifndef blobptr_h
#define blobptr_h
#include "Blob.h"
#include <memory>
#include <vector>

template <typename> class BlobPtr;

template <typename T>
bool operator ==(const BlobPtr<T>& lhs, const BlobPtr<T>& rhs);
template <typename T>
bool operator <(const BlobPtr<T>& lhs, const BlobPtr<T>& rhs);

template <typename T> class BlobPtr
{
    friend bool operator ==<T>(const BlobPtr<T>& lhs, const BlobPtr<T>& rhs);
    
    friend bool operator < <T>(const BlobPtr<T>& lhs, const BlobPtr<T>& rhs);
    
public:
    BlobPtr() : curr(0) {}
    BlobPtr(Blob<T>& a, std::size_t sz = 0) : wptr(a.data), curr(sz) {}
    
    T& operator*() const
    {
        auto p = check(curr, "dereference past end");
        return (*p)[curr];
    }
    
    //prefix
    BlobPtr& operator++();
    BlobPtr& operator--();
    
    BlobPtr& operator++(int);
    BlobPtr& operator--(int);
    
private:
    std::shared_ptr<std::vector<T>> check(std::size_t, const std::string&) const;
    
    std::weak_ptr<std::vector<T>> wptr;
    std::size_t curr;
};

//prefix
template<typename T>
BlobPtr<T>& BlobPtr<T>:: operator++()
{
    check(curr, "increment past end of StrBlob");
    ++curr;
    return *this;
}
template<typename T>
BlobPtr<T>& BlobPtr<T>::operator--()
{
    --curr;
    check(curr,"decrement past begin of BlobPtr");
    return *this;
}

//postfix
template<typename T>
BlobPtr<T>& BlobPtr<T>::operator++(int)
{
    BlobPtr ret = *this;
    --*this;
}
template<typename T>
BlobPtr<T>& BlobPtr<T>::operator--(int)
{
    BlobPtr ret = *this;
    --*this;
    return ret;
}

template<typename T>
bool operator ==(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs)
{
    if (lhs.wptr.lock() != rhs.wptr.lock())
        throw std::runtime_error("ptrs to different Blobs!");
    return lhs.i == rhs.i;
}

template<typename T>
bool operator <(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs)
{
    if(lhs.wptr.lock() != rhs.wptr.lock())
        throw std::runtime_error("ptrs to different Blobs!");
    return lhs.i < rhs.i;
}
#endif /* blobptr_h */
