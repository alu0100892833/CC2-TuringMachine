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


Transition::Transition(std::string origin, std::string next, std::string symbol, std::string wr, char mov) {
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

Transition::~Transition() {}


std::string Transition::getNextStatus() const {
    return nextStatus;
}


std::string Transition::getInput() const {
    return input;
}


std::string Transition::getWrite() const {
    return write;
}


char Transition::getMovement() const {
    return movement;
}

std::string Transition::getOriginalStatus() const {
    return originalStatus;
}





std::ostream& operator<< (std::ostream& os, const Transition& tst) {
    os << tst.getOriginalStatus() << " " << tst.getInput();
    os << " ; " << tst.getNextStatus() << " " << tst.getWrite() << " " << tst.getMovement();
    return os;
}

bool operator==(const Transition& first, const Transition& second) {
    return ((first.getInput() == second.getInput())
        && (first.getOriginalStatus() == second.getOriginalStatus())
        && (first.getNextStatus() == second.getNextStatus()));
}





























// END
