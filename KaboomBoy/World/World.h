//
//  World.hpp
//  KaboomBoy
//
//  Created by J. Schalkwijk on 28/09/2016.
//  Copyright © 2016 JeromeSchalkwijk. All rights reserved.
//

#ifndef World_h
#define World_h

#include <iostream>
#include <vector>

#include "WorldELement.h"

namespace KaboomBoy
{
    class World
    {
    public:
        /**
         * World parsing is meant to be an efficient step, i.e. 
         * if the world changes little and is parsed multiple times, very little 
         * actual allocations/deallocations will be performed
         */
        void parse(std::istream& reader);
        
        
    private:
        class WorldElementStore
        {
        public:
            enum Ownership {
                Delete,
                NoOwnership
            };
            
            WorldElementStore() :
                element(nullptr), owner(Ownership::NoOwnership) {}
            WorldElementStore(WorldElement *elem, Ownership ownership) :
                element(elem), owner(ownership) {}
            
            // Soft copy
            WorldElementStore(const WorldElementStore& other) :
                element(other.element), owner(Ownership::NoOwnership) {}
            
            // Soft copy on operator=, too
            WorldElementStore& operator=(WorldElementStore other)
            {
                this->swapWith(other);
                return *this;
            }
            
            // Move constructor
            WorldElementStore(WorldElementStore&& other)
                    : WorldElementStore() // initialize via default constructor, C++11 only
            {
                this->swapWith(other);
            }

            
            // Swap
            void swapWith(WorldElementStore& other)
            {
                std::swap(element, other.element);
                std::swap(owner, other.owner);
            }
            
            ~WorldElementStore() { if (owner == Ownership::Delete) delete element; }
            
            // Allow the world element to be directly castable to a WorldElement
            operator WorldElement*() { return element; }
            
        private:
            WorldElement *element;
            Ownership owner;
        };
        
        typedef std::vector< WorldElementStore > worldrow_t;
        typedef std::vector< worldrow_t > worldgrid_t;
        
        worldgrid_t mWorldGrid;
        
        
    };
    
}

#endif /* World_h */
