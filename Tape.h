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

/**
 * @brief A class that represents a tape in a Turing Machine.
 * The tape is infinite in both sides, filled with blank symbols when needed.
 * @author Óscar Darias Plasencia
 */
class Tape {

private:
    int pointer;
    char white;
    std::vector<char> sequence;
    std::set<char> alphabet;

public:
    /**
     * @brief Default constructor.
     */
    Tape();

    /**
     * @brief Parameter constructor.
     * @param alph String with all the symbols of the alphabet.
     * @param wh Blank or white symbol.
     */
    Tape(std::string alph, char wh);

    /**
     * @brief Copy constructor.
     * @param copy
     */
    Tape(const Tape& copy);

    /**
     * @brief Destructor.
     */
    ~Tape();

    /**
     * @brief Returns the value of the tape pointed at the moment.
     * @return
     */
    char get();

    /**
     * @brief Returns the white symbol.
     * @return
     */
    char getWhite();

    /**
     * @brief Returns the alphabet of the tape as a string.
     * @return
     */
    std::string getAlphabetAsString();

    /**
     * @brief Sets the tape as an empty one.
     * All tapes on a multitape Turing Machine that are not the main tape, are empty tapes at start.
     * @param alph Alphabet of the tape as a string.
     * @param wh White symbol.
     */
    void setAsEmptyTape(const std::string& alph, char wh);

    /**
     * @brief Sets the alphabet.
     * @param alph Alphabet as a string.
     */
    void setAlphabet(const std::string& alph);

    /**
     * Sets the initial sequence for the tape.
     * @param seq
     */
    void setSequence(const std::string& seq);

    /**
     * Returns the current status of the sequence.
     * @return
     */
    std::vector<char> getSequence();


    /**
     * Moves the pointer according to the given parameter.
     * @param movement R moves right, L moves left, and S keeps the pointer without moving.
     */
    void movePointer(char movement);

    /**
     * @brief Writes a certain symbol at the current position.
     * @param symbol
     */
    void write(char symbol);

    /**
     * @brief Writes a symbol and moves, according to the given parameters.
     * @param symbol
     * @param movement
     */
    void writeAndMove(char symbol, char movement);

    /**
     * @brief Prints the status of the tape, from the pointer to the end.
     */
    void printResult();

    /**
     * @brief Resets the tape to its original status.
     */
    void reset();

    /**
     * @brief Operator = overloading.
     * @param other
     * @return
     */
    Tape& operator= (const Tape& other);
};


#endif /* Tape_h */
