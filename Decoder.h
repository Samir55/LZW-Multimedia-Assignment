//
//  Decoder.hpp
//
//
//  Created by ASamir on 4/29/17.
//  Copyright © 2017 ASamir. All rights reserved.
//
#pragma once
#ifndef Decoder_hpp
#define Decoder_hpp

#include "Utils.h"
using namespace std;

class Decoder{
private:
    vector<int> encodedMessage;
    string decodedMessage;
    map<int, string> dictionary;
    int lastIndex;
public:
    Decoder();
    ~Decoder();
    void readEncodedMessage(string filePath);
    void decodeMessage();
    void initializeDictionary();
    void saveDictionary(string filePath);
    void saveDecodedMeesage(string filePath);
};


#endif /* Decoder_hpp */
