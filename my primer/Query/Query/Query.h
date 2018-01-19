//
//  Query.h
//  Query
//
//  Created by ellen on 11/28/16.
//  Copyright © 2016 ellen. All rights reserved.
//

#ifndef Query_h
#define Query_h
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <memory>
using namespace std;
class QueryResult;
class TextQuery{
public:
    using line_no = vector<string>::size_type;
    TextQuery(ifstream&);
    QueryResult query(const string&) const;
    
private:
    shared_ptr<vector<string>> file;
    map<string, shard_ptr<set<line_no>>> wm;
};

class QueryResult{
private:
    string sought;
    shared_ptr<set<line_no>> lines;
    shared_ptr<vector<string>> file;
};

#endif /* Query_h */
