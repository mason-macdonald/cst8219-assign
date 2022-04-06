#include "Frame.h"

Frame::Frame() {
    frameName = new char[MAX_NAME_SIZE+1];
}

Frame::~Frame() {
    delete frameName;
}