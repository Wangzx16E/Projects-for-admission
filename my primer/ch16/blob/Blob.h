//
//  Blob.h
//  new
//
//  Created by ellen on 12/5/16.
//  Copyright © 2016 ellen. All rights reserved.
//

#ifndef Blob_h
#define Blob_h
#include <memory>
#include <vector>

template<typename T> class Blob
{
public:
    Blob();
    Blob(std::initializer_list<T> il);
    
    template<typename It>
    Blob(It b, It e);
    
    size_t size() const { return data->size();}
    bool empty() const { return data->empty();}
    
    void push_back(const T& t) { data->push_back(t);}
    void push_back(T&& t) { data->push_back(std::move(t)); }
    void pop_back();
    
    T& back();
    T& operator[](size_t i) ;
    
    const T& back() const;
    const T& operator [](size_t i) const;

private:
    std::shared_ptr<std::vector<T>> data;
    void check(size_t i, const std::string &msg) const;
};

//constructors
template<typename T>
Blob<T>::Blob(): data(std::shared_ptr<std::vector<T>>()) {}

template<typename T>
Blob<T>::Blob(std::initializer_list<T> il): data(std::shared_ptr<std::vector<T>>(il)) {}

template<typename T>
template<typename It>
Blob<T>::Blob(It b, It e): data(std::make_shared<std::vector<T>>(b,e)) {}

template<typename T>
void Blob<T>::check(size_t i, const std::string &msg) const
{
    if(i >= data->size()) throw std::out_of_range(msg);
}

template<typename T>
T& Blob<T>::back()
{
    check(0, "back on empty Blob");
    return data->back();
}

template<typename T>
const T& Blob<T>::back() const
{
    check(0, "back on empty Blob");
    return data->back();
}

template<typename T>
T& Blob<T>::operator[](size_t i)
{
    check(i, "subscript out of range");
    return (*data)[i];
}

template<typename T>
const T& Blob<T>::operator [](size_t i) const
{
    check(i, "subscript out of range");
    return (*data)[i];
}

template<typename T>
void Blob<T>::pop_back()
{
    check(0, "pop_back on empty Blob");
    data->pop_back();
}
#endif /* Blob_h */
