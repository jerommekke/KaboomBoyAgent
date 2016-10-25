//
//  WorldElementStore.hpp
//  KaboomBoy
//
//  Created by J. Schalkwijk on 12/10/2016.
//  Copyright © 2016 JeromeSchalkwijk. All rights reserved.
//

#ifndef WorldElementStore_h
#define WorldElementStore_h

#include "WorldElement.h"

namespace KaboomBoy
{
    class WorldElementStore
    {
    public:
        enum Ownership {
            Delete,
            NoOwnership
        };
        
        WorldElementStore();
        ~WorldElementStore();
        
        WorldElementStore(WorldElement *elem, Ownership ownership);
        
        // Soft copy
        WorldElementStore(const WorldElementStore& other);
        
        // Soft copy on operator=, too
        WorldElementStore& operator=(WorldElementStore other);
        
        // Move constructor
        WorldElementStore(WorldElementStore&& other);
        
        // Swap
        void swapWith(WorldElementStore& other);
        
        // Allow the world element to be directly castable to a WorldElement
        operator WorldElement*() { return element; }
        WorldElement *operator->() { return element; }
        
    private:
        WorldElement *element;
        Ownership owner;
    };
    
}



#endif /* WorldElementStore_h */
