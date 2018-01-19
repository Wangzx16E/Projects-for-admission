//
//  main.cpp
//  StrBlob
// page 404 definition
// StrBlob: shared_ptr<vector<string>> data
// StrBlobPtr: weak_ptr<vector<string>> wptr; size_t curr;

#include <iostream>
#include <fstream>
#include "StrBlob.h"
#include <string>
using namespace std;

int main()
{
    ifstream ifs("/Users/user/Desktop/my primer/StrBlob/text.txt");
    StrBlob blob;
    for(string str; getline(ifs, str); )
        blob.push_back(str);
    for(StrBlobPtr pbeg(blob.begin()), pend(blob.end()); pbeg != pend; pbeg.incr())
        cout << pbeg.deref() << endl;
}
