//
//  Transition.h
//  CC2-TuringMachine
//
//  Created by Óscar Darias Plasencia on 23/10/2017.
//  Copyright © 2017 Óscar Darias Plasencia. All rights reserved.
//

#ifndef Transition_h
#define Transition_h

#pragma once

#include <iostream>
#include <cstring>

class Transition {

private:
    std::string nextStatus;
    std::string originalStatus;
    std::string input;
    std::string write;
    char movement;

public:
    Transition();
    Transition(const Transition& copy);
    Transition(std::string origin, std::string next, std::string symbol, std::string wr, char mov);
    ~Transition();
    std::string getNextStatus() const;
    std::string getOriginalStatus() const;
    std::string getInput() const;
    std::string getWrite() const;
    char getMovement() const;



};

std::ostream& operator<< (std::ostream& os, const Transition& tst);
bool operator==(const Transition& first, const Transition& second);



#endif /* Transition_h */
