/*
 * Title: Frame.h
 * Course: CST8219 C++ Programming
 * Term: Winter 2022
 * Authors/Student Names: Mason Macdonald, Maxwell Neil, Thomas Nguyen
 * Professors: Surbhi Bahri, Kacey Taouch
 * Assessment: Final project part 3
 * Purpose: Class definition for Frame
 */
#pragma once

#include <iostream>
#include <cstring>

class Frame
{
    char* frameName;
    double duration;

    public:
    /*
    Parameterized onstructor
    Parameter:
    - char*: reference to a name
    - double: duration of a frame
    */
    Frame(char*, double);

    /*
    Copy onstructor
    Parameter:
    - Frame&: source Frame where members are copied
    */
    Frame(const Frame&);

    /*
    Destructor
    Purpose: delete memory of object and its members
    */
    ~Frame();

    /*
    Assignment operator for Frame
    Parameter:
    - Frame&: source Frame where members are referenced
    Purpose: assign all member of an object to the same value of another object
    */
    Frame& operator=(const Frame&);

    /*
    Extraction operator for Frame
    Parameter:
    - ostream&: an output stream where information are displayed
    - Frame&: source Frame where members are referenced
    Purpose: Display information about a Frame object
    */
    friend std::ostream& operator << (std::ostream&, Frame&);
};

