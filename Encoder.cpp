//
//  Encoder.cpp
//
//
//  Created by ASamir on 4/29/17.
//  Copyright © 2017 ASamir. All rights reserved.
//

#include "Encoder.h"

Encoder::Encoder(){

    
}

void Encoder::initializeDictionary(){

    for(int i = 0; i < 26; i++){
        string s ="";
        dictionary[s + char('a'+ i)] = i ;
        lastCode = i+1;
    }
}

void Encoder::readMessageFromFile(string filePath){
    FileManipulator fileObject;
    this->readMessage = fileObject.readFromFile(filePath);
    //For Checking the output
    //cout << this->readMessage << endl;
    return ;
}

void Encoder::encodeMessage(){
    string String = "";
    int index = 0;
    String += this->readMessage[index++];

    while( index < this->readMessage.size()){
        char Char = this->readMessage[index++];
        if( this->dictionary.count(String + Char) > 0) //Check if concatenated string exists in the dictionary
        {
            String = String + Char;
        }
        else{
            //Add Current String Code to the EncodedMessage
            this->encodedMessage.push_back(this->dictionary[String]);
            //Add to the Dictionary the concatenated String
            this->dictionary[(String + Char)] = this->lastCode++;
            String = Char;
        }
    }
    //Add last String Code to the EncodedMessage
    this->encodedMessage.push_back(this->dictionary[String]);
}

void Encoder::saveEncodedMessage(string filePath){
    FileManipulator fileObject;
    fileObject.writeToFile(this->encodedMessage, filePath);
}

void Encoder::saveDictionary(string filePath){
    FileManipulator fileObject;
    fileObject.WriteDictionaryToFile(this->dictionary, filePath);
}

Encoder::~Encoder(){
    
}
