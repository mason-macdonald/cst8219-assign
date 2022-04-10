#include "AnimationManager.h"

AnimationManager::~AnimationManager() {
    animations.clear();
}

void AnimationManager::EditAnimation() {
    int index, size;
    char response;
    bool running;

    if(animations.empty()) {
        std::cout << "There are no animations in the animation manager\n" << std::endl;
        return;
    }

    while(1) {
        size = animations.size();

        std::cout << "Which animation do you wish to edit? Please provide the index from (from 0 to " << size-1 << ") : ";

        if(std::cin >> index) {
            std::cin.clear();
            if (index >= 0 && index < size) {
                std::cout << "Editing Animation #" << index << std::endl;
                break;
            }
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
        std::cout<<"\nANIMATION MENU\n1. Insert a Frame at the front\n2. Delete last Frame\n3. Edit a Frame\n4. Quit\n\nSelected option: ";
        if(std::cin>>response) {
            std::cin.clear();
            switch (response) {
            case '1':
                std::cin >> animations[index]; break;
            case '2':
                animations[index].DeleteFrame(); break;
            case '3':
                animations[index].EditFrame(); break;
            case '4':
                running = false;
                std::cout << "Animation #" << index << " edit completed\n" << std::endl; break;
            default:
                std::cout<<"Please enter a valid option"<<std::endl;
            }
            std::cin.clear();
        }
    }
}

void AnimationManager::DeleteAnimation() {
    int size, index;

    if(animations.empty())
        std::cout << "There are no animations in the animation manager" << std::endl;
    else {

        while(1) {
            size = animations.size();

            std::cout << "Delete an animation from the animation manager" << std::endl;
            std::cout << "Which animation do you wish to delete? Please give the index in the range 0 to " << size-1 << ": ";

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

    std::cout << "Add an animaton to the animation manager" << std::endl;

    while(1) {
        std::cout << "Please enter the animation name: ";

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
    std::cout << "Animation entitled " << name << " added to the back of the animations\n" << std::endl;

    return in;
}

std::ostream& operator<<(std::ostream& out, AnimationManager& mng) {
    int i;

    out << "Animation manager: " << mng.managerName << std::endl;

    if(mng.animations.empty()) {
        out << "Blank animation manager.\n" << std::endl;
    }
    else {
        i = 0;
        for(auto it = mng.animations.begin(); it != mng.animations.end(); it++) {
            out << "Animation: " << i << std::endl;
            out << "\t" << * it;
            i++;
        }
    }
    return out;
}
