//
//  main.cpp
//  ex8personinfo
//
//  Created by ellen on 11/18/16.
//  Copyright © 2016 ellen. All rights reserved.
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>

using std::istream; using std::istringstream; using std::ifstream;
using std::string; using std::vector; using std::cin;
using std::cout; using std::endl;
using std::istringstream; using std::ostringstream;  using std::cerr;

struct PersonInfo {
    string name;
    vector<string> phones;
};

bool valid(string);
string format(string);

int main()
{
    
    ifstream ifs("/Users/user/Desktop/my primer/memo/test2.txt");
    
    if(!ifs)
    {
        cerr << "no phone numbers?" << endl;
        return -1;
    }
    string line, word;
    vector<PersonInfo> people;
    istringstream record;
    
    while (getline(ifs, line))
    {
        PersonInfo info;
        record.clear();
        record.str(line);
        record >> info.name;
        while (record >> word)
            info.phones.push_back(word);
        people.push_back(info);
    }
    
    for(const auto &p : people)
    {
        ostringstream badNums, formatted;
        for(const auto &nums : p.phones)
        {
            if(!valid(nums))
                badNums << " " << nums;
            else
                formatted << " " << format(nums);
        }
        if(badNums.str().empty())
            cout << p.name << " " << formatted.str() << endl;
        else
            cerr << "error: " << p.name << badNums.str() << endl;
        
    }
    return 0;
}
bool valid(string num){
    return (num.size()==5);
}
string format(string num){
    return num += 's';
}
