//
//  IFuture.h
//  KaboomBoy
//
//  Created by J. Schalkwijk on 12/10/2016.
//  Copyright © 2016 JeromeSchalkwijk. All rights reserved.
//

#ifndef IFuture_h
#define IFuture_h

#include <list>

namespace KaboomBoy
{
    
    class World;
    
    /* Interface for representations of the future */
    class IFuture
    {
    public:
        typedef std::list<const World *> futures_t;
        
        virtual ~IFuture() {}
        
        // Return representations of the world a certain number of turns into the future
        virtual futures_t worldInTurns(int numberOfTurns) = 0;
        
        // Ask for the number of steps into the future we have a representation of
        virtual int futureDepth() = 0;
        
        
    };
}



#endif /* IFuture_h */
