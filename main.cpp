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
        int option = 1;
        char filename[] = "";
        TuringMachine tm;
        std::cout << "WELCOME. THIS PROGRAM SIMULATES A TURING MACHINE." << std::endl << std::endl;
        while (option != 0) {
            std::cout << std::endl << "\t0. EXIT" << std::endl;
            std::cout << "\t1. LOAD NEW TURING MACHINE FROM FILE" << std::endl;
            std::cout << "\t2. PROCESS NEW INPUT FROM FILE" << std::endl;
            std::cout << "\t3. PROCESS NEW MANUAL INPUT" << std::endl << std::endl;
            std::cin >> option;

            switch (option) {
                case 0 :
                    std::cout << "EXITING..." << std::endl;
                    break;
                case 1 :
                    std::cout << "SPECIFY THE NAME OF THE FILE: ";
                    std::cin >> filename;
                    tm.build(filename);
                    break;
                case 2 :
                    if (tm.getInitialStatusPos() == -1)
                        std::cout << "YOU FIRST NEED TO LOAD A TURING MACHINE." << std::endl;
                    else {
                        std::string inputfile;
                        std::cout << "SPECIFY THE NAME OF THE FILE: ";
                        std::cin >> inputfile;
                        tm.processStringFromFile(inputfile);
                        inputfile.clear();
                    }
                    break;
                case 3 :
                    if (tm.getInitialStatusPos() == -1)
                        std::cout << "YOU FIRST NEED TO LOAD A TURING MACHINE." << std::endl;
                    else {
                        std::string input;
                        std::cout << "SPECIFY THE INPUT STRING: ";
                        std::cin >> input;
                        tm.processString(input);
                        input.clear();
                    }
                    break;

                default:
                    std::cout << option << " IS NOT A VALID OPTION." << std::endl;
            }
        }
    } catch(const char* msg) {
        std::cerr << msg << std::endl;
    }
    return 0;
}
