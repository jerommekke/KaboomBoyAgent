//
//  WorldElement.hpp
//  KaboomBoy
//
//  Created by J. Schalkwijk on 29/09/2016.
//  Copyright © 2016 JeromeSchalkwijk. All rights reserved.
//

#ifndef WorldElement_h
#define WorldElement_h

namespace KaboomBoy {
    class WorldElement
    {
    public:
        WorldElement() {}
        virtual ~WorldElement() {}
        
        static WorldElement* create(char asciiChar, WorldElement* previousTurn);
        
        virtual bool walkable() = 0;
        virtual bool occupied() = 0;
        virtual bool destroyable() = 0;
        virtual bool agent() = 0;
        virtual bool bomb() = 0;
        
        virtual WorldElement* advanceTurn(int *propagateDistance, bool *update) = 0;
        virtual WorldElement* propogateFrom(WorldElement *source) = 0;
    protected:
        
        
    private:
        WorldElement *createElement(char asciiChar);
        
    };
    
 

}

#endif /* WorldElement_h */
