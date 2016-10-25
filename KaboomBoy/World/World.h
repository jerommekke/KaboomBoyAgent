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

#include "WorldElementStore.h"

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
        
        
        /**
         * Advance the world one step. Only steps forward that what it believes is definitely the future
         * @return returns whether the update changed something
         */
        bool advanceTurn();
        
    private:
        typedef std::vector< WorldElementStore > worldrow_t;
        typedef std::vector< worldrow_t > worldgrid_t;
        
        worldgrid_t mWorldGrid;
        
        std::vector< std::vector< int > > mPropagateDist; 
        
    };
    
}

#endif /* World_h */
