//
//  Status.h
//  CC2-TuringMachine
//
//  Created by Óscar Darias Plasencia on 23/10/2017.
//  Copyright © 2017 Óscar Darias Plasencia. All rights reserved.
//

#ifndef Status_h
#define Status_h

#pragma once

#include "Transition.h"

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <vector>
#include <iterator>
#include <algorithm>
#include <fstream>
#include <sstream>

/**
 * @brief A class that represents a status or node in a Turing Machine.
 * @author Óscar Darias Plasencia
 */
class Status {

private:
    std::string identifier;
    bool acceptance;
    std::vector<Transition> transitions;

public:

    /**
     * @brief Default constructor.
     */
    Status();

    /**
     * @brief Parameter constructor
     * @param symbol The identificator of the status
     * @param accep Specifies if it will be an acceptance status
     */
    Status(const std::string& symbol, bool accep);

    /**
     * @brief Destructor.
     */
    ~Status();


    /**
     * @brief Getter for the identificator.
     * @return ID of the status.
     */
    std::string getID() const;

    /**
     * @brief Check if it is an acceptance status
     * @return Value of acceptance
     */
    bool isAnAcceptanceStatus();

    /**
     * @brief Sets the status as an acceptance status.
     */
    void setAcceptance();

    /**
     * @brief Returns a transition that matches the input given as an argument.
     * @param input Vector with all the input strings read on the different tapes.
     * @return A matching Transition. Will be empty if not found.
     */
    Transition getTransitionFor(const std::vector<std::string>& input);


    /**
     * @brief Adds a new Transition object to the vector of transitions of the status.
     * @param newTrans
     */
    void addTransition(const Transition& newTrans);
};

/**
 * @brief Operator << overload for Status.
 * @param os
 * @param output
 * @return
 */
std::ostream& operator<< (std::ostream& os, const Status& output);









#endif /* Status_h */
