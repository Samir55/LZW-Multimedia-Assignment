//
//  main.cpp
//
// Ahmed Samir h
//  Created by ASamir on 4/29/17.
//  Copyright © 2017 ASamir. All rights reserved.
//

#include "Decoder.h"
#include "Encoder.h"

bool compareEncodedAndDecodedMessages(string eFilePath, string dFilePath){
    FileManipulator fileObject;
    string e = fileObject.readFromFile(eFilePath);
    string d = fileObject.readFromFile(dFilePath);
    return e == d;
}

string inputMessagePath = "/home/ahmedsamir/CLionProjects/Lab 2 M (2)/inputMessage.txt";
string encodedMessagePath = "/home/ahmedsamir/CLionProjects/Lab 2 M (2)/Encoding.txt";
string encoderDictionaryPath = "/home/ahmedsamir/CLionProjects/Lab 2 M (2)/Encoder_Dictionary.txt";
string decoderDictionaryPath = "/home/ahmedsamir/CLionProjects/Lab 2 M (2)/Decoder_Dictionary.txt";
string decodedMessagePath = "/home/ahmedsamir/CLionProjects/Lab 2 M (2)/Decoding.txt";

int main(int argc, const char * argv[]) {
    //Encoder Object
    Encoder encoder;
    //Read Message
    encoder.readMessageFromFile(inputMessagePath);
    //Initialize Dictionary
    encoder.initializeDictionary();
    //Encode Message
    encoder.encodeMessage();
    //Save Encoded Message
    encoder.saveEncodedMessage(encodedMessagePath);
    //Save Encoding Dictionary
    encoder.saveDictionary(encoderDictionaryPath);

    //Decoder Object
    Decoder decoder;
    //Read Message
    decoder.readEncodedMessage(encodedMessagePath);
    //Initialize Dictionary
    decoder.initializeDictionary();
    //Decode Message
    decoder.decodeMessage();
    //Save Decoded Message
    decoder.saveDecodedMeesage(decodedMessagePath);
    //Save Decoding Dictionary
    decoder.saveDictionary(decoderDictionaryPath);

    if( compareEncodedAndDecodedMessages(inputMessagePath, decodedMessagePath))
        cout << "Yes Both are identical " << endl;
    else
        cout << "No they are not identical " << endl;
    return 0;
}
