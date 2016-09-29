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
        World();
        ~World();
        
        // Not meant to have more than one
        World(const World& other) = delete;
        World& operator=(const World& other) = delete;
        
        void parse(std::istream& reader);
        
        
        
    private:
        std::vector< std::vector< WorldElement * > > mWorldGrid;
        
        
    };
    
}

#endif /* World_h */
