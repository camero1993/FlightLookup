//
//  llist.h
//  LList HW
//
//  Created by Magnus Graham on 10/16/23.
//

#ifndef LLIST_H
#define LLIST_H
//#include "flight.h"

typedef struct LLNodetemp LLNode;

typedef struct flightTemp flight;

struct flightTemp {
    char* airline;
    int flightnum;
    int departure;
    int arrival;
};

struct LLNodetemp{
    flight* data;
    LLNode* next;
};


  
//function prototypes
LLNode* insert(LLNode *, LLNode**);
void delete(int, LLNode**);
LLNode* makeNode(void);
LLNode* initNode(LLNode*, char*, char*, char*, char*);
void save(LLNode*, char *);
void printList(LLNode *);
void freeList(LLNode*);

LLNode* loadFile(char*);
void runProg(LLNode*);

#endif /* llist_h */
