//
//  WorldElement.cpp
//  KaboomBoy
//
//  Created by J. Schalkwijk on 29/09/2016.
//  Copyright © 2016 JeromeSchalkwijk. All rights reserved.
//

#include "WorldElement.h"

namespace KaboomBoy
{
    
    WorldElement *WorldElement::create(char asciiChar, WorldElement *previousTurn)
    {
        switch (asciiChar)
        {
            case '-': case '|': case 'H':
                return Indestructible::update(previousTurn);
                break;
            case '#':
                return Destructible::update(previousTurn);
            case ' ':
                return WalkWay::update(previousTurn);
            case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
                return Agent::update(previousTurn, asciiChar);
            case 'Q':
                return Bomb::update(previousTurn);
            case '*':
                return Explosion::update(previousTurn);
            default:
                return nullptr;
                
        }
    }
    
    template<typename T>
    T *simpleUpdate(WorldElement *previous)
    {
        if (previous == nullptr)
            return new T();
        if (T *prev = dynamic_cast<T *>(previous))
        {
            return prev;
        }
        else
        {
            delete previous;
            return new T();
        }

    }
    
    
    Indestructible *Indestructible::update(WorldElement *previous)
    {
        return simpleUpdate<Indestructible>(previous);
    }
    
    Destructible *Destructible::update(WorldElement *previous)
    {
        return simpleUpdate<Destructible>(previous);
    }
    
    WalkWay *WalkWay::update(WorldElement *previous)
    {
        return simpleUpdate<WalkWay>(previous);
    }
    
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
    
    Bomb *Bomb::update(WorldElement *previous)
    {
        if (previous == nullptr)
            return new Bomb();
        
        if (Agent *prev = dynamic_cast<Agent *>(previous))
        {
            Bomb *newBomb = new Bomb(prev->bombPower());
            delete prev;
            return newBomb;
        }
        
        delete previous;
        return new Bomb();

    }
    
    Explosion *Explosion::update(WorldElement *previous)
    {
        return simpleUpdate<Explosion>(previous); 
    }
    
}

