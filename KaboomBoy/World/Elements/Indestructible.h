//
//  Indestructible.hpp
//  KaboomBoy
//
//  Created by J. Schalkwijk on 24/10/2016.
//  Copyright © 2016 JeromeSchalkwijk. All rights reserved.
//

#ifndef Indestructible_hpp
#define Indestructible_hpp

#include "WorldElement.h"

namespace KaboomBoy
{
    class Indestructible : public WorldElement
    {
    public:
        virtual bool walkable()    { return false; }
        virtual bool occupied()    { return false; }
        virtual bool destroyable() { return false; }
        virtual bool agent()       { return false; }
        virtual bool bomb()        { return false; }
        
        virtual WorldElement* advanceTurn(int *propagateDistance, bool *update);
        virtual WorldElement* propagateFrom(WorldElement *source);
        
        static Indestructible *update(WorldElement *previous);
    };
    
}


#endif /* Indestructible_hpp */
