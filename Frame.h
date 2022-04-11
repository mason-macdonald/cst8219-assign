/*
 * Title: Frame.h
 * Course: CST8219 C++ Programming
 * Term: Winter 2022
 * Authors/Student Names: Mason Macdonald, Maxwell Neil, Thomas Nguyen
 * Professors: Surbhi Bahri, Kacey Taouch
 * Assessment: Final project part 2
 * Purpose: Class definition for Frame
 */


#pragma once

#define MAX_NAME_SIZE 20

class Frame {
	char* frameName;
	Frame* pNext;
public:
	/*
	Default constructor
	*/
	Frame();

	/*
	Destructor
	Purpose: delete memory of a Frame object and its members
	*/
	~Frame();

	/*
	GetFrameName
	Return: reference to name of a frame
	Purpose: get name of a frame
	*/
	char*& GetFrameName() { return frameName; }

	/*
	GetpNext
	Return: reference to the next frame
	Purpose: get reference to the next frame
	*/
	Frame*& GetpNext() { return pNext; }
};
