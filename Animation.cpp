#include "Animation.h"

Animation::~Animation() {
    frames.clear();
}

void Animation::EditFrame() {
    int size, index, i;
    std::cout << "Edit frame in " << AnimationName << std::endl;

    if(frames.empty()) {
        std::cout << "Blank animation. Cannot EDIT." << std::endl;
        return;
    }

    size = 0;
    for(auto it = frames.begin(); it != frames.end(); it++) {
        size++;
    }
    std::cout << "Number of frame in this animation: " << size << std::endl;

    while(1) {
        std::cout << "Enter index of the frame you want to edit[0-" << size-1 << "]: ";

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

    // EDIT FRAME OPERATION
}

void Animation::DeleteFrame() {
    int size;
    if(frames.empty())
        std::cout << "Blank animation. CANNOT DELETE." << std::endl;
    else {
        // DELETE LAST FRAME OPERATION
        
        std::cout << "Last frame deleted." << std::endl;
    }
}

std::istream& operator>>(std::istream& in, Animation& anima) {
    int duration;
    std::string name;
    char *copy = new char[MAX_NAME_SIZE+1];

    std::cout << "Insert a new frame" << std::endl;

    while(1) {
        std::cout << "Enter frame name: ";

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
        std::cout << "Enter frame duration: ";

        if(in >> duration)
            break;
        else {
            std::cout << "Invalid input!" << std::endl;
            in.clear();
            in.ignore(256, '\n');
        }
    }

    copy = strcpy(copy, name.c_str());
    Frame *newFr = new Frame(copy, duration);
    anima.frames.push_front(*newFr);

    return in;
}

std::ostream& operator<<(std::ostream& out, Animation& anima) {
    int i = 0;
    out << "Animation name: " << anima.AnimationName << std::endl;

    if(anima.frames.empty())
        out << "Blank animation\n" << std::endl;
    else {
        out << "Start animation" << std::endl;
        for(auto it = anima.frames.begin(); it != anima.frames.end(); it++) {
            out << "Frame " << i << ": " << *it << std::endl;
            i++;
        }
        out << std::endl;
    }
    return out;
}
