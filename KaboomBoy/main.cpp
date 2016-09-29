//
//  main.cpp
//  KaboomBoy
//
//  Created by J. Schalkwijk on 28/09/2016.
//  Copyright © 2016 JeromeSchalkwijk. All rights reserved.
//

#include <iostream>
#include <fstream>

#include "World.h"

using namespace KaboomBoy;

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    std::ifstream reader("/Users/jerome/Development/KaboomBoy/data/level/example.lvl");
    
    if (reader.is_open())
        std::cout << "Level opened..\n";
    
    World world;
    world.parse(reader);
    
    return 0;
}
