//
//  WorldElementStore.cpp
//  KaboomBoy
//
//  Created by J. Schalkwijk on 12/10/2016.
//  Copyright © 2016 JeromeSchalkwijk. All rights reserved.
//

#include "WorldElementStore.h"
#include <utility>

namespace KaboomBoy
{

    WorldElementStore::WorldElementStore() :
        element(nullptr), owner(Ownership::NoOwnership) {}
    
    WorldElementStore::WorldElementStore(WorldElement *elem, Ownership ownership) :
        element(elem), owner(ownership) {}
        
    // Soft copy
    WorldElementStore::WorldElementStore(const WorldElementStore& other) :
        element(other.element), owner(Ownership::NoOwnership) {}
    
    // Move constructor
    WorldElementStore::WorldElementStore(WorldElementStore&& other)
    : WorldElementStore() // initialize via default constructor, C++11 only
    {
        this->swapWith(other);
    }
    
    // Soft copy on operator=, too
    WorldElementStore& WorldElementStore::operator=(WorldElementStore other)
    {
        this->swapWith(other);
        return *this;
    }
        
   
    // Swap
    void WorldElementStore::swapWith(WorldElementStore& other)
    {
        std::swap(element, other.element);
        std::swap(owner, other.owner);
    }
    
    WorldElementStore::~WorldElementStore()
    {
        if (owner == Ownership::Delete) delete element;
    }
    
}
