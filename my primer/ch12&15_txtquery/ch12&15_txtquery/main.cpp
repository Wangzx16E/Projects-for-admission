//
//  main.cpp
//  ch12&15_txtquery
//
//  Created by ellen on 12/2/16.
//  Copyright © 2016 ellen. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <fstream>

#include "query.h"
#include "textquery.h"

int main()
{
    std::ifstream file("/Users/user/Desktop/my primer/ch12&15_txtquery/test.txt");
    
    TextQuery tQuery(file);
    Query q = Query("fieryzzz") | Query("wind");
    std::cout << q.eval(tQuery);
    return 0;
}
