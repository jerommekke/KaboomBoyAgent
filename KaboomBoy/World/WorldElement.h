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
        
    protected:
        
        
    private:
        WorldElement *createElement(char asciiChar);
        
    };
    
    class Indestructible : public WorldElement
    {
    public:
        virtual bool walkable()    { return false; }
        virtual bool occupied()    { return false; }
        virtual bool destroyable() { return false; }
        virtual bool agent()       { return false; }
        virtual bool bomb()        { return false; }
        
        static Indestructible *update(WorldElement *previous);
    };
    
    class WalkWay : public WorldElement
    {
    public:
        virtual bool walkable()    { return true; }
        virtual bool occupied()    { return false; }
        virtual bool destroyable() { return true; }
        virtual bool agent()       { return false; }
        virtual bool bomb()        { return false; }

        static WalkWay *update(WorldElement *previous);
        
    };
    
    
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
        
    private:
        int mTurnsBeforeBoom;
        int mPower;  // number of elements the explosion will reach
    };
    
    class Destructible : public WalkWay
    {
    public:
        virtual bool occupied()    { return true; }
        virtual bool destroyable() { return true; }
        
        static Destructible *update(WorldElement *previous);
    };
    
    class Explosion : public WalkWay
    {
    public:
        virtual bool occupied()    { return true; }
        virtual bool destroyable() { return false; }
        
        static Explosion *update(WorldElement *previous);
    };
    
    class Agent : public WalkWay
    {
    public:
        Agent(char identity) : mIdentity(identity) {}
        
        virtual bool occupied()    { return true; }
        virtual bool destroyable() { return true; }
        virtual bool agent()       { return true; }
        
        int bombPower() const { return 3; }
        static Agent *update(WorldElement *previous, char asciiChar);
    private:
        char mIdentity;

    };
    

}

#endif /* WorldElement_h */
