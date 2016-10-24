//
//  DefiniteFuture.cpp
//  KaboomBoy
//
//  Created by J. Schalkwijk on 12/10/2016.
//  Copyright © 2016 JeromeSchalkwijk. All rights reserved.
//

#include "DefiniteFuture.h"

#include "World.h"

namespace KaboomBoy
{
    DefiniteFuture::DefiniteFuture()
    {
    }
    
    DefiniteFuture::~DefiniteFuture()
    {
    }
    
    IFuture::futures_t DefiniteFuture::worldInTurns(int numberOfTurns)
    {
        return futures_t();
    }
    
    int DefiniteFuture::futureDepth()
    {
        return (int)mFutures.size();
    }
    
    void DefiniteFuture::calculateFutures(const World& currentWorld)
    {
        // Clear futures and restart
        mFutures.clear();
        
        // Calculate futures while the future yields actual information
        for ( World nextTurn = currentWorld; nextTurn.advanceTurn();  )
        {
            mFutures.push_back( futures_t(1, nextTurn) );
        }
        
    }
    
    
    
    
}
