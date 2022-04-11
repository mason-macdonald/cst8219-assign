/*
 * Title: part3.cpp
 * Course: CST8219 C++ Programming
 * Term: Winter 2022
 * Authors/Student Names: Mason Macdonald, Maxwell Neil, Thomas Nguyen
 * Professors: Surbhi Bahri, Kacey Taouch
 * Assessment: Final project part 3
 * Purpose: Test all functions of AnimationManager
 */

//#define _CRT_SECURE_NO_WARNINGS

//#define _CRTDBG_MAP_ALLOC // need this to get the line identification

//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF|_CRTDBG_LEAK_CHECK_DF);

// in main, after local declarations

//NB must be in debug build #include <crtdbg.h> #include <iostream> #include <string>

#include <vector>
#include <forward_list>

using namespace std;

#include "Frame.h"
#include "Animation.h"
#include "AnimationManager.h"

int main(void) {
    char response;
    bool RUNNING = true;
    AnimationManager M("Manager1");

    //_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF |

    //_CRTDBG_LEAK_CHECK_DF);

    while (RUNNING) {
        cout<<"MENU\n1. Add an Animation\n2. Delete an Animation\n3. Edit an Animation\n4. List the Animations\n5. Quit\n\nSelected Option: ";

        if(cin>>response) {
            switch (response) {
            case '1':cin >> M; break;
            case '2':M.DeleteAnimation(); break;
            case '3':M.EditAnimation(); break;
            case '4':cout << M; break;
            case '5':RUNNING = false; break;
            default:cout<<"Please enter a valid option"<<endl;
            }
            while(cin.get() != '\n');
        }
        else {
            cout << "Invalid input" << endl;
            cin.clear();
			cin.ignore(256, '\n');
        }
    }
    return 0;
}
