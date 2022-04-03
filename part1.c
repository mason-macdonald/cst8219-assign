// part1.c
//@author: Surbhi Bahri
//@Edited/finished By: Maxwell Neil
#define _CRT_SECURE_NO_WARNINGS
#define _CRTDBG_MAP_ALLOC // need this to get the line identification
//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF|_CRTDBG_LEAK_CHECK_DF); // in main, after local declarations
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
    node->frames->frameName = (char *)malloc(sizeof(char) * (10 + 1));
    if (NULL == node->animationName) {
        fprintf(stderr, "Error - could not allocate memory");
        return;
    }
    node->frames->pNext= NULL;
}
//Asks user for a frame name then adds it at the end of the Animation LL
void InsertFrame(Animation* node) {
    while (getchar() != '\n') { /* Chomps user input */
    }
    struct Frame* currentFrame = node->frames;

    while (NULL != currentFrame->pNext){
        printf("How many times");
        currentFrame = currentFrame->pNext;
    }

    currentFrame->pNext = malloc(sizeof(struct Frame*));
    if (NULL == node->frames) {
        fprintf(stderr, "Error - could not allocate memory");
        return;
    }
    currentFrame->pNext->pNext= NULL;
    currentFrame->pNext->frameName = (char *)malloc(sizeof(char) * (10 + 1));
    if (NULL == node->animationName) {
        fprintf(stderr, "Error - could not allocate memory");
        return;
    }
    printf("Insert a frame in the animation\nPlease enter the frame name: ");
    /* Allows the user to enter an employee name; allows for spaces */

    scanf("%10[^\n]s", currentFrame->frameName);
    while (getchar() != '\n') { /* Chomps user input */
    }
    printf("\n");
}


//Deletes the last frame in the Animation LL
void DeleteFrame(Animation* node) {
    while (getchar() != '\n') { /* Chomps user input */
    }
    struct Frame* currentNode = node->frames;
    if (NULL == currentNode->pNext){
        printf("There are no frames to delete. Returning to main menu\n\n");
        return;
    }
    while (NULL!= currentNode->pNext->pNext){
        currentNode= currentNode->pNext;
    }

    free(currentNode->pNext->frameName);
    free(currentNode->pNext);
    currentNode->pNext = NULL;
    printf("Deleted the last frame.\n\n");
}
//Asks for the index of the frame to change and updates the NAME of the frame based on user input.
void EditFrame(Animation* node) {
    while (getchar() != '\n') { /* Chomps user input */
    }
    struct Frame* currentNode = node->frames;
    int count = 0;
    int userchoice;
    while(NULL != currentNode->pNext){
        currentNode = currentNode->pNext;
        count++;
    }

    if(count<=0){
        printf("There are no frames to edit. Returning to main menu\n\n");
        return;
    }
    printf("Edit a frame in the animation\nThere are %d frames in the list. Please specify the index (<=%d) to edit at:\n",count,count-1);
    scanf("%d", &userchoice);
    while (getchar() != '\n') { /* Chomps user input */
    }
    if(userchoice>=count || userchoice<0){
        printf("User choice: %d was out of allowed range. Returning to main menu.\n\n",userchoice);
        return;
    }
    count =0;
    currentNode = node->frames;
    while(userchoice!=count){
        currentNode = currentNode->pNext;
    }
    printf("The name of this frame is %s\n",currentNode->frameName);
    printf("What do you wish to replace it with?\n",currentNode->frameName);

    scanf("%10[^\n]s", currentNode->frameName);
    while (getchar() != '\n') { /* Chomps user input */
    }

    printf("\n\n");
}

//Prints animation name and all nodes in order by index. Nodes print index number and name.
void ReportAnimation(Animation* node) {
    while (getchar() != '\n') { /* Chomps user input */
    }
    struct Frame* currentNode = node->frames;
    int counter = 0;
    printf("\nAnimation Name is: %s\n", node->animationName);
    printf("Report the animation\n");
    while(NULL != currentNode->pNext){
        printf("Image #%d, file name= %s\n", counter, currentNode->frameName);
        currentNode= currentNode->pNext;
        counter++;
    }
    printf("\n");
}
//Releases memory correctly for the Animation LL
void CleanUp(Animation* node) {
    while (getchar() != '\n') { /* Chomps user input */
    }
    //It should be mentioned to solve this nicely i would wanted to write a method to preform recursive freeing of the memory.
    //It should also be mentioned there are many much nicer ways to solve this but most(if not all) require changing outside of the allowed methods
    //thus i am not allowed to do it and decided to settle for this (essentially brute force) method.
    struct Frame* currentNode = node->frames;

    int count = 0;
    int totalFrames;
    //Find the number of frames to delete
    while(NULL != currentNode->pNext){
        currentNode = currentNode->pNext;
        count++;
    }
    totalFrames=count;
    //Count to the second from end then delete the end. Subtract from the number of frames remaining (totalFrames)
    //(deletes all frames except the first)
    while (totalFrames>0){
        count=1;
        currentNode = node->frames;
        while (count<totalFrames){
            currentNode = currentNode->pNext;
            count++;
        }
        //2 Frees for each still existing frame. (delete frees the memory from one add)
        free(currentNode->pNext->frameName);
        free(currentNode->pNext);
        totalFrames--;
    }
    //Free the first frame and animation string
    //3 Frees for the 3 malloc in Init
    free(node->frames->frameName);
    free(node->frames);
    free(node->animationName);
}
