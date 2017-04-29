//
//  Decoder.cpp
//
//
//  Created by ASamir on 4/29/17.
//  Copyright © 2017 ASamir. All rights reserved.
//

#include "Decoder.h"

Decoder::Decoder() {
    this->decodedMessage = "";
}

Decoder::~Decoder() {


}

void Decoder::readEncodedMessage(string filePath) {
    FileManipulator fileObject;
    this->encodedMessage = fileObject.integerReadFromFile(filePath);
    return ;
}

void Decoder::initializeDictionary() {
    this->lastIndex = 0;
    for(int i = 0; i < 26; i++){
        string s ="";
        dictionary[i ] = s + char('a'+ i);
        lastIndex = i+1;
    }
}

void Decoder::decodeMessage() {

    string Prev = "" ;
    int index = 0;
    while(index < this->encodedMessage.size()){
        int newCode = this->encodedMessage[index++];
        string Entry = "";
        Entry = this->dictionary[newCode];
        if( Entry == "" ){
          Entry = Prev + Prev[0];
        }
        //Output Entry
        this->decodedMessage += Entry;
        if(Prev != ""){
            this->dictionary[this->lastIndex++] = Prev + Entry[0];
        }
        Prev = Entry;
    }
}

void Decoder::saveDecodedMeesage(string filePath) {
    FileManipulator fileObject;
    fileObject.writeToFile(this->decodedMessage, filePath);
}

void Decoder::saveDictionary(string filePath) {
    FileManipulator fileObject;
    fileObject.WriteDictionaryToFile(this->dictionary,filePath);
}