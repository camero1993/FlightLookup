//
//  main.c
//  LList HW
//
//  Created by Magnus Graham on 10/16/23.
//

#include <stdio.h>
#include "flight.h"
#include "llist.h"

int main(int argc, char * argv[]) {
  //initialize llist
  //pass list and file into loadfile along with
  //run runprog with list
  LLNode* list = NULL;
  if(argc == 2) {
    list = loadFile(argv[1]);
  }
  else if (argc > 2) {
    printf("Please use format \"./flight\" or \"./flight [filename]\"\n");
  }
  
  runProg(list);
  
  return 0;
}
