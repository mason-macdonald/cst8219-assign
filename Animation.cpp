/*
 * Title: TeamAssignment
 * Course: CST8219 C++
 * Term: Winter 2022
 * Authors/Student Names: Mason Macdonald, Maxwell Neil, Thomas Nguyen
 */
#include "Animation.h"

Animation::~Animation() {
    frames.clear();
}

void Animation::EditFrame() {
    std::string name;
    int size, index, i, duration;
    char *copy = new char[MAX_NAME_SIZE+1];
    
    std::cout << "Edit frame in " << AnimationName << std::endl;

    if(frames.empty()) {
        std::cout << "There are no frames in the animation" << std::endl;
        return;
    }

    size = 0;
    for(auto it = frames.begin(); it != frames.end(); it++) {
        size++;
    }
    
    while(1) {
        std::cout << "There are " << size << " frame(s) in the list . Please specify the index (<=" << size - 1 << ") to edit at: ";

        if(std::cin >> index) {
            if(index >= 0 && index < size)
                break;
            else
                std::cout << "Frame does not exist." << std::endl;
        }
        else {
            std::cout << "Invalid input!" << std::endl;
            std::cin.clear();
            std::cin.ignore(256, '\n');
        }
    }


    auto it = frames.begin();
    for(int i = 0; i < index; i++) {
        it++;
    }

    std::cout << "The name and duration of this frame is " << *it << std::endl;
    std::cout << "What do you wish to replace them with?" << std::endl;

    while(1) {
        std::cout << "Enter frame name: ";

        if(std::cin >> name) {
            if(name.length() <= MAX_NAME_SIZE)
                break;
            else
                std::cout << "Name must be less than " << MAX_NAME_SIZE << " characters." << std::endl;
        }
        else {
            std::cout << "Invalid input!" << std::endl;
            std::cin.clear();
			std::cin.ignore(256, '\n');
        }
    }

    while(1) {
        std::cout << "Enter frame duration: ";

        if(std::cin >> duration)
            break;
        else {
            std::cout << "Invalid input!" << std::endl;
            std::cin.clear();
            std::cin.ignore(256, '\n');
        }
    }

    copy = strcpy(copy, name.c_str());
    Frame tmp(copy, duration);
    *it = tmp;
    std::cout << "Frame #" << index << " edit completed" << std::endl;
}

void Animation::DeleteFrame() {
    int size;
    if(frames.empty())
        std::cout << "There are no frames in the animation" << std::endl;
    else {
        size = 0;
        for(auto it = frames.begin(); it != frames.end(); it++) {
            size++;
        }

        if(size == 1)
            frames.pop_front();
        else {
            auto it = frames.begin();
            for(int i = 1; i < size - 1; i++) {
                it++;
            }
            frames.erase_after(it);
        }

        std::cout << "Last frame deleted." << std::endl;
    }
}

std::istream& operator>>(std::istream& in, Animation& anima) {
    int duration;
    std::string name;
    char *copy = new char[MAX_NAME_SIZE+1];

    std::cout << "Insert a frame in the animation" << std::endl;

    while(1) {
        std::cout << "Please enter the frame name: ";

        if(in >> name) {

            if(name.length() <= MAX_NAME_SIZE)
                break;
            else
                std::cout << "Name must be less than " << MAX_NAME_SIZE << " characters." << std::endl;
        }
        else {
            std::cout << "Invalid input!" << std::endl;
            in.clear();
			in.ignore(256, '\n');
        }
    }

    while(1) {
        std::cout << "Please enter the frame duration: ";

        if(in >> duration)
            break;
        else {
            std::cout << "Invalid input!" << std::endl;
            in.clear();
            in.ignore(256, '\n');
        }
    }

    copy = strcpy(copy, name.c_str());
    Frame newFr(copy, duration);
    anima.frames.push_front(newFr);
    delete[] copy;

    std::cout << "Frame " << name << " added to the front of the frames" << std::endl;

    return in;
}

std::ostream& operator<<(std::ostream& out, Animation& anima) {
    int i = 0;
    out << "Animation name is " << anima.AnimationName << std::endl;
    out << "\tReport the Animation" << std::endl;

    if(anima.frames.empty())
        out << "\tNo frames in the animation" << std::endl;
    else {
        for(auto it = anima.frames.begin(); it != anima.frames.end(); it++) {
            out << "\tFrame " << i << ": " << *it << std::endl;
            i++;
        }
    }
    out << std::endl;   //TODO adds \n while outputting
    return out;
}
