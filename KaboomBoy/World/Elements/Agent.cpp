//
//  Agent.cpp
//  KaboomBoy
//
//  Created by J. Schalkwijk on 24/10/2016.
//  Copyright © 2016 JeromeSchalkwijk. All rights reserved.
//

#include "Agent.h"

#include "Explosion.h"

namespace KaboomBoy {
    
    Agent *Agent::update(WorldElement *previous, char asciiChar)
    {
        // Do powerups here if previous had a powerup
        if (previous == nullptr)
            return new Agent(asciiChar);
        if (Agent *prev = dynamic_cast<Agent *>(previous))
        {
            if (prev->mIdentity == asciiChar) return prev;
        }
        
        delete previous;
        return new Agent(asciiChar);
        
    }
    
    
    WorldElement* Agent::advanceTurn(int *propagateDistance, bool *update)
    {
        // We have no idea where the agent is next turn, so let's turn him into a walkway
        *propagateDistance = 0;
        *update = true;
        return new WalkWay();
    }
    
    WorldElement* Agent::propogateFrom(WorldElement *source)
    {
        if (dynamic_cast<Explosion *>(source))
            return source;
        
        // unaffected
        return this;
    }

    
    

}
