//
//  Tape.cpp
//  CC2-TuringMachine
//
//  Created by Óscar Darias Plasencia on 23/10/2017.
//  Copyright © 2017 Óscar Darias Plasencia. All rights reserved.
//

#include "Tape.h"

Tape::Tape() {
    pointer = -1;
}


Tape::Tape(std::string input, char wh) {
    pointer = 0;
    white = wh;
    for (int i = 0; i < input.size(); i++)
        sequence.push_back(input[i]);
}


Tape::Tape(const Tape& copy) {
    pointer = copy.pointer;
    sequence = copy.sequence;
    white = copy.white;
}


Tape::~Tape() {
    sequence.clear();
}

char Tape::get() {
    return sequence[pointer];
}

std::vector<char> Tape::getSequence() {
    return sequence;
}


void Tape::movePointer(char movement) {
    if ((movement == 'L') && (pointer == 0)) {
        sequence.insert(sequence.begin(), white);
        return;
    } else if ((movement == 'R') && (pointer == sequence.size() - 1)) {
        sequence.push_back(white);
    }

    if (movement == 'S')
        return;
    else if (movement == 'R')
        pointer++;
    else if (movement == 'L')
        pointer--;
    else
        throw "UNKNOWN SYMBOL FOR MOVEMENT.";
}

void Tape::write(char symbol) {
    sequence[pointer] = symbol;
}

void Tape::writeAndMove(char symbol, char movement) {
    write(symbol);
    movePointer(movement);
}

Tape& Tape::operator=(const Tape& other) {
    pointer = other.pointer;
    white = other.white;
    sequence = other.sequence;
    return *this;
}













// END
