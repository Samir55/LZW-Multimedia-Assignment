//
//  Encoder.h
//
//
//  Created by ASamir on 4/29/17.
//  Copyright © 2017 ASamir. All rights reserved.
//
#pragma once
#ifndef Encoder_h
#define Encoder_h

#include "Utils.h"

class Encoder{
private:
    string readMessage;
    vector<int> encodedMessage;
    map<string, int> dictionary;
    int lastCode;
public:
    Encoder();
    ~Encoder();
    void readMessageFromFile(string filePath);
    void initializeDictionary();
    void saveDictionary(string filePath);
    void encodeMessage();
    void saveEncodedMessage(string filePath);
    
};

#endif /* Encoder_h */
