//  main.cpp
//  Sales_data
//
/*
std::string bookNo;
unsigned units_sold = 0;
double revenue = 0.0;*/

#include <iostream>
#include <fstream>
#include <numeric>
#include <algorithm>
#include <vector>
#include "Sales_data.h"

using namespace std;

bool compareIsbn(const Sales_data &sd1, const Sales_data &sd2)
{  return sd1.isbn().size() < sd2.isbn().size() ;}

int main(int argc, char **argv)
{
    
    ifstream input("/Users/user/Desktop/my primer/Sales_data/Salesdata.txt");
    vector<Sales_data> v;
    istream_iterator<Sales_data> in_iter(input), eof;
    while(in_iter != eof)
        v.push_back(*in_iter++);
    
    sort(v.begin(),v.end(), compareIsbn);
    for (auto beg = v.cbegin(), end = beg; beg != v.cend(); beg = end)
    {
        end = find_if(beg, v.cend(), [beg](const Sales_data &item) {return item.isbn() != beg ->isbn(); } );
        cout << accumulate(beg, end, beg->isbn()) << endl;
    }
    
    
    return 0;
}
