//
//  Bulk_quote.h
//  ch15test
//
//  Created by ellen on 12/2/16.
//  Copyright © 2016 ellen. All rights reserved.
//

#ifndef Bulk_quote_h
#define Bulk_quote_h

#include "Disc_quote.h"
#include <iostream>
#include <string>
// changed the below to the inherited constructor for ex15.27.
// rules:  1. only inherit from the direct base class.
//         2. default, copy and move constructors can not inherit.
//         3. any data members of its own are default initialized.
//         4. the rest details are in the section section 15.7.4.
/*
 Bulk_quote(const std::string& b, double p, std::size_t q, double disc) :
 Disc_quote(b, p, q, disc) { std::cout << "Bulk_quote : constructor taking 4 parameters\n"; }
 */

class Bulk_quote: public Disc_quote
{
public:
    Bulk_quote() { std::cout << "default constructing Bulk_quote\n"; };
 
    using Disc_quote::Disc_quote;
    
    //copy constructor
    Bulk_quote(const Bulk_quote& bq): Disc_quote(bq) { std::cout << "Bulk_quote : copy constructor\n"; }
    
    //move constructor
    Bulk_quote(Bulk_quote&& bq) : Disc_quote(std::move(bq))
    { std::cout << "Bulk_quote : move constructor\n"; }
    
    //copy =()
    Bulk_quote& operator =(const Bulk_quote& rhs)
    {
        Disc_quote::operator =(rhs);
        std::cout << "Bulk_quote : copy =()\n";
        return *this;
    }
    
    //move =()
    Bulk_quote& operator =(Bulk_quote&& rhs)
    {
        Disc_quote::operator =(std::move(rhs));
        std::cout << "Bulk_quote : move =()\n";
        return *this;
    }
        
    double net_price(size_t n) const override { return n * price * ( n >= quantity ? 1 - discount : 1);
    
    ~Bulk_quote() override
    {  std::cout << "destructing Bulk_quote\n"; }

        
};
#endif /* Bulk_quote_h */
