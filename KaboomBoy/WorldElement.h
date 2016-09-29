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
        static WorldElement* create(char asciiChar, WorldElement* previousTurn);
        
        virtual bool walkable() = 0;
        virtual bool occupied() = 0;
        virtual bool destroyable() = 0;
        virtual bool agent() = 0;
        virtual bool bomb() = 0;
        
    protected:
        virtual void update() = 0;
        
    private:
        
    };
    
    class Indestructible : public WorldElement
    {
    public:
        virtual bool walkable()    { return false; }
        virtual bool occupied()    { return false; }
        virtual bool destroyable() { return false; }
        virtual bool agent()       { return false; }
        virtual bool bomb()        { return false; }
    };
    
    class WalkWay : public WorldElement
    {
    public:
        virtual bool walkable()    { return true; }
        virtual bool occupied()    { return false; }
        virtual bool destroyable() { return true; }
        virtual bool agent()       { return false; }
        virtual bool bomb()        { return false; }

    };
    
    
    class Bomb : public WalkWay
    {
    public:
        Bomb() : mTurnsBeforeBoom(3), mPower(3) {}
        
        virtual void update() { mTurnsBeforeBoom--; }
        int turnsLeft() const { return mTurnsBeforeBoom; }
        int power()     const { return mPower; }
        
        virtual bool occupied()    { return true; }
        virtual bool bomb()        { return true; }
        
    private:
        int mTurnsBeforeBoom;
        int mPower;  // number of elements the explosion will reach
    };
    
    class Destructible : public WalkWay
    {
    public:
        virtual bool occupied()    { return true; }
        virtual bool destroyable() { return true; }
    };
    
    class Explosion : public WalkWay
    {
    public:
        virtual bool occupied()    { return true; }
        virtual bool destroyable() { return false; }
    };
    
    class Agent : public WalkWay
    {
    public:
        virtual bool occupied()    { return true; }
        virtual bool destroyable() { return true; }
        virtual bool agent()       { return true; }

    };
    

}

#endif /* WorldElement_h */
