//
//  Sales_data.h
//  Sales_data
//
//  Created by ellen on 11/15/16.
//  Copyright © 2016 ellen. All rights reserved.
//

#ifndef Sales_data_h
#define Sales_data_h

#include <string>
#include <iostream>

class Sales_data;
std::istream &read(std::istream&, Sales_data&);

class Sales_data {
    friend std::istream &read(std::istream &is, Sales_data &item);
    friend std::ostream &print(std::ostream &os, const Sales_data &item);
    friend Sales_data add(const Sales_data &lhs, const Sales_data &rhs);

public:
    Sales_data(const std::string &s, unsigned n, double p):bookNo(s), units_sold(n), revenue(n*p) { }
    
    Sales_data() : Sales_data("", 0, 0.0f) { }
    
    Sales_data(const std::string &s) : Sales_data(s, 0, 0.0f) {}
    
    Sales_data(std::istream &is);
    
    std::string isbn() const { return bookNo; }
    Sales_data& combine(const Sales_data&);

private:
    inline double avg_price() const;
    
private:
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

inline
double Sales_data::avg_price() const
{
    return units_sold ? revenue/units_sold : 0 ;
}

// member functions
Sales_data& Sales_data::combine(const Sales_data& rhs)
{
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

//friend functions
std::istream &read(std::istream &is, Sales_data &item)
{
    double price = 0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = price * item.units_sold;
    return is;
}

std::ostream &print(std::ostream &os, const Sales_data &item)
{
    os << item.isbn() << " " << item.units_sold << " " << item.revenue;
    return os;
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs)
{
    Sales_data sum = lhs;
    sum.combine(rhs);
    return sum;
}


#endif /* Sales_data_h */
