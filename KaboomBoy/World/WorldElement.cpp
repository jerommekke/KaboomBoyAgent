//
//  WorldElement.cpp
//  KaboomBoy
//
//  Created by J. Schalkwijk on 29/09/2016.
//  Copyright © 2016 JeromeSchalkwijk. All rights reserved.
//

#include "WorldElement.h"

#include "Elements/Indestructible.h"
#include "Elements/Walkway.h"
#include "Elements/Destructible.h"
#include "Elements/Agent.h"
#include "Elements/Bomb.h"
#include "Elements/Explosion.h"


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
       
    
}

