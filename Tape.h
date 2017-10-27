//
//  Tape.h
//  CC2-TuringMachine
//
//  Created by Óscar Darias Plasencia on 23/10/2017.
//  Copyright © 2017 Óscar Darias Plasencia. All rights reserved.
//

#ifndef Tape_h
#define Tape_h

#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <cstring>

class Tape {

private:
    int pointer;
    char white;
    std::vector<char> sequence;
    std::set<char> alphabet;

public:
    Tape();
    //Tape(char filename[]);
    Tape(std::string alph, char wh);
    Tape(const Tape& copy);
    ~Tape();

    char get();
    void setSequence(const std::string& seq);
    std::vector<char> getSequence();

    void movePointer(char movement);
    void write(char symbol);
    void writeAndMove(char symbol, char movement);
    void printResult();

    void reset();

    Tape& operator= (const Tape& other);
};


#endif /* Tape_h */
