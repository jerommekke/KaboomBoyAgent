//
//  World.cpp
//  KaboomBoy
//
//  Created by J. Schalkwijk on 28/09/2016.
//  Copyright © 2016 JeromeSchalkwijk. All rights reserved.
//

#include "World.h"

#include <string>

namespace KaboomBoy
{
    World::World()
    {
        
    }
    
    World::~World()
    {
        for (const auto& x : mWorldGrid )
        {
            for (const WorldElement *elem : x)
                delete elem;
        }
    }
    
    void World::parse(std::istream& reader)
    {
        
        std::string line;
        for( unsigned int i = 0; std::getline(reader, line); ++i )
        {
            // resize if required
            if (i >= mWorldGrid.size()) mWorldGrid.push_back( std::vector<WorldElement *>() );
            
            for (auto j = 0; j < line.size(); ++j)
            {
                // resize if required
                if (j >= mWorldGrid[i].size()) mWorldGrid[i].push_back(nullptr);
                
                mWorldGrid[i][j] = WorldElement::create(line[j], mWorldGrid[i][j]);
            }
        }
    }
    
    
    
}
