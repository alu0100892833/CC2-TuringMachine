//
//  main.cpp
//  CC2-TuringMachine
//
//  Created by Óscar Darias Plasencia on 23/10/2017.
//  Copyright © 2017 Óscar Darias Plasencia. All rights reserved.
//

#include <iostream>
#include "TuringMachine.h"


int main(int argc, const char * argv[]) {
    try {
        TuringMachine tm("mt.txt");
    } catch(const char* msg) {
        std::cerr << msg << std::endl;
    }
    return 0;
}
