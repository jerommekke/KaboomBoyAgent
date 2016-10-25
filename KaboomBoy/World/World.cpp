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
        
        if (mPropagateDist.size() != mWorldGrid.size() ||
            mPropagateDist[0].size() != mWorldGrid[0].size() )
        {
            mPropagateDist.resize(mWorldGrid.size());
            
            auto iter = mWorldGrid.begin();
            for (auto& row : mPropagateDist)
            {
                row.resize(iter->size());
                iter++;
            }
        }
        
        auto pRowIter = mPropagateDist.begin();
        for (auto& row : mWorldGrid) {
            
            auto pColIter = pRowIter->begin();
            pRowIter++;
            
            for (auto& elem : row)
            {
                // step forward the element
                int propagateDistance = 0;
                bool update = false;
                
                WorldElement *newElem = elem->advanceTurn(&propagateDistance, &update);
                
                if (newElem != (WorldElement *)elem)
                    elem = { newElem, WorldElementStore::Ownership::Delete };
                
                doUpdate = doUpdate || update;
                pColIter++;
            }
        }
    
        //TODO use the propogation distance
        // Probably store a tmp array with prop distances and then
        // handle propogation in another go, so that we dont propagate into un-updated stuff
        for (int i = 0; i < mPropagateDist.size(); ++i)
        {
            for (int j = 0; j < mPropagateDist[i].size(); ++j)
            {
                const int dist = mPropagateDist[i][j];
                if (dist > 0)
                {
                    // Propagate in all distances
                    for (int ii = i+1; ii < i + dist; ++ii)
                    {
                        // propagate
                        WorldElement *newElem = mWorldGrid[ii][j]->propagateFrom(mWorldGrid[i][j]);
                        
                        // Consider memory, this is a bit scary
                        if (newElem != (WorldElement *)mWorldGrid[ii][j] && newElem != (WorldElement *)mWorldGrid[i][j])
                            mWorldGrid[i][j] = { newElem, WorldElementStore::Ownership::Delete };
                    }
                }
            }
        }
        
        
        return doUpdate;
    }
    
}
