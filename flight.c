//
//  flight.c
//  LList HW
//
//  Created by Magnus Graham on 10/16/23.
//
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

//#include "flight.h"
#include "llist.h"

void runProg(LLNode* list) {
    char action;
    char arg2[16]; // hold argument

    char airline[3];
  char Fnumber[5];
  char Farrive[5];
  char Fdepart[5];

    while (1) {
        printf("Enter action: a, d, s, p, or q\n");

        scanf("%c", &action);

        if (action == 'a') {
            
	  printf("To add, please use syntax '[airline] [flight#] [departure time] [arrival time]'\n");
	  scanf("%2s %4s %4s %4s",airline,Fnumber,Fdepart,Farrive);
	
	  LLNode* new_node = makeNode(); // Corrected variable name
	  new_node = initNode(new_node, arg2, Fnumber, Fdepart, Farrive);
	  insert(new_node, &list);
	  printList(list);
	}
	else if (action == 'd') {
	  printf("Enter the number of the flight to be deleted\n");
	  scanf("%s",Fnumber);
	  delete(atoi(Fnumber), &list);
	  printList(list);
	} else if (action == 's') {
	  printf("Enter a filename to save list\n");
	  scanf("%s",arg2);
	  save(list, arg2);
	} else if (action == 'p') {
	  printList(list);
	} else if (action == 'q') {
	  if(list!= NULL){
	    freeList(list);
	  }
	  break;
	} else {
	  printf("Invalid input: Please use the commands a, d, s, p, or q\n");
    }
}

    printf("Program terminated.\n");
}


LLNode* loadFile(char* input) {
  printf("Entering loadFile\n");
  FILE* inputfile = fopen(input, "r"); //open file specified
  if (inputfile == NULL) {
    printf("Error loading file\n");
    return NULL;
  }
  LLNode** headPtr = NULL;
  LLNode* head = NULL;
  LLNode** currPtr = NULL;
  LLNode* currNode = NULL;
  
  
  char airline[3];
  //int Fnumber, Farrive, Fdepart;
  char Fnumber[5];
  char Farrive[5];
  char Fdepart[5];
  
  //iterate through file
  int i = 0; // Declare i as a toggle
  while (fscanf(inputfile, "%2s %4s %4s %4s", airline, Fnumber, Fdepart, Farrive) == 4) {
    printf("%s %s %s %s\n", airline, Fnumber, Fdepart, Farrive);
    currNode = makeNode();
    currPtr = &currNode;
    
    if(currNode != NULL){
      currNode = initNode(currNode, airline, Fnumber, Farrive, Fdepart);
 
      if(i==0){ //only run on first iteration
	headPtr = &currNode; // make the first node the head
	i++;
      }
      
      head = insert(currNode,headPtr);
      headPtr = &head;
    }
  }
  printf("File read complete\n");
  fclose(inputfile);
  return *headPtr;
}





