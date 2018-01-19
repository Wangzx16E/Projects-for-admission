//
//  Disc_quote.h
//  ch15test
//
//  Created by ellen on 12/2/16.
//  Copyright © 2016 ellen. All rights reserved.
//

#ifndef Disc_quote_h
#define Disc_quote_h
#include "Quote.h"
#include <iostream>
#include <string>

class Disc_quote : public Quote
{
    friend bool operator !=(const Disc_quote& lhs, const Disc_quote& rhs);
public:
    Disc_quote() { std::cout << "default constructing Disc_quote\n"; };
    Disc_quote(const std::string& b, double p, size_t q, double disc) : Quote(b, p), quantity(q), discount(disc) { std::cout << "Disc_quote : constructor taking 4 parameters.\n"; }
    
    Disc_quote(const Disc_quote& dq): Quote(dq), quantity(dq.quantity), discount(dq.discount)
    { std::cout << "Disc_quote : copy constructor.\n"; }
    
    Disc_quote(Disc_quote&& dq): Quote(std::move(dq)), quantity(std::move(dq.quantity)), discount(std::move(dq.discount)) { std::cout << "Disc_quote : move constructor.\n"; }
    
    Disc_quote& operator =(const Disc_quote& rhs)
    {
        Quote::operator =(rhs);
        this->quantity = rhs.quantity;
        this->discount = rhs.discount;
        std::cout << "Disc_quote : copy =()\n";
        return *this;
    }
    
    Disc_quote& operator =(Disc_quote&& rhs) noexcept
    {
        if (*this != rhs)
        {
            Quote::operator =(std::move(rhs));
            this->quantity = std::move(rhs.quantity);
            this->discount = std::move(rhs.discount);
        }
        std::cout << "Disc_quote : move =()\n";
        return *this;
    }
        
    virtual double net_price(size_t n) const override = 0;
    
    ~Disc_quote()
        { std::cout << "destructing Dis_quote\n"; }
protected:
    size_t quantity = 3;
    double discount = 0.0;
    
};

bool inline
operator !=(const Disc_quote& lhs, const Disc_quote& rhs)
{
     return Quote(lhs) != Quote(rhs)
            &&
            lhs.quantity != rhs.quantity
            &&
            lhs.discount != rhs.discount;
}




#endif /* Disc_quote_h */
