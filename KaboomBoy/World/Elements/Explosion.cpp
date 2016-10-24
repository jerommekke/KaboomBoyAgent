//
//  Explosion.cpp
//  KaboomBoy
//
//  Created by J. Schalkwijk on 24/10/2016.
//  Copyright © 2016 JeromeSchalkwijk. All rights reserved.
//

#include "Explosion.h"

#include "util.h"

namespace KaboomBoy
{
    Explosion *Explosion::update(WorldElement *previous)
    {
        return simpleUpdate<Explosion>(previous);
    }
    
    WorldElement* Explosion::advanceTurn(int *propagateDistance, bool *update)
    {
        // Explosion only lives for one turn
        *propagateDistance = 0;
        *update = true;
        return new WalkWay();
    }
    
    WorldElement* Explosion::propogateFrom(WorldElement *source)
    {
        // unaffected
        return this;
    }
    
    
    
}
