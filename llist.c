//
//  llist.c
//  LList HW
//
//  Created by Magnus Graham on 10/16/23.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "llist.h"
//#include "flight.h"

//was having issues with segfaults, asked Professor Libby for help on this
LLNode* insert(LLNode* toInsert, LLNode** head) {
  // Base case 1
  if (*head == NULL || toInsert->data->flightnum <= (*head)->data->flightnum) { // if list is empty or toInsert belongs at front
    toInsert->next = *head;
    *head = toInsert;
    return *head;// Return new head
  } else if ((*head)->next == NULL || toInsert->data->flightnum < ((*head)->next)->data->flightnum) { // if flight num < the next node's flightnum
    // Recursive case 1
    // Insert toInsert between *head and (*head)->next
    toInsert->next = (*head)->next;
    (*head)->next = toInsert;
    return *head; //return new head
  }
  else {
    if ((*head)->next == NULL) { //end of list
      (*head)->next = toInsert; //put toInsert at end
      toInsert->next = NULL;
    } else { //If toInsert's flight number is greater than or equal to the next node's flight number
      // Recursive case 2 
      *head = (*head)->next;
      insert(toInsert, head);//call on next in the list
    }
    return *head; //return head of the list
  }
}





//was stuck on this one, used chatgpt for ideas on how to fix segfault
void delete(int flightnum, LLNode **head) {
  if (*head == NULL) { //base case 1, list is empty
    printf("Could not find flight %d\n",flightnum); 
    return;
  }
  if ((*head)->data->flightnum == flightnum) {
    printf("Deleting flight %d\n",flightnum);
    LLNode* temp = *head;
    *head = (*head)->next;
    free(temp); // Delete the node
    return;
  }
    
  delete(flightnum, &((*head)->next)); //call on next node
    
}


LLNode* makeNode(void){
    LLNode * ret = (LLNode * )malloc(sizeof(LLNode));
    if(ret!=NULL){
      ret->data = (flight *)malloc(sizeof(flight));
      if (ret->data!=NULL){
	ret->data->airline = (char*)malloc(sizeof(char) * 3);
	ret->data->arrival = -1;
	ret->data->departure = -1;
	ret->data->departure = -1;
	ret->next = NULL;   //initialize all fields to empty values
      }
    }
    else{
      printf("Issue mallocing node!\n");
    }
    
    return ret;
}

void save(LLNode* head, char *filename) {
    LLNode* temp = head;
    FILE* savefile = fopen(filename, "w"); // Use "w" to create file
    if (savefile == NULL) { //check if successful
        printf("Error writing to file");
        return; 
    }

    while (temp != NULL) {
        fprintf(savefile, "%s %d %d %d\n", temp->data->airline, temp->data->flightnum, temp->data->departure, temp->data->arrival);
        temp = temp->next;//copy to file
    }

    fclose(savefile); // Close file
}



void printList(LLNode * head){
  if(head == NULL){
    return;
  }
  printf("Airline: %s\t Flight number: %d\t Departure: %d\t Arrival: %d\n",head->data->airline, head->data->flightnum,head->data->departure,head->data->arrival);

  printList(head->next); //recursively call on next node

}

LLNode* initNode(LLNode* Node, char* Fairline, char* Fnumber, char* Fdepart, char* Farrive){
  //function to insert data into node
  strcpy(Node->data->airline,Fairline);
  
  Node->data->flightnum = atoi(Fnumber);
  Node->data->departure = atoi(Fdepart);
  Node->data->arrival = atoi(Farrive);
  return Node;
}

void freeList(LLNode* list) {
  //free list nodes
  LLNode* curr = list;
    int i = 0;
  
    while (curr != NULL) {
        LLNode* aux = curr;
        curr = curr->next;
        free(aux);
        i++;
    }
}

