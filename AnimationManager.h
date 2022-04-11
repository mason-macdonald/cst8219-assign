/*
 * Title: AnimationManager.h
 * Course: CST8219 C++ Programming
 * Term: Winter 2022
 * Authors/Student Names: Mason Macdonald, Maxwell Neil, Thomas Nguyen
 * Professors: Surbhi Bahri, Kacey Taouch
 * Assessment: Final project part 3
 * Purpose: Class definition for AnimationManager
 */
#pragma once

#include <string>
#include <vector>
#include <iostream>

#include "Animation.h"

class AnimationManager
{
	std::string managerName;
	std::vector<Animation> animations;
public:
	/*
    Parameterized onstructor
    Parameter:
    - string: name of AnimationManager object
    */
	AnimationManager(std::string name) :managerName(name) { }

	/*
    Destructor
    Purpose: delete memory of AnimationManager object and its members
    */
	~AnimationManager();

	/*
	EditAnimation
	Purpose: Select a specic animation using an index and modify this animation
	*/
	void EditAnimation();

	/*
	DeleteAnimation
	Purpose: Delete a specic animation using an index
	*/
	void DeleteAnimation();

	// Add an animation
	friend std::istream& operator>>(std::istream& , AnimationManager&);
	// Output the animations
	friend std::ostream& operator<<(std::ostream& , AnimationManager&);
};
