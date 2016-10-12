//
//  Controller.hpp
//  KaboomBoy
//
//  Created by J. Schalkwijk on 12/10/2016.
//  Copyright © 2016 JeromeSchalkwijk. All rights reserved.
//

#ifndef Controller_h
#define Controller_h

#include "World/World.h"
#include "Future/DefiniteFuture.h"

namespace KaboomBoy
{
    class Controller
    {
    public:
        Controller();
        ~Controller();
        
        /**
         * Updates the world based on server input
         */
        void update();
        
        
    private:
        World mWorld;
        DefiniteFuture mDefiniteFuture;
        
    };
}

#endif /* Controller_h */
