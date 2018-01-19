//
//  main.cpp
//  Screen
//
//  Created by ellen on 11/15/16.
//  Copyright © 2016 ellen. All rights reserved.
//

#include <iostream>
#include "Screen.h"
using std::cout; using std::endl;

int main()
{
    Screen myScreen(5,5,'X');
    myScreen.display(cout);
    cout << endl;
    myScreen.move(4, 0).set('#').display(cout);
    cout << endl;
    myScreen.display(cout);
    cout << endl;
    return 0;
}
