//
//  Explosion.hpp
//  KaboomBoy
//
//  Created by J. Schalkwijk on 24/10/2016.
//  Copyright © 2016 JeromeSchalkwijk. All rights reserved.
//

#ifndef Explosion_hpp
#define Explosion_hpp


#include "Walkway.h"

namespace KaboomBoy
{
    
    class Explosion : public WalkWay
    {
    public:
        virtual bool occupied()    { return true; }
        virtual bool destroyable() { return false; }
        
        static Explosion *update(WorldElement *previous);
        
        virtual WorldElement* advanceTurn(int *propagateDistance, bool *update);
        virtual WorldElement* propogateFrom(WorldElement *source);
        
    };
    
}


#endif /* Explosion_hpp */
