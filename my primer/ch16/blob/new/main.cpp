//
//  main.cpp
//  new
//
//  Created by ellen on 11/17/16.
//  Copyright © 2016 ellen. All rights reserved.
//
// Exercise 16.12:
// Write your own version of the Blob and BlobPtr templates. including the
// various const members that were not shown in the text.
//
// Exercise 16.13:
// Explain which kind of friendship you chose for the equality and relational
// operators for BlobPtr.
//  As shown in the class body.
//

#include <iostream>
#include <vector>
#include <list>
#include <string>
#include "blobptr.h"
#include "Blob.h"

int main()
{
    std::vector<int> v = {1, 2, 3, 4, 5, 6};
    Blob<int> b(v.begin(), v.end());
    
    return 0;
}

