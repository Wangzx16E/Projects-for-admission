//
//  memon.h
//  
//
//  Created by ellen on 11/17/16.
//
//

#ifndef memon_h
#define memon_h

#include <string>

class Account {
public:
    void calculate() { amount += amount * interestRate; }
    static double rate() { return interestRate; }
    static void rate(double newRate) { interestRate = newRate; }
    
private:
    std::string owner;
    double amount;
    static double interestRate;
    static constexpr double todayRate = 42.42;
    static double initRate() { return todayRate; }
};

double Account::interestRate = initRate( );

#endif /* memon_h */
