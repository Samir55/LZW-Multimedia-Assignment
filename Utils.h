//
//  Utils.h
//
//
//  Created by ASamir on 4/29/17.
//  Copyright © 2017 ASamir. All rights reserved.
//
#pragma once
#ifndef Utils_h
#define Utils_h

#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

class FileManipulator{
public:
    string readFromFile(string filePath){
        string symbols;
        
        //Readind from stream
        ifstream file;
        file.open(filePath);
        char output[1000000];
        
        if (file.is_open()) {
            while (file >> output) {

            }
        }
        //See the size of the input for checking
        //cout << "input Message file size" << strlen(output) <<endl;
        
        //put into vector
        for(int i = 0;i < strlen(output); i++){
            symbols.push_back(output[i]);
        }
        
        //close file
        file.close();
        
        return symbols;
    }

    vector<int> integerReadFromFile(string filePath){
        vector<int> symbols;

        //Reading from stream
        ifstream file;
        file.open(filePath);
        int output;

        if (file.is_open()) {
            while (file >> output) {
                symbols.push_back(output);
            }
        }

        //close file
        file.close();

        return symbols;
    }
    
    void writeToFile(string symbols,string filePath){
        //save to file
        ofstream file;
        file.open(filePath);
        for(int i = 0; i < symbols.size(); i++){
            file << symbols[i];

        }
        file << endl;
        file << endl;
        //Close File ;)
        file.close();
    }
    
    void writeToFile(vector<int> symbols,string filePath){
        //save to file
        ofstream file;
        file.open(filePath);
        for(int i = 0; i < symbols.size(); i++){
            file << symbols[i];
            //Separate with space and Must be ignored in reading
            file << " ";
        }
        //Close File ;)
        file.close();
    }
    
    void WriteDictionaryToFile(map<string, int> Dict, string filePath){
        ofstream file;
        file.open(filePath,std::ofstream::out);
        for(std::map<string,int>::iterator it= Dict.begin();it!=Dict.end();it++){
            file<<((pair<string,int>)(*it)).first<<" "<<((pair<string,int>)(*it)).second<<endl;
        }
        file.close();
    }

    void WriteDictionaryToFile(map<int, string> Dict, string filePath){
        ofstream file;
        file.open(filePath,std::ofstream::out);
        for(std::map<int, string>::iterator it= Dict.begin();it!=Dict.end();it++){
            file<<((pair<int, string>)(*it)).first<<" "<<((pair<int, string>)(*it)).second<<endl;
        }
        file.close();
    }
};
#endif /* Utils_h */
