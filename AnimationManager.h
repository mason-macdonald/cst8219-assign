// AnimationManager.h
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
	AnimationManager(std::string name) :managerName(name) { }
	~AnimationManager();
	void EditAnimation();
	void DeleteAnimation();
	// Add an animation
	friend std::istream& operator>>(std::istream& , AnimationManager&);
	// Output the animations
	friend std::ostream& operator<<(std::ostream& , AnimationManager&);
};
