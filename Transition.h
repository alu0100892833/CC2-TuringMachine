//
//  Transition.h
//  CC2-TuringMachine
//
//  Created by Óscar Darias Plasencia on 23/10/2017.
//  Copyright © 2017 Óscar Darias Plasencia. All rights reserved.
//

#ifndef Transition_h
#define Transition_h

#pragma once

#include <iostream>
#include <cstring>
#include <vector>

/**
 * @brief A class that represents a transition in a Turing Machine.
 * @author Óscar Darias Plasencia
 */
class Transition {

private:
    std::string nextStatus;
    std::string originalStatus;
    std::vector<std::string> input;
    std::vector<std::string> write;
    std::vector<char> movement;

public:

    /**
     * @brief Default constructor.
     */
    Transition();

    /**
     * Copy constructor.
     * @param copy
     */
    Transition(const Transition& copy);

    /**
     * @brief Parameter constructor.
     * @param origin Origin status ID.
     * @param next Destination status ID.
     * @param symbol All the symbols that would need to be read on all tapes for this Transition to be applied.
     * @param wr All the symbols that would be written on the different tapes in case this Transition was applied.
     * @param mov All the movements for the pointers of the different tapes in case this Transition was applied.
     */
    Transition(const std::string& origin, const std::string& next, const std::vector<std::string>& symbol,
               const std::vector<std::string>& wr, const std::vector<char>& mov);

    /**
     * @brief Destructor.
     */
    ~Transition();

    /**
     * @brief Getter for the destination status.
     * @return
     */
    std::string getNextStatus() const;

    /**
     * @brief Getter for the original status.
     * @return
     */
    std::string getOriginalStatus() const;

    /**
     * @brief Getter for the needed input.
     * @return
     */
    std::vector<std::string> getInput() const;

    /**
     * @brief Getter for the symbols that would be written.
     * @return
     */
    std::vector<std::string> getWrite() const;

    /**
     * @brief Getter for the movements.
     * @return
     */
    std::vector<char> getMovement() const;

};

/**
 * @brief Operator << overload for Transition objects.
 * @param os
 * @param tst
 * @return
 */
std::ostream& operator<< (std::ostream& os, const Transition& tst);

/**
 * @brief Operator == overload for Transition objects.
 * @param first
 * @param second
 * @return
 */
bool operator==(const Transition& first, const Transition& second);



#endif /* Transition_h */
