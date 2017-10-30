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

/**
 * @brief A class that represents a Turing Machine.
 * @author Óscar Darias Plasencia
 */
class TuringMachine {

private:
    int initialStatusPosInVector;
    std::set<std::string> inputAlphabet;
    std::vector<Status> nodes;
    std::vector<Tape> tape;

public:

    /**
     * @brief Default constructor.
     */
    TuringMachine();

    /**
     * @brief Copy constructor.
     * @param copy
     */
    TuringMachine(const TuringMachine& copy);

    /**
     * Destructor.
     */
    ~TuringMachine();

    /**
     * @brief Builds the Turing Machine from a file.
     * @param filename Name of the file, which should have the correct syntax.
     */
    void build(char filename[]);

    /**
     * @brief Returns the position of the initial status within the status vector.
     * @return
     */
    int getInitialStatusPos() const;

    /**
     * @brief Adds a new status to the machine.
     * @param newStatus
     */
    void addStatus(const Status& newStatus);

    /**
     * @brief Processes the given string, checking if it is accepted by the machine.
     * @param input
     */
    void processString(std::string input);

    /**
     * @brief Processes one or various strings stored in a file, checking if the machine accepts them.
     * @param filename
     */
    void processStringFromFile(std::string filename);



private:

    /**
     * @brief Prints the final status of the machine, once it finishes processing a string.
     */
    void printResult();

    /**
     * @brief Resets the machine to its original values.
     */
    void reset();

    /**
     * @brief Resets all the tapes to their original values.
     */
    void resetTapes();

    /**
     * @brief Processes a string, interpretting it as the status set from the file where the machine is specified.
     * @param str
     */
    void readQSet(std::string str);

    /**
     * @brief Processes a string, interpretting it as the final status set from the file where the machine is specified.
     * @param str
     */
    void readFSet(std::string str);

    /**
     * @brief Processes a string, interpretting it as the input alphabet from the file where the machine is specified.
     * @param str
     */
    void readInputAlphabet(std::string str);

    /**
     * @brief Tries to find a status given its ID.
     * @param identifier
     * @return Pointer to the status with the given ID. If not found, returns nullptr.
     */
    Status* findStatusByID(std::string identifier);

    /**
     * @brief Processes a string, interpretting it as a transition function from the file where the machine is specified.
     * @param str
     */
    void readTransitionFunction(std::string str);
};


#endif /* TuringMachine_h */
