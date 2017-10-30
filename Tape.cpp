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


Tape::Tape(std::string alph, char wh) {
    pointer = 0;
    white = wh;
    for (char temp : alph) {
        if (temp != ' ')
            alphabet.insert(temp);
    }
}


Tape::Tape(const Tape& copy) {
    pointer = copy.pointer;
    sequence = copy.sequence;
    white = copy.white;
}


Tape::~Tape() {
    sequence.clear();
    alphabet.clear();
}

char Tape::get() {
    return sequence[pointer];
}

void Tape::setSequence(const std::string& seq) {
    for (char temp : seq) {
        if (temp != ' ')
            sequence.push_back(temp);
    }
}

std::vector<char> Tape::getSequence() {
    return sequence;
}

void Tape::setAsEmptyTape(const std::string& alph) {
    sequence.push_back(white);
    this->setAlphabet(alph);
    pointer = 0;
}

void Tape::setAlphabet(const std::string& alph) {
    for (char temp : alph) {
        if (temp != ' ')
            alphabet.insert(temp);
    }
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

void Tape::printResult() {
    for (int i = pointer; i < sequence.size(); i++)
        std::cout << sequence[i] << " ";
    std::cout << white;
}

void Tape::reset() {
    sequence.clear();
    pointer = 0;
}

Tape& Tape::operator=(const Tape& other) {
    pointer = other.pointer;
    white = other.white;
    sequence = other.sequence;
    alphabet = other.alphabet;
    return *this;
}













// END
