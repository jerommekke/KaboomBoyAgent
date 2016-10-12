//
//  Controller.cpp
//  KaboomBoy
//
//  Created by J. Schalkwijk on 12/10/2016.
//  Copyright © 2016 JeromeSchalkwijk. All rights reserved.
//

#include "Controller.h"

#include <fstream>

namespace KaboomBoy
{

    Controller::Controller()
    {
        
    }
    
    Controller::~Controller()
    {
        
    }

    void Controller::update()
    {
        
        std::ifstream reader("/Users/jerome/Development/KaboomBoy/data/level/example.lvl");
        
        std::cerr << "Opening level..";
        if (reader.is_open())
            std::cerr << "level opened..";
        
        mWorld.parse(reader);
        
        std::cerr << ".. done\n";
        std::cerr << "Calculating definite futures..";
        
        mDefiniteFuture.calculateFutures(mWorld);
        
        std::cerr << "..done\n";
        
    }
    
    
}
