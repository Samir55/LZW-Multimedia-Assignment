cmake_minimum_required(VERSION 3.6)
project(Lab_2_M)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        Decoder.cpp
        Decoder.h
        Encoder.cpp
        Encoder.h
        Encoder_Dictionary.txt
        Encoding.txt
        inputMessage.txt
        main.cpp
        Utils.h)

add_executable(Lab_2_M ${SOURCE_FILES})