/*
 * Title: Animation.h
 * Course: CST8219 C++ Programming
 * Term: Winter 2022
 * Authors/Student Names: Mason Macdonald, Maxwell Neil, Thomas Nguyen
 * Professors: Surbhi Bahri, Kacey Taouch
 * Assessment: Final project part 2
 * Purpose: Class definition for Animation
 */

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
	/*
	Default constructor
	*/
	Animation();

	/*
	Destructor
	Purpose: delete memory of an Animation object and its members
	*/
	~Animation();

	/*
	InsertFrame
	Purpose: create a new frame and add it to an animation
	*/
	void InsertFrame();

	/*
	InsertFrame
	Purpose: select a frame using an index and edit
	*/
	void EditFrame();

	/*
	InsertFrame
	Purpose: delete a frame using an index and edit
	*/
	void DeleteFrame();

	/*
	InsertFrame
	Purpose: display information of an Animation
	*/
	void ReportAnimation();
};
