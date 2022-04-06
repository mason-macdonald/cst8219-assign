#include "Animation.h"

Animation::Animation() {
    numFrame = 0;
    animationName = "Test Animation";
    frames = NULL;
}

Animation::~Animation() {
    Frame *lastPtr, *currentPtr;

    if(numFrame == 0)
        cout << "Blank animation! No cleanup needed." << endl;
    else {
        lastPtr = frames;
        currentPtr = lastPtr->GetpNext();

        delete lastPtr;

        while(currentPtr) {
            lastPtr = currentPtr;
            currentPtr = currentPtr->GetpNext();

            delete lastPtr;
        }
        cout << "Cleanup completed." << endl;
    }
}

void Animation::InsertFrame() {
    char *name;
    Frame *tmp, *currentPtr;

    tmp = new Frame();
    name = tmp->GetFrameName();
    
    while(1) {
        printf("Enter frame name: ");

        if(cin >> name)
            break;
		else {
			cout << "Invalid input!" << endl;
			cin.clear();
			cin.ignore(256, '\n');
		}
    }

    currentPtr = frames;
    if(currentPtr)
        tmp->GetpNext() = currentPtr;
    
    frames = tmp;
    numFrame++;
    
    cout << endl;
}

void Animation::EditFrame() {
    char *name;
    int index, i;
    Frame *currentPtr, *tmp;

    if(numFrame == 0)
        cout << "There's no frame! Cannot edit." << endl;
    else {
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

        name = currentPtr->GetFrameName();

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
    }
    cout << endl;
}

void Animation::DeleteFrame() {
    Frame *lastPtr, *currentPtr;

    if(numFrame == 0)
        printf("There's no frame! Cannot delete.");
    else {
        lastPtr = NULL;
        currentPtr = frames;

        while(currentPtr->GetpNext()) {
            lastPtr = currentPtr;
            currentPtr = currentPtr->GetpNext();
        }

        delete currentPtr;
        numFrame--;

        if(lastPtr)
            lastPtr->GetpNext() = NULL;
        else
            frames = NULL;
    }
    cout << endl;
}

void Animation::ReportAnimation() {
    int id = 1;
    struct Frame *currentPtr;

    cout << "Animation name: " << animationName << endl;
    cout << "Total frame: " << numFrame << "\n" << endl;

    if(numFrame == 0)
        cout << "Blank animation ..." << endl;
    else {
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