#include "Animation.h"

Animation::Animation() {
    animationName = new char[15];
    strcpy(animationName, "Test Animation");
    frames = NULL;
}

Animation::~Animation() {
    Frame *lastPtr, *currentPtr;
    delete animationName;

    if (!frames) {
        cout << "Blank animation! No cleanup needed." << endl;
        return;
    }
    else {
        lastPtr = frames;
        currentPtr = lastPtr->GetpNext();

        delete lastPtr;
        //Loops through all the LL deleting the last node.
        while(currentPtr) {
            lastPtr = currentPtr;
            currentPtr = currentPtr->GetpNext();

            delete lastPtr;
        }
        cout << "Cleanup completed." << endl;
    }
}

void Animation::InsertFrame() {
    string name;
    Frame *tmp, *currentPtr;
    int length;

    tmp = new Frame();
    
    while(1) {
        printf("Enter frame name: ");
        //cant use cin.getline() because of the while (cin.get() != '\n'); in part2.cpp
        if(cin >> name)
            break;
		else {
			cout << "Invalid input!" << endl;
			cin.clear();
			cin.ignore(256, '\n');
		}
    }
    currentPtr = frames;
    tmp->GetpNext() = currentPtr;

    //Tags a null terminator to the the end of the string after copying it into the char*
    length = MAX_NAME_SIZE <= name.length() ? MAX_NAME_SIZE : name.length();
    name.copy(tmp->GetFrameName(), length);
    tmp->GetFrameName()[length] = '\0';

    frames = tmp;
    cout << endl;
}

void Animation::EditFrame() {
    string name;
    int index, i, numFrame = 0, length;
    Frame *currentPtr, *tmp;
    if (!frames) {
        cout << "There's no frame! Cannot edit." << endl;
        return;
    }
    else {
        currentPtr = frames;
        //Counts the total num of Frames in LL
        while (currentPtr) {
            currentPtr = currentPtr->GetpNext();
            numFrame++;
        }
        cout << "There are " << numFrame << " frames in this animation." << endl;

        while(1) {
            printf("Please enter index of a frame to edit: ");
            
            if(cin >> index) {
                if(index <= numFrame && index > 0)
                    break;
                else
                    printf("Frame does not exist!\n");
            }
            else {
                printf("Invalid input!\n");
                cin.clear();
			    cin.ignore(256, '\n');
            }
        }

        i = 1;
        currentPtr = frames;
        while(i != index) {
            i++;
            currentPtr = currentPtr->GetpNext();
        }

        while(1) {
            printf("New frame name: ");

            if(cin >> name)
                break;
            else {
                cout << "Invalid input!" << endl;
                cin.clear();
                cin.ignore(256, '\n');
            }
        }
        length = MAX_NAME_SIZE <= name.length() ? MAX_NAME_SIZE : name.length();
        name.copy(currentPtr->GetFrameName(), length);
        currentPtr->GetFrameName()[length] = '\0';
    }
    cout << endl;
}

void Animation::DeleteFrame() {
    Frame *lastPtr, *currentPtr;

    if (!frames) {
        printf("There's no frame! Cannot delete.");
        return;
    }
    else {
        lastPtr = NULL;
        currentPtr = frames;

        while(currentPtr->GetpNext()) {
            lastPtr = currentPtr;
            currentPtr = currentPtr->GetpNext();
        }

        delete currentPtr;

        if(lastPtr)
            lastPtr->GetpNext() = NULL;
        else
            frames = NULL;
    }
    cout << endl;
}

void Animation::ReportAnimation() {
    int id = 1, numFrame = 0;
    struct Frame *currentPtr;

    if (!frames) {
        cout << "Blank animation ..." << endl;
        return;
    }
    else {
        currentPtr = frames;
        while (currentPtr) {
            currentPtr = currentPtr->GetpNext();
            numFrame++;
        }
        cout << "Animation name: " << animationName << endl;
        cout << "Total frame: " << numFrame << "\n" << endl;
        cout << "Start this animation ..." << endl;

        currentPtr = frames;

        while(currentPtr) {
            cout << "Image " << id << ", file name: " << currentPtr->GetFrameName() << endl;
            id++;
            currentPtr = currentPtr->GetpNext();
        }
    }
    cout << endl;
}