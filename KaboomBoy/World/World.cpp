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
    
    
    bool World::advanceTurn()
    {
        bool doUpdate = false;
        
        for (auto& row : mWorldGrid)
            for (auto& elem : row)
            {
                // step forward the element
                int propagateDistance = 0;
                bool update = false;
                
                //TODO: this is a leak! We don't know which are shallow and which are deep copies
                elem = { ((WorldElement *)elem)->advanceTurn(&propagateDistance, &update), WorldElementStore::Ownership::NoOwnership };
                
                //TODO use the propogation distance
                // Probably store a tmp array with prop distances and then
                // handle propogation in another go, so that we dont propogate into un-updated stuff
                
                doUpdate = doUpdate || update;
            }
    
        return doUpdate;
    }
    
}
