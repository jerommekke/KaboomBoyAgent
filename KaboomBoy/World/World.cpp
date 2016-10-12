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

    void World::parse(std::istream& reader)
    {
        
        std::string line;
        for( unsigned int i = 0; std::getline(reader, line); ++i )
        {
            // resize if required
            if (i >= mWorldGrid.size()) mWorldGrid.push_back( worldrow_t() );
            
            for (auto j = 0; j < line.size(); ++j)
            {
                // resize if required
                if (j >= mWorldGrid[i].size()) mWorldGrid[i].push_back( { nullptr, WorldElementStore::NoOwnership } );
                
                mWorldGrid[i][j] = { WorldElement::create(line[j], mWorldGrid[i][j]), WorldElementStore::Delete };
            }
        }
    }
    
    
    
    
}
