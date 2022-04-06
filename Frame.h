//Frame.h
//@author: Surbhi Bahri

#pragma once

#define MAX_NAME_SIZE 20

class Frame {
	char* frameName;
	Frame* pNext;
public:
	Frame();
	~Frame();
	bool setName(char *name);
	bool setNext(Frame *next);
	char*& GetFrameName() { return frameName; }
	Frame*& GetpNext() { return pNext; }
};
