//
//  Destructible.hpp
//  KaboomBoy
//
//  Created by J. Schalkwijk on 24/10/2016.
//  Copyright © 2016 JeromeSchalkwijk. All rights reserved.
//

#ifndef Destructible_hpp
#define Destructible_hpp


#include "Walkway.h"

namespace KaboomBoy
{
    
    class Destructible : public WalkWay
    {
    public:
        virtual bool occupied()    { return true; }
        virtual bool destroyable() { return true; }
        
        static Destructible *update(WorldElement *previous);
        
        virtual WorldElement* advanceTurn(int *propagateDistance, bool *update);
        virtual WorldElement* propogateFrom(WorldElement *source);
    };
}


#endif /* Destructible_hpp */
