//
//  debugdelete.h
//  memo
//
//  Created by ellen on 12/5/16.
//  Copyright © 2016 ellen. All rights reserved.
//

#ifndef debugdelete_h
#define debugdelete_h
#include <iostream>

class DebugDelete
{
public:
    DebugDelete(std::ostream& s = std::cerr): os(s) {}
    template<typename T>
    void operator ()(T *p) const
    {
        os << "deleting unique_ptr" << std::endl;
        delete p;
    }
    
private:
    std::ostream& os;
};
#endif /* debugdelete_h */
