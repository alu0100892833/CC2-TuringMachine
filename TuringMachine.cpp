//
//  TuringMachine.cpp
//  CC2-TuringMachine
//
//  Created by Óscar Darias Plasencia on 25/10/2017.
//  Copyright © 2017 Óscar Darias Plasencia. All rights reserved.
//

#include "TuringMachine.h"

std::string trim(const std::string& str);
std::vector<std::string> tokenizeBy(const std::string& str);

TuringMachine::TuringMachine() {
    initialStatusPosInVector = -1;
}

void TuringMachine::build(char filename[]) {
    reset();
    std::ifstream tmfile;
    tmfile.open(filename);
    if (tmfile.is_open()) {
        // IGNORE COMMENTS
        std::string dummy = "#";
        while (dummy[0] == '#') {
            std::getline(tmfile, dummy);
            dummy = trim(dummy);
        }
        // Now, dummy could have the Q set or the specific number of tapes
        if (tokenizeBy(dummy).size() == 1) {
            tape.resize((unsigned long) std::stoi(tokenizeBy(dummy)[0]));
            std::getline(tmfile, dummy);
        } else
            tape.resize(1);
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
        //tape = dummytape;
        tape[0] = dummytape;
        for (int i = 1; i < tape.size(); i++)
            tape[i].setAsEmptyTape(tapeAlphab, white[0]);
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
        std::getline(tmfile, dummy);
        while (!tmfile.eof()) {
            readTransitionFunction(dummy);
            std::getline(tmfile, dummy);
        }
        readTransitionFunction(dummy);
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

int TuringMachine::getInitialStatusPos() const {
    return initialStatusPosInVector;
}

void TuringMachine::addStatus(const Status& newStatus) {
    nodes.push_back(newStatus);
}


void TuringMachine::processString(std::string input) {
    if (initialStatusPosInVector == -1) {
        std::cout << "UNDEFINED TURING MACHINE." << std::endl;
        return;
    }
    try {
        std::cout << std::endl << "PROCESSING STRING: " << input << std::endl;
        tape[0].setSequence(input);
        Status *current = &nodes[initialStatusPosInVector];
        while (true) {
            std::vector<std::string> reading;
            for (Tape temp : tape) {
                std::string symbol(1, temp.get());
                reading.push_back(symbol);
            }
            Transition next = current->getTransitionFor(reading);
            if (next.getOriginalStatus().empty()) break;
            current = findStatusByID(next.getNextStatus());
            if (current == nullptr) throw "BAD POINTER. DESTINATION STATUS DOES NOT EXIST.";
            for (int i = 0; i < tape.size(); i++) {
                char symbol = next.getWrite()[i][0];
                tape[i].writeAndMove(symbol, next.getMovement()[i]);
            }
        }
        if (current->isAnAcceptanceStatus()) {
            std::cout << std::endl << "RECOGNIZED STRING" << std::endl;
            std::cout << "TAPE FINAL SEQUENCE:   ";
            printResult();
            std::cout << std::endl << std::endl;
        } else {
            std::cout << std::endl << "STRING NOT RECOGNIZED" << std::endl;
        }
        resetTapes();
    } catch(const char* msg) {
        std::cerr << msg << std::endl;
    }
}

void TuringMachine::processStringFromFile(std::string filename) {
    std::ifstream reader;
    reader.open(filename);
    if (reader.is_open()) {
        std::string input;
        std::getline(reader, input);
        while ((!input.empty()) && (!reader.eof())) {
            processString(input);
            std::getline(reader, input);
        }
        reader.close();
    } else {
        std::cout << "FILE NOT FOUND" << std::endl;
    }
}


void TuringMachine::reset() {
    inputAlphabet.clear();
    std::vector<Status>().swap(nodes);
}

void TuringMachine::readQSet(std::string str) {
    std::vector<std::string> tokenized = tokenizeBy(str);
    for (int i = 0; i < tokenized.size(); i++) {
        Status temp (tokenized[i], false);
        addStatus(temp);
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
    if (str.empty()) return;
    std::vector<std::string> tokenized = tokenizeBy(str);
    /*if (tokenized.size() != 5)
        throw "SYNTAX ERROR. TRANSITION FUNCTION NOT CORRECTLY DEFINED";
    else if (tokenized[4].size() > 1)
        throw "SYNTAX ERROR. UNRECOGNIZED MOVEMENT IN TRANSITION FUNCTION DEFINITION.";
    else if (findStatusByID(tokenized[0]) == nullptr)
        throw "SYNTAX ERROR. ORIGIN STATE IN TRANSITION FUNCTION DOES NOT EXIST.";
    else if (findStatusByID(tokenized[2]) == nullptr)
        throw "SYNTAX ERROR. DESTINATION STATE IN TRANSITION FUNCTION DOES NOT EXIST.";*/
    if (tokenized.size() != 2 + tape.size() * 3)
        throw "SYNTAX ERROR. TRANSITION FUNCTION NOT CORRECTLY DEFINED";
    std::vector<std::string> input, write;
    std::vector<char> movements;
    for (int i = 1; i <= tape.size(); i++)
        input.push_back(tokenized[i]);
    for (int i = (int)tape.size() + 2; i < tokenized.size() - tape.size(); i++)
        write.push_back(tokenized[i]);
    for (int i = (int)tokenized.size() - (int)tape.size(); i < tokenized.size(); i++)
        movements.push_back(tokenized[i][0]);
    Transition newTrans(tokenized[0], tokenized[tape.size() + 1], input, write, movements);
    findStatusByID(tokenized[0])->addTransition(newTrans);
}

void TuringMachine::printResult() {
    for (Tape temp : tape) {
        temp.printResult();
        std::cout << std::endl;
    }
}

void TuringMachine::resetTapes() {
    for (int i = 0; i < tape.size(); i++) {
        tape[i].reset();
        if (i != 0) {
            char wh = tape[i].getWhite();
            std::string alph = tape[i].getAlphabetAsString();
            tape[i].setAsEmptyTape(alph, wh);
        }
    }
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


std::vector<std::string> tokenizeBy(const std::string& str) {
    std::string trimmed = trim(str);
    std::string value;
    std::vector<std::string> result;
    result.push_back("dummy");  // if not initialised outside the loop, push_back does not work, I do not know why
    auto *line = new char[trimmed.size() + 1];
    std::copy(trimmed.begin(), trimmed.end(), line);
    line[trimmed.size()] = '\0';
    char *token = std::strtok(line, " ");
    while (token != nullptr) {
        value = token;
        token = std::strtok(nullptr, " ");
        result.push_back(value);
    }
    result.erase(result.begin());
    return result;
}













// END
