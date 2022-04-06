//Animation.h
//@author: Surbhi Bahri

#pragma once

#define MAX_NAME_SIZE 20

#include <iostream>
#include "Frame.h"

using namespace std;

class Animation
{
	int numFrame;
	string animationName;
	Frame* frames;
public:
	Animation();
	~Animation();
	void InsertFrame();
	void EditFrame();
	void DeleteFrame();
	void ReportAnimation();
};
