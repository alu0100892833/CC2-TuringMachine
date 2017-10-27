//
//  TuringMachine.h
//  CC2-TuringMachine
//
//  Created by Óscar Darias Plasencia on 25/10/2017.
//  Copyright © 2017 Óscar Darias Plasencia. All rights reserved.
//

#ifndef TuringMachine_h
#define TuringMachine_h

#pragma once

#include "Status.h"
#include "Tape.h"

#include <set>

class TuringMachine {

private:
    int initialStatusPosInVector;
    std::set<std::string> inputAlphabet;
    std::vector<Status> nodes;
    Tape tape;

public:
    TuringMachine();
    TuringMachine(const TuringMachine& copy);
    ~TuringMachine();

    void build(char filename[]);

    int getInitialStatusPos() const;
    void addStatus(const Status& newStatus);
    void processString(std::string input);
    void processStringFromFile(std::string filename);

    void print();

private:
    void reset();
    void readQSet(std::string str);
    void readFSet(std::string str);
    void readInputAlphabet(std::string str);
    Status* findStatusByID(std::string identifier);
    void readTransitionFunction(std::string str);
};


#endif /* TuringMachine_h */
