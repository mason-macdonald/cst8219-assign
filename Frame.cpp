#include "Frame.h"

Frame::Frame(char* name, double time) {
    duration = time;
    frameName = new char[21];
    frameName = strcpy(frameName, name);
}

Frame::Frame(const Frame& src) : Frame(src.frameName, src.duration) {
}

Frame::~Frame() {
    delete frameName;
}

Frame& Frame::operator=(const Frame &src) {
    strcpy(frameName, src.frameName);
    duration = src.duration;

    return *this;
}

std::ostream& operator << (std::ostream& out, Frame& fr) {
    out << "Frame Name=" << fr.frameName << "; duration=" << fr.duration;

    return out;
}
