#include "Animation.h"

Animation::Animation() {
    animationName = "Test Animation";
    frames = NULL;
}

Animation::~Animation() {
    Frame *lastPtr, *currentPtr;

    if(!frames)
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
    tmp->GetpNext() = currentPtr;
    
    frames = tmp;
    
    cout << endl;
}

void Animation::EditFrame() {
    char *name;
    int index, i, numFrame = 0;
    Frame *currentPtr, *tmp;
    if(!frames)
        cout << "There's no frame! Cannot edit." << endl;
    else {
        currentPtr = frames;
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

    if(!frames)
        printf("There's no frame! Cannot delete.");
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

    if(!frames)
        cout << "Blank animation ..." << endl;
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