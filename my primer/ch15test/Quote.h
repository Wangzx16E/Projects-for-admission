//
//  Quote.h
//  ch15test
//
//  Created by ellen on 12/2/16.
//  Copyright © 2016 ellen. All rights reserved.
//

#ifndef Quote_h
#define Quote_h
#include <string>
#include <iostream>



class Quote
{
    friend bool operator !=(const Quote& lhs, const Quote& rhs);
public:
    Quote() { std::cout << "default constructing Quote\n"; }
    Quote(const std::string& b, double p) : bookNo(b), price(p) { std::cout << "Quote : constructor taking 2 params\n"; }
    //copy constructor
    Quote(const Quote& q) : bookNo(q.bookNo), price(q.price)
    { std::cout << "Quote: copy constructing\n"; }
    
    // move constructor
    Quote(Quote&& q) noexcept : bookNo(std::move(q.bookNo)), price(std::move(q.price))
    { std::cout << "Quote: move constructing\n"; }
    
    //copy =
    Quote& operator =(const Quote& rhs)
    {
        if(*this != rhs) { bookNo = rhs.bookNo; price = rhs.price; }
        std::cout << "Quote: copy =() \n";
        return *this;
    }
    
    // move =
    Quote& operator =(Quote&& rhs) noexcept
    {
        if(*this != rhs) { bookNo = std::move(rhs.bookNo); price = std::move(rhs.price); }
        std::cout << "Quote: move =!!!!!! \n";
        return *this;
    }
        
    std::string isbn() const { return bookNo;}
        
    virtual double net_price(size_t n) const { return n * price; }
    virtual ~Quote() = default;
    virtual void debug() const            //(ostream &os)
    {  std::cout << "isbn : price = " << isbn() << " : " << this->price << std::endl;}
    
    
    //clone self
    virtual Quote* clone() const &  { return new Quote(*this);}
    virtual Quote* clone() &&       { return new Quote(std::move(*this)); }
        
private:
        std::string bookNo;
        
protected:
        double price = 0.0;
        
};
bool inline
operator !=(const Quote& lhs, const Quote& rhs)
{
    return lhs.bookNo != rhs.bookNo
           &&
           lhs.price  != rhs.price;
}
        
//non-member
double print_total(std::ostream &os, const Quote &item, size_t n)
        {
            // depending on the type of the object bound to the item parameter
            // calls either Quote::net_price or Bulk_quote::net_price
            double ret = item.net_price(n);
            os << "ISBN: " << item.isbn()   // calls Quote::isbn
               << "# sold: " << n << " total due: " << ret << std::endl;
            return ret;
        }



#endif /* Quote_h */
