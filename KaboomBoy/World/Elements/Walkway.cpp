//
//  Walkway.cpp
//  KaboomBoy
//
//  Created by J. Schalkwijk on 24/10/2016.
//  Copyright © 2016 JeromeSchalkwijk. All rights reserved.
//

#include "Walkway.h"

#include "Explosion.h"
#include "util.h"

namespace KaboomBoy
{
    WalkWay *WalkWay::update(WorldElement *previous)
    {
        return simpleUpdate<WalkWay>(previous);
    }
    
    WorldElement* WalkWay::advanceTurn(int *propagateDistance, bool *update)
    {
        *propagateDistance = 0;
        *update = 0;
        return nullptr;
    }
    
    WorldElement* WalkWay::propagateFrom(WorldElement *source)
    {
        // If explosion, affected!
        if (dynamic_cast<Explosion *>(source))
            return source;
        
        // else - unaffected
        return this;
    }
    

    
}
