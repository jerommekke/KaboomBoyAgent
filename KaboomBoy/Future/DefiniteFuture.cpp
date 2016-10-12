//
//  DefiniteFuture.cpp
//  KaboomBoy
//
//  Created by J. Schalkwijk on 12/10/2016.
//  Copyright © 2016 JeromeSchalkwijk. All rights reserved.
//

#include "DefiniteFuture.h"

namespace KaboomBoy
{
    DefiniteFuture::DefiniteFuture() :
        mFutureDepth(0)
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
        return mFutureDepth;
    }
    
    void DefiniteFuture::calculateFutures(const World& currentWorld)
    {
        // Clear futures and restart
        mFutures.clear();
        
        // Start calculating futures
        bool nextTurnHasDefiniteFuture = true;
        
        // FIrst make a copy of the world
        
        
        
        
    }
    
    
    
}
