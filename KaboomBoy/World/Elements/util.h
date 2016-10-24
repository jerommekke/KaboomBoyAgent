//
//  util.h
//  KaboomBoy
//
//  Created by J. Schalkwijk on 24/10/2016.
//  Copyright © 2016 JeromeSchalkwijk. All rights reserved.
//

#ifndef util_h
#define util_h

#include "WorldElement.h"

namespace KaboomBoy {
    
    template<typename T>
    T *simpleUpdate(WorldElement *previous)
    {
        if (previous == nullptr)
            return new T();
        if (T *prev = dynamic_cast<T *>(previous))
        {
            return prev;
        }
        else
        {
            delete previous;
            return new T();
        }
        
    }
}

#endif /* util_h */
