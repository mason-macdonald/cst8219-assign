/*
 * Title: part1.cpp
 * Course: CST8219 C++ Programming
 * Term: Winter 2022
 * Authors/Student Names: Mason Macdonald, Maxwell Neil, Thomas Nguyen, Surbhi Bahri
 * Professors: Surbhi Bahri, Kacey Taouch
 * Assessment: Final project part 1
 * Purpose: To build a frame linked list for an animation.
 */

//#define _CRT_SECURE_NO_WARNINGS
//#define _CRTDBG_MAP_ALLOC // need this to get the line identification
//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF|_CRTDBG_LEAK_CHECK_DF); // in main, after local declarations
//NB must be in debug build

#define MAX_NAME_SIZE 30

//#include <crtdbg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum{FALSE = 0, TRUE} BOOL;

struct Frame{
    char *frameName;
    struct Frame *pNext;
};

typedef struct{
    char *animationName;
    struct Frame *frames;
}Animation;

// Forward declarations

void InitAnimation(Animation*);

void InsertFrame(Animation*);

void DeleteFrame(Animation*);

void EditFrame(Animation*);

void ReportAnimation(Animation*);

void CleanUp(Animation*);

int main(void)

{

    char response, junk;
    BOOL RUNNING = TRUE;
    Animation RG;
    //_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    InitAnimation(&RG);

    while (RUNNING)
    {
        printf( "MENU\n1. Insert a Frame at the front\n2. Delete last Frame\n3. Edit a Frame\n4. Report the Animation\n5. Quit\n> ");

        if(scanf("%c%c", &response, &junk) == 2 && junk == '\n') {
            switch (response)
            {
            case '1':InsertFrame(&RG);break;

            case '2':DeleteFrame(&RG);break;

            case '3':EditFrame(&RG);break;

            case '4':ReportAnimation(&RG);break;

            case '5':RUNNING = FALSE;CleanUp(&RG);break;

            default:printf("Please enter a valid option\n\n");
            }
        }
        else {
            printf("Invalid input!\n\n");
            while(getchar() != '\n');
        }
    }

    return 0;
}

void InitAnimation(Animation* ptrAnimation) {
    ptrAnimation->frames = NULL;
    ptrAnimation->animationName = "Test Animation";
}

void InsertFrame(Animation* ptrAnimation) {
    char *name;
    struct Frame *tmp, *currentPtr;

    tmp = (struct Frame*)malloc(sizeof(struct Frame));
    if (NULL == tmp) {
        fprintf(stderr, "Error - could not allocate memory");
        return;
    }
    name = (char*)malloc((MAX_NAME_SIZE + 1) * sizeof(char));
    if (NULL == name) {
        fprintf(stderr, "Error - could not allocate memory");
        return;
    }

    while(1) {
        printf("Enter frame name: ");
        name[0] = '\0';
        scanf("%20[^\n]s", name);
        while (getchar() != '\n');

        if(name[0] == '\0' || strlen(name) > MAX_NAME_SIZE)
            printf("Invalid Input!\n");
        else
            break;
    }

    tmp->frameName = name;

    currentPtr = ptrAnimation->frames;
    tmp->pNext = currentPtr;

    ptrAnimation->frames = tmp;

    printf("\n");
}

void DeleteFrame(Animation* ptrAnimation) {
    struct Frame *lastPtr, *currentPtr;

    if(ptrAnimation->frames) {
        lastPtr = NULL;
        currentPtr = ptrAnimation->frames;

        while(currentPtr->pNext) {
            lastPtr = currentPtr;
            currentPtr = currentPtr->pNext;
        }

        free(currentPtr->frameName);
        free(currentPtr);

        if(lastPtr)
            lastPtr->pNext = NULL;
        else
            ptrAnimation->frames = NULL;
    }
    else
        printf("There's no frame! Cannot delete.\n");
    printf("\n");
}

void EditFrame(Animation* ptrAnimation) {
    char junk, *name;
    int index, i, currentCount;
    struct Frame *currentPtr;

    currentPtr = ptrAnimation->frames;

    if(currentPtr) {
        currentCount = 0;
        while(currentPtr) {
            currentCount++;
            currentPtr = currentPtr->pNext;
        }
        printf("There are %d frames in this animation\n", currentCount);

        while(1) {
            printf("Please enter index of a frame to edit [0-%d]: ", currentCount - 1);

            if(scanf("%d%c", &index, &junk) == 2 && junk == '\n') {
                if(index < currentCount && index >= 0)
                    break;
                else
                    printf("Frame does not exist!\n");
            }
            else {
                printf("Invalid input!\n");
                while(getchar() != '\n');
            }
        }

        i = 0;
        currentPtr = ptrAnimation->frames;
        while(i != index) {
            i++;
            currentPtr = currentPtr->pNext;
        }

        name = currentPtr->frameName;

        while(1) {
            printf("New frame name: ");

            name[0] = '\0';
            scanf("%20[^\n]s", name);
            while (getchar() != '\n');

            if(name[0] == '\0' || strlen(name) > MAX_NAME_SIZE)
                printf("Invalid Input!\n");
            else
                break;
        }
    }
    else
        printf("There's no frame! Cannot edit.\n");
    
    printf("\n");
}

void ReportAnimation(Animation* ptrAnimation) {
    int id = 1, numFrame = 0;
    struct Frame *currentPtr;

    printf("Animation name: %s\n", ptrAnimation->animationName);

    currentPtr = ptrAnimation->frames;
    while(currentPtr) {
        numFrame++;
        currentPtr = currentPtr->pNext;
    }
    printf("Total frame: %d\n\n", numFrame);

    if(ptrAnimation->frames) {
        printf("Start this animation ...\n");

        currentPtr = ptrAnimation->frames;

        while(currentPtr) {
            printf("Image %d, file name: %s\n", id, currentPtr->frameName);
            id++;
            currentPtr = currentPtr->pNext;
        }
    }
    else
        printf("Blank animation ...\n");

    printf("\n");
}

void CleanUp(Animation* ptrAnimation) {
    struct Frame *lastPtr, *currentPtr;

    if(ptrAnimation->frames) {
        lastPtr = ptrAnimation->frames;
        currentPtr = lastPtr->pNext;

        free(lastPtr->frameName);
        free(lastPtr);

        while(currentPtr) {
            lastPtr = currentPtr;
            currentPtr = currentPtr->pNext;

            free(lastPtr->frameName);
            free(lastPtr);
        }

        printf("Cleanup completed.\n");
    }
    else
        printf("Blank animation! No cleanup needed.\n");
}
