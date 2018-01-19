//
//  Person.h
//  Created by ellen on 11/15/16.
//

#ifndef Person_h
#define Person_h

#include <iostream>
#include <string>


class Person
{
    friend std::istream &read(std::istream &is, Person &person);
    friend std::ostream &print(std::ostream &os, Person &person);
public:
    //constructor
    Person() = default;
    Person(const std::string sname, const std::string saddr): name(sname), address(saddr) { }
    explicit Person(std::istream &is) { read(is,*this);}
    
    std::string  getName()  const { return name;}  //string get_name() ???
    std::string  getAddress() const{ return address;}

private:
    std::string name;
    std::string address;
};

//nonmember functions
std::istream &read(std::istream &is, Person &person)
{
    is >> person.name >> person.address;
    return is;
}

std::ostream &print(std::ostream &os, const Person &person)
{
    os << person.name << " " << person.address;
    return os;
}

#endif /* Person_h */
