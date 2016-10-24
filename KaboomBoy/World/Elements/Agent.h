//
//  Agent.hpp
//  KaboomBoy
//
//  Created by J. Schalkwijk on 24/10/2016.
//  Copyright © 2016 JeromeSchalkwijk. All rights reserved.
//

#ifndef Agent_hpp
#define Agent_hpp

#include "Walkway.h"

namespace KaboomBoy
{
    
    class Agent : public WalkWay
    {
    public:
        Agent(char identity) : mIdentity(identity) {}
        
        virtual bool occupied()    { return true; }
        virtual bool destroyable() { return true; }
        virtual bool agent()       { return true; }
        
        int bombPower() const { return 3; }
        static Agent *update(WorldElement *previous, char asciiChar);
        
        virtual WorldElement* advanceTurn(int *propagateDistance, bool *update);
        virtual WorldElement* propogateFrom(WorldElement *source);
        
    private:
        char mIdentity;
        
    };
    
}


#endif /* Agent_hpp */
