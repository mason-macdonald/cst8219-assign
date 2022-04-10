#include "Frame.h"

Frame::Frame(char* name, double time) {
    duration = time;
    frameName = new char[21];
    frameName = strcpy(frameName, name);
    std::cout << "Frame Name=" << name << "; duration=" << time << "; ADRESS: " << &frameName <<  " ;Does anyone know why this runs twice\n";

}

Frame::Frame(const Frame& src) : Frame(src.frameName, src.duration) {
}

Frame::~Frame() {
    std::cout << "Frame Name=" << this->frameName << "; duration=" << this->duration << "; ADRESS: " << &this->frameName << "\n";
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
