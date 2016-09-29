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
        World(std::istream reader);
        
    private:
        std::vector< std::vector< WorldElement > > mWorldGrid;
        
        
    };
    
}

#endif /* World_h */
