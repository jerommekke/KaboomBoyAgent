//
//  Indestructible.cpp
//  KaboomBoy
//
//  Created by J. Schalkwijk on 24/10/2016.
//  Copyright © 2016 JeromeSchalkwijk. All rights reserved.
//

#include "Indestructible.h"

#include "util.h"

namespace KaboomBoy
{
    
    Indestructible *Indestructible::update(WorldElement *previous)
    {
        return simpleUpdate<Indestructible>(previous);
    }
    
    WorldElement* Indestructible::advanceTurn(int *propagateDistance, bool *update)
    {
        *propagateDistance = 0;
        *update = 0;
        return this;
    }
    
    WorldElement* Indestructible::propagateFrom(WorldElement *source)
    {
        // unaffected
        return this;
    }

}
