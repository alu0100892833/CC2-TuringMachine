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
#include <vector>

class Transition {

private:
    std::string nextStatus;
    std::string originalStatus;
    std::vector<std::string> input;
    std::vector<std::string> write;
    std::vector<char> movement;

public:
    Transition();
    Transition(const Transition& copy);
    Transition(const std::string& origin, const std::string& next, const std::vector<std::string>& symbol,
               const std::vector<std::string>& wr, const std::vector<char>& mov);
    ~Transition();
    std::string getNextStatus() const;
    std::string getOriginalStatus() const;
    std::vector<std::string> getInput() const;
    std::vector<std::string> getWrite() const;
    std::vector<char> getMovement() const;



};

std::ostream& operator<< (std::ostream& os, const Transition& tst);
bool operator==(const Transition& first, const Transition& second);



#endif /* Transition_h */
