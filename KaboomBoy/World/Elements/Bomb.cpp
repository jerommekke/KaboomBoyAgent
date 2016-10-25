//
//  Bomb.cpp
//  KaboomBoy
//
//  Created by J. Schalkwijk on 24/10/2016.
//  Copyright © 2016 JeromeSchalkwijk. All rights reserved.
//

#include "Bomb.h"
#include "Agent.h"
#include "Explosion.h"

namespace KaboomBoy {
    
    Bomb *Bomb::update(WorldElement *previous)
    {
        if (previous == nullptr)
            return new Bomb();
        
        if (Agent *prev = dynamic_cast<Agent *>(previous))
        {
            Bomb *newBomb = new Bomb(prev->bombPower());
            delete prev;
            return newBomb;
        }
        
        delete previous;
        return new Bomb();
        
    }
    
    WorldElement *Bomb::advanceTurn(int *propagateDistance, bool *update)
    {
        *update = true;
        
        if (mTurnsBeforeBoom > 0)
        {
            // Create new bomb
            Bomb *copy = new Bomb(*this);

            copy->mTurnsBeforeBoom--;
            *propagateDistance = 0;
            return copy;
        }
        else
        {
            //Boom!
            Explosion *boom = new Explosion();
            
            *propagateDistance = mPower;
            *update = true;
            return boom;
        }
    }
    
    WorldElement *Bomb::propagateFrom(WorldElement *source)
    {
        if (dynamic_cast<Explosion *>(source))
            return source;
        
        return this;
    }
    
}
