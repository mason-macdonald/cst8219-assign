//Animation.h
//@author: Surbhi Bahri

#pragma once

#include <iostream>
#include <cstring>
#include "Frame.h"

using namespace std;

class Animation
{
	char* animationName;
	Frame* frames;
public:
	Animation();
	~Animation();
	void InsertFrame();
	void EditFrame();
	void DeleteFrame();
	void ReportAnimation();
};
