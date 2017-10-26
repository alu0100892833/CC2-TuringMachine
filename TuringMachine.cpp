//
//  TuringMachine.cpp
//  CC2-TuringMachine
//
//  Created by Óscar Darias Plasencia on 25/10/2017.
//  Copyright © 2017 Óscar Darias Plasencia. All rights reserved.
//

#include "TuringMachine.h"

std::string trim(const std::string& str);
std::vector<std::string> tokenizeBy(std::string str);

TuringMachine::TuringMachine() {}

TuringMachine::TuringMachine(char filename[]) {
    reset();
    std::ifstream tmfile;
    tmfile.open("TM/first.mt");
    if (tmfile.is_open()) {
        // IGNORE COMMENTS
        std::string dummy = "#";
        while (dummy[0] == '#') {
            std::getline(tmfile, dummy);
            dummy = trim(dummy);
        }
        // Now, dummy should have the Q set
        readQSet(dummy);
        std::getline(tmfile, dummy);
        // Now, dummy should have the input alphabet
        readInputAlphabet(trim(dummy));
        std::string tapeAlphab, initialStatus, white;
        std::getline(tmfile, tapeAlphab);
        std::getline(tmfile, initialStatus);
        std::getline(tmfile, white);
        if (white.size() > 1)
            throw "ERROR. WHITE SYMBOL NOT CORRECTLY SPECIFIED. SYNTAX ERROR";
        Tape dummytape (tapeAlphab, white[0]);
        tape = dummytape;
        bool initialCorrectlyDefined = false;
        for (int i = 0; i < nodes.size(); i++)
            if (nodes[i].getID() == initialStatus) {
                initialCorrectlyDefined = true;
                initialStatusPosInVector = i;
            }
        if (!initialCorrectlyDefined)
            throw "SYNTAX ERROR. INITIAL STATE NOT SPECIFIED";
        std::getline(tmfile, dummy);
        // Now dummy has de F Set
        readFSet(dummy);
        // The rest should be transition functions
        while (!tmfile.eof()) {
            std::getline(tmfile, dummy);
            readTransitionFunction(dummy);
        }
        tmfile.close();
    } else {
        throw "ERROR. Turing Machine file could not be loaded.";
    }
}

TuringMachine::TuringMachine(const TuringMachine& copy) {
    initialStatusPosInVector = copy.initialStatusPosInVector;
    inputAlphabet = copy.inputAlphabet;
    nodes = copy.nodes;
}

TuringMachine::~TuringMachine() {
    reset();
}

void TuringMachine::addStatus(const Status& newStatus) {
    nodes.push_back(newStatus);
}


void TuringMachine::processString(std::string input) {

}

void TuringMachine::reset() {
    inputAlphabet.clear();
    std::vector<Status>().swap(nodes);
}

void TuringMachine::readQSet(std::string str) {
    std::vector<std::string> tokenized = tokenizeBy(str);
    for (int i = 0; i < tokenized.size(); i++) {
        Status temp (tokenized[i], false);
        nodes.push_back(temp);
    }
}

void TuringMachine::readInputAlphabet(std::string str) {
    std::vector<std::string> tokenized = tokenizeBy(str);
    for (int i = 0; i < tokenized.size(); i++) {
        inputAlphabet.insert(tokenized[i]);
    }
}

void TuringMachine::readFSet(std::string str) {
    std::vector<std::string> tokenized = tokenizeBy(str);
    for (int i = 0; i < tokenized.size(); i++) {
        findStatusByID(tokenized[i])->setAcceptance();
    }
}

Status* TuringMachine::findStatusByID(std::string identifier) {
    for (int i = 0; i < nodes.size(); i++)
        if (nodes[i].getID() == identifier)
            return &nodes[i];
    return nullptr;
}

void TuringMachine::readTransitionFunction(std::string str) {
    std::vector<std::string> tokenized = tokenizeBy(str);
    if (tokenized.size() != 5)
        throw "SYNTAX ERROR. TRANSITION FUNCTION NOT CORRECTLY DEFINED";
    else if (tokenized[4].size() > 1)
        throw "SYNTAX ERROR. UNRECOGNIZED MOVEMENT IN TRANSITION FUNCTION DEFINITION.";
    else if (findStatusByID(tokenized[0]) == nullptr)
        throw "SYNTAX ERROR. ORIGIN STATE IN TRANSITION FUNCTION DOES NOT EXIST.";
    else if (findStatusByID(tokenized[2]) == nullptr)
        throw "SYNTAX ERROR. DESTINATION STATE IN TRANSITION FUNCTION DOES NOT EXIST.";
    Transition newTrans(tokenized[0], tokenized[2], tokenized[1], tokenized[3], tokenized[4][0]);
    findStatusByID(tokenized[0])->addTransition(newTrans);
}





/*********************************************
 * INDEPENDENT METHODS
 *********************************************/

std::string trim(const std::string& str) {
    size_t first = str.find_first_not_of(' ');
    if (std::string::npos == first)
        return str;
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last - first + 1));
}


std::vector<std::string> tokenizeBy(std::string str) {
    str = trim(str);
    std::vector<std::string> result;
    char *line = new char[str.size() + 1];
    std::copy(str.begin(), str.end(), line);
    line[str.size()] = '\0';
    char *token = std::strtok(line, " ");
    while (token != nullptr) {
        std::string value(token);
        result.push_back(value);
    }
    return result;
}













// END
