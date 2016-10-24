//
//  DefiniteFuture.hpp
//  KaboomBoy
//
//  Created by J. Schalkwijk on 12/10/2016.
//  Copyright © 2016 JeromeSchalkwijk. All rights reserved.
//

#ifndef DefiniteFuture_h
#define DefiniteFuture_h

#include "IFuture.h"

namespace KaboomBoy
{
    class DefiniteFuture : public IFuture
    {
    public:
        DefiniteFuture();
        ~DefiniteFuture();
        
        // Return representations of the world a certain number of turns into the future
        IFuture::futures_t worldInTurns(int numberOfTurns);
        
        // Ask for the number of steps into the future we have a representation of
        int futureDepth();
        
        void calculateFutures(const World& currentWorld);
        
    private:
        std::list< futures_t > mFutures;
        
    };
}

#endif /* DefiniteFuture_h */
