// part1.c
//@author: Surbhi Bahri
#define _CRT_SECURE_NO_WARNINGS
#define _CRTDBG_MAP_ALLOC // need this to get the line identification
//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF|_CRTDBG_LEAK_CHECK_DF); // in
//main, after local declarations
//NB must be in debug build
#include <stdlib.h>
#include <crtdbg.h>
#include <stdio.h>
#include <string.h>
typedef enum { FALSE = 0, TRUE } BOOL;
struct Frame {
	char* frameName;
	struct Frame* pNext;
};
typedef struct {
	char* animationName;
	struct Frame* frames;
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
	char response;
	BOOL RUNNING = TRUE;
	Animation RG;
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF |
		_CRTDBG_LEAK_CHECK_DF);
	InitAnimation(&RG);
	printf("OUTSIDE Address of a: %p\n", &RG);
	while (RUNNING)
	{
		printf("MENU\n 1. Insert a Frame at the front\n 2. Delete last Frame\n 3. Edit a Frame\n 4. Report the Animation\n 5. Quit\n");
			scanf("%c", &response);
		switch (response)
		{
		case '1':InsertFrame(&RG); break;
		case '2':DeleteFrame(&RG); break;
		case '3':EditFrame(&RG); break;
		case '4':ReportAnimation(&RG); break;
		case '5':RUNNING = FALSE; CleanUp(&RG); break;
		default:printf("Please enter a valid option\n");
		}
	}
	return 0;
}
//Initializes the passed animation Animation
void InitAnimation(Animation* node) {

    node->animationName = (char *)malloc(sizeof(char) * (10 + 1));
    if (NULL == node->animationName) {
        fprintf(stderr, "Error - could not allocate memory");
        return;
    }
    strcpy(node->animationName, "Animation1");

    node->frames = malloc(sizeof(struct Frame*));
    if (NULL == node->frames) {
        fprintf(stderr, "Error - could not allocate memory");
        return;
    }

    node->frames->pNext = malloc(sizeof(struct Frame*));
    if (NULL == node->frames) {
        fprintf(stderr, "Error - could not allocate memory");
        return;
    }
    node->frames->pNext= NULL;
}
//Asks user for a frame name then adds it at the end of the Animation LL
void InsertFrame(Animation* node) {
    struct Frame* currentFrame = node->frames;

    while (NULL != currentFrame->pNext){
        printf("How many times");
        currentFrame = currentFrame->pNext;
    }

    currentFrame->frameName = (char *)malloc(sizeof(char) * (10 + 1));
    if (NULL == node->animationName) {
        fprintf(stderr, "Error - could not allocate memory");
        return;
    }
    printf("Insert a frame in the animation\nPlease enter the frame name: ");
    /* Allows the user to enter an employee name; allows for spaces */
    getchar();
    scanf("%10[^\n]s", currentFrame->frameName);
    while (getchar() != '\n') { /* Chomps user input */
    }


    currentFrame->pNext = malloc(sizeof(struct Frame*));
    if (NULL == node->frames) {
        fprintf(stderr, "Error - could not allocate memory");
        return;
    }
    node->frames->pNext= NULL;
}
//Initializes the passed animation Animation
void InitAnimation(Animation* node) {

    node->animationName = (char*)malloc(sizeof(char) * (10 + 1));
    if (NULL == node->animationName) {
        fprintf(stderr, "Error - could not allocate memory");
        return;
    }
    strcpy(node->animationName, "Animation1");

    node->frames = malloc(sizeof(struct Frame*));
    if (NULL == node->frames) {
        fprintf(stderr, "Error - could not allocate memory");
        return;
    }

    node->frames->pNext = malloc(sizeof(struct Frame*));
    if (NULL == node->frames) {
        fprintf(stderr, "Error - could not allocate memory");
        return;
    }
    node->frames->pNext = NULL;
}
//Asks user for a frame name then adds it at the end of the Animation LL
void InsertFrame(Animation* node) {
    struct Frame* currentFrame = node->frames;

    while (NULL != currentFrame->pNext) {
        printf("How many times");
        currentFrame = currentFrame->pNext;
    }

    currentFrame->frameName = (char*)malloc(sizeof(char) * (10 + 1));
    if (NULL == node->animationName) {
        fprintf(stderr, "Error - could not allocate memory");
        return;
    }
    printf("Insert a frame in the animation\nPlease enter the frame name: ");
    /* Allows the user to enter an employee name; allows for spaces */
    getchar();
    scanf("%10[^\n]s", currentFrame->frameName);
    while (getchar() != '\n') { /* Chomps user input */
    }


    currentFrame->pNext = malloc(sizeof(struct Frame*));
    if (NULL == node->frames) {
        fprintf(stderr, "Error - could not allocate memory");
        return;
    }
    node->frames->pNext = NULL;
}
//Deletes the last frame in the Animation LL
void DeleteFrame(Animation* node) {

}
//Asks for the index of the frame to change and updates the NAME of the frame based on user input.
void EditFrame(Animation* node) {

}
//Prints animation name and all nodes in order by index. Nodes print index number and name.
void ReportAnimation(Animation* node) {

}
//Releases memory correctly for the Animation LL
void CleanUp(Animation* node) {

}
