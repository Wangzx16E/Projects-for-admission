//
//  delete.h
//  memo
//
//  Created by ellen on 12/5/16.
//  Copyright © 2016 ellen. All rights reserved.
//

#ifndef delete_h
#define delete_h

namespace cp5
{
    struct Delete
    {
        template<typename T>
        auto operator() (T *p) const
        {   delete p; }
    };
    
}
#endif /* delete_h */
