//
//  Status.h
//  CC2-TuringMachine
//
//  Created by Óscar Darias Plasencia on 23/10/2017.
//  Copyright © 2017 Óscar Darias Plasencia. All rights reserved.
//

#ifndef Status_h
#define Status_h

#pragma once

#include "Transition.h"

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <vector>
#include <iterator>
#include <algorithm>
#include <fstream>
#include <sstream>

class Status {

private:
    std::string identifier;
    bool acceptance;
    std::vector<Transition> transitions;

public:
    Status();
    Status(std::string symbol, bool accep);
    ~Status();

    std::string getID();
    bool isAnAcceptanceStatus();
    void setAcceptance();
    Transition getTransitionFor(std::string input);

    void addTransition(const Transition& newTrans);
};











#endif /* Status_h */
