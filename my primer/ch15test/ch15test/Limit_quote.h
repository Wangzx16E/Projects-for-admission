//
//  Limit_quote.h
//  ch15test
//
//  Created by ellen on 12/2/16.
//  Copyright © 2016 ellen. All rights reserved.
//


#ifndef Limit_quote_h
#define Limit_quote_h

#include "Disc_quote.h"
#include <iostream>
#include <string>

class Limit_quote : public Disc_quote {
public:
    Limit_quote() = default;
    Limit_quote(const std::string& b, double p, std::size_t max, double disc): Disc_quote(b, p, max, disc)  {}
    
    double net_price(std::size_t n) const override
    { return n * price * (n < quantity ? 1 - discount : 1 ); }
    
};

#endif /* Limit_quote_h */
