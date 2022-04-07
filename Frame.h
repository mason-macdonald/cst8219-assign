//Frame.h (Part 3)

//@author: Surbhi Bahri

#pragma once

#include <iostream>

class Frame
{
    char* frameName;
    double duration;

    public:
    Frame(char*, double);
    Frame(const Frame&);
    ~Frame();

    Frame& operator=(const Frame&);
    friend std::ostream& operator << (std::ostream&, Frame&);
};

