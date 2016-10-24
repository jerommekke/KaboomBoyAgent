//
//  Walkway.hpp
//  KaboomBoy
//
//  Created by J. Schalkwijk on 24/10/2016.
//  Copyright © 2016 JeromeSchalkwijk. All rights reserved.
//

#ifndef Walkway_hpp
#define Walkway_hpp

#include "WorldElement.h"

namespace KaboomBoy
{
    
    class WalkWay : public WorldElement
    {
    public:
        virtual bool walkable()    { return true; }
        virtual bool occupied()    { return false; }
        virtual bool destroyable() { return true; }
        virtual bool agent()       { return false; }
        virtual bool bomb()        { return false; }
        
        static WalkWay *update(WorldElement *previous);
        
        virtual WorldElement* advanceTurn(int *propagateDistance, bool *update);
        virtual WorldElement* propogateFrom(WorldElement *source);
        
    };
    
}

#endif /* Walkway_hpp */
