//
//  Status.cpp
//  CC2-TuringMachine
//
//  Created by Óscar Darias Plasencia on 23/10/2017.
//  Copyright © 2017 Óscar Darias Plasencia. All rights reserved.
//

#include <cstdio>
#include "Status.h"

Status::Status() {
    identifier = "";
}

Status::Status(std::string symbol, bool accep) {
    identifier = symbol;
    acceptance = accep;
}

Status::~Status() {
    transitions.clear();
    std::vector<Transition>().swap(transitions);
}

std::string Status::getID() const {
    return identifier;
}


bool Status::isAnAcceptanceStatus() {
    return acceptance;
}

void Status::setAcceptance() {
    acceptance = true;
}


Transition Status::getTransitionFor(std::string input) {
    Transition result;
    for (int i = 0; i < transitions.size(); i++) {
        if (transitions[i].getInput() == input)
            result = transitions[i];
    }

    return result;
}


void Status::addTransition(const Transition& newTrans) {
    for (int i = 0; i < transitions.size(); i++)
        if (newTrans == transitions[i])
            return;
    transitions.push_back(newTrans);
}




std::ostream& operator<< (std::ostream& os, const Status& output) {
    os << output.getID();
    return os;
}





















// END
