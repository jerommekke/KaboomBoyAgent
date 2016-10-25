//
//  Bomb.hpp
//  KaboomBoy
//
//  Created by J. Schalkwijk on 24/10/2016.
//  Copyright © 2016 JeromeSchalkwijk. All rights reserved.
//

#ifndef Bomb_hpp
#define Bomb_hpp


#include "Walkway.h"

namespace KaboomBoy
{
    
    class Bomb : public WalkWay
    {
    public:
        Bomb(int power = 3) : mTurnsBeforeBoom(3), mPower(power) {}
        
        virtual void update() { mTurnsBeforeBoom--; }
        int turnsLeft() const { return mTurnsBeforeBoom; }
        int power()     const { return mPower; }
        
        virtual bool occupied()    { return true; }
        virtual bool bomb()        { return true; }
        
        static Bomb *update(WorldElement *previous);
        
        virtual WorldElement* advanceTurn(int *propagateDistance, bool *update);
        virtual WorldElement* propagateFrom(WorldElement *source);
        
    private:
        int mTurnsBeforeBoom;
        int mPower;  // number of elements the explosion will reach
    };
    
}

#endif /* Bomb_hpp */
