//
//  main.cpp
//  KaboomBoy
//
//  Created by J. Schalkwijk on 28/09/2016.
//  Copyright © 2016 JeromeSchalkwijk. All rights reserved.
//

#include <iostream>

#include "Controller.h"

using namespace KaboomBoy;

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cerr << "Launching KaboomBoyAgent for Jerommekke!\n";
    
    Controller controller;
    
    controller.update();
    
    
    return 0;
}
