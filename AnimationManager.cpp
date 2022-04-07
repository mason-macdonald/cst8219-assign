#include "AnimationManager.h"

AnimationManager::~AnimationManager() {
    animations.clear();
}

void AnimationManager::EditAnimation() {
    int index, size;
    char response;
    bool running;

    if(animations.empty()) {
        std::cout << "Blank animation manager. Cannot EDIT." << std::endl;
        return;
    }

    while(1) {
        size = animations.size();

        std::cout << "Enter index of the animation you want to edit [0-" << size-1 << "] : ";

        if(std::cin >> index) {
            if(index >= 0 && index < size)
                break;
            else
                std::cout << "Animation does not exist." << std::endl;
        }
        else {
            std::cout << "Animation does not exist." << std::endl;
            std::cin.clear();
            std::cin.ignore(256, '\n');
        }
    }

    running = true;
    while (running) {
        std::cout<<"\nANIMATION MENU\n1. Insert new frame at front\n2. Delete last frame\n3. Edit a frame\n4. Quit\n> ";

        if(std::cin>>response) {
            switch (response) {
            case '1':
                std::cin >> animations[index]; break;
            case '2':
                animations[index].DeleteFrame(); break;
            case '3':
                animations[index].EditFrame(); break;
            case '4':
                running = false; break;
            default:
                std::cout<<"Please enter a valid option"<<std::endl;
            }
            std::cin.clear();
            std::cin.ignore(256, '\n');
        }
    }
}

void AnimationManager::DeleteAnimation() {
    int size, index;

    if(animations.empty())
        std::cout << "Blank animation manager. Cannot DELETE." << std::endl;
    else {
        while(1) {
            size = animations.size();

            std::cout << "Enter index of the animation you want to DELETE [0-" << size-1 << "] : ";

            if(std::cin >> index) {
                if(index >= 0 && index < size)
                    break;
                else
                    std::cout << "Animation does not exist." << std::endl;
            }
            else {
                std::cout << "Animation does not exist." << std::endl;
                std::cin.clear();
                std::cin.ignore(256, '\n');
            }
        }

        std::cout << "Animation #" << index << " deleted." << std::endl;
        animations.erase(animations.begin() + index);
    }
    std::cout << std::endl;
}

std::istream& operator>>(std::istream& in, AnimationManager& mng) {
    std::string name;

    std::cout << "Add new animaton" << std::endl;

    while(1) {
        std::cout << "Enter frame name: ";

        if(in >> name) {
            break;
        }
        else {
            std::cout << "Name must be less than " << MAX_NAME_SIZE << " characters." << std::endl;
            in.clear();
			in.ignore(256, '\n');
        }
    }
    Animation *anima = new Animation(name);
    mng.animations.push_back(*anima);
    std::cout << std::endl;

    return in;
}

std::ostream& operator<<(std::ostream& out, AnimationManager& mng) {
    int i;

    out << "Animation manager: " << mng.managerName << "\n" << std::endl;

    if(mng.animations.empty()) {
        out << "Blank animation manager." << std::endl;
    }
    else {
        i = 0;
        for(auto it = mng.animations.begin(); it != mng.animations.end(); it++) {
            out << "Animation #" << i << std::endl;
            out << *it;
            i++;
        }
    }
    return out;
}
