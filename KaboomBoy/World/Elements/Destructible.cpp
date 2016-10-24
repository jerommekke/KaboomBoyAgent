//
//  Destructible.cpp
//  KaboomBoy
//
//  Created by J. Schalkwijk on 24/10/2016.
//  Copyright © 2016 JeromeSchalkwijk. All rights reserved.
//

#include "Destructible.h"

#include "Explosion.h"
#include "util.h"

namespace KaboomBoy
{
    Destructible *Destructible::update(WorldElement *previous)
    {
        return simpleUpdate<Destructible>(previous);
    }
    
    WorldElement* Destructible::advanceTurn(int *propagateDistance, bool *update)
    {
        *propagateDistance = 0;
        *update = 0;
        return this;
    }
    
    WorldElement* Destructible::propogateFrom(WorldElement *source)
    {
        // If explosion, affected!
        if (dynamic_cast<Explosion *>(source))
            return source;
        
        // else - unaffected
        return this;
    }
    
    
    
}
