//
//  basket.h
//  ch15test
//
//  Created by ellen on 12/2/16.
//  Copyright © 2016 ellen. All rights reserved.
//

#ifndef basket_h
#define basket_h

#include "Quote.h"
#include <set>
#include <memory>

class Basket
{
public:
    void add_item(const Quote& sale)
    {  items.insert(std::shared_ptr<Quote> (sale.clone())); }
    void add_item(Quote&& sale)
    {  items.insert(std::shared_ptr<Quote> (std::move(sale.clone())); }
    
private:
    static bool compare(const std::shared_ptr<Quote>& lhs, const std::shared_ptr<Quote>& rhs)
    { return lhs->isbn() < rhs->isbn(); }
    
    std::multiset<shard_ptr<Quote>, decltype(compare)*> items{compare };
};

#endif /* basket_h */
