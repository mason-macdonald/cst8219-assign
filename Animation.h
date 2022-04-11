/*
 * Title: Animation.h
 * Course: CST8219 C++ Programming
 * Term: Winter 2022
 * Authors/Student Names: Mason Macdonald, Maxwell Neil, Thomas Nguyen
 * Professors: Surbhi Bahri, Kacey Taouch
 * Assessment: Final project part 3
 * Purpose: Class definition for Animation
 */
#pragma once

#include <iostream>
#include <cstring>
#include <forward_list>

#include "Frame.h"

#define MAX_NAME_SIZE 20

class Animation
{
	std::string AnimationName;
	std::forward_list<Frame> frames;
public:
	/*
    Parameterized onstructor
    Parameter:
    - string: name of Animation object
    */
	Animation(std::string name):AnimationName(name) {  }

	/*
    Destructor
    Purpose: delete memory of Animation object and its members
    */
	~Animation();

	/*
	EditAnimation
	Purpose: Select a specic frame using an index and modify this frame
	*/
	void EditFrame();

	/*
	DeleteAnimation
	Purpose: Delete a specic frame using an index
	*/
	void DeleteFrame();

	// Add a frame as in cin>>A;
	friend std::istream& operator>>(std::istream&, Animation&);
	// Output the frames as in cout<<A;
	friend std::ostream& operator<<(std::ostream&, Animation&);
};
