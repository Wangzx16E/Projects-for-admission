//
//  main.cpp
//  ch15test
//
//  Created by ellen on 11/30/16.
//  Copyright © 2016 ellen. All rights reserved.
//

#include <iostream>
#include <string>

#include "Quote.h"
#include "Bulk_quote.h"
#include "Limit_quote.h"
#include "Disc_quote.h"


int main()
{
    Bulk_quote bq1;
    Bulk_quote bq2("ss", 2.05, 12, 0.3);
    bq2 = std::move(bq2);
    
    return 0;
}
