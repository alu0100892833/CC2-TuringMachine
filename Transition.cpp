//
//  Transition.cpp
//  CC2-TuringMachine
//
//  Created by Óscar Darias Plasencia on 23/10/2017.
//  Copyright © 2017 Óscar Darias Plasencia. All rights reserved.
//

#include "Transition.h"

Transition::Transition() {
    originalStatus = "";
}


Transition::Transition(const std::string& origin, const std::string& next, const std::vector<std::string>& symbol,
                       const std::vector<std::string>& wr, const std::vector<char>& mov) {
    originalStatus = origin;
    nextStatus = next;
    input = symbol;
    write = wr;
    movement = mov;
}

Transition::Transition(const Transition& copy) {
    originalStatus = copy.originalStatus;
    nextStatus = copy.nextStatus;
    input = copy.input;
    write = copy.write;
    movement = copy.movement;
}

Transition::~Transition() = default;


std::string Transition::getNextStatus() const {
    return nextStatus;
}


std::vector<std::string> Transition::getInput() const {
    return input;
}


std::vector<std::string> Transition::getWrite() const {
    return write;
}


std::vector<char> Transition::getMovement() const {
    return movement;
}

std::string Transition::getOriginalStatus() const {
    return originalStatus;
}





std::ostream& operator<< (std::ostream& os, const Transition& tst) {
    os << tst.getOriginalStatus();
    for (const std::string& temp : tst.getInput())
        os << " " << temp;
    os << " ; " << tst.getNextStatus();
    for (const std::string& temp : tst.getWrite())
        os << " " << temp;
    for (const char temp : tst.getMovement())
        os << " " << temp;
    return os;
}

bool operator==(const Transition& first, const Transition& second) {
    return ((first.getInput() == second.getInput())
        && (first.getOriginalStatus() == second.getOriginalStatus())
        && (first.getNextStatus() == second.getNextStatus()));
}





























// END
