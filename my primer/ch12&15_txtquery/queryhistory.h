//
//  queryhistory.h
//  ch12&15_txtquery
//
//  Created by ellen on 12/4/16.
//  Copyright © 2016 ellen. All rights reserved.
//

#ifndef queryhistory_h
#define queryhistory_h

#include <memory>
#include <vector>
#include "query.h"
using std::shared_ptr; using std::vector; using std::make_shared;

class QueryHistory
{
public:
    Query& operator[](size_t n)
    {
        return *(query_vec[n]);
    }
    
    size_t add_query(const Query&);
    
private:
    vector<shared_ptr<Query>> query_vec;
};

size_t add_query(const Query &query)
{
    shared_ptr<Query> p = make_shared<Query>(query);
    query_vec.push_back(p);
    return query_vec.size() - 1;
}

#endif /* queryhistory_h */
