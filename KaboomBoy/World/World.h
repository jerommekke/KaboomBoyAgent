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
        
        
    private:
        typedef std::vector< WorldElementStore > worldrow_t;
        typedef std::vector< worldrow_t > worldgrid_t;
        
        worldgrid_t mWorldGrid;
        
        
    };
    
}

#endif /* World_h */
