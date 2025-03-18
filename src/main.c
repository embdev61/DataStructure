#include <stdio.h>
#include "linklist.h"

int main() {

    LOG("INFO", BLUE, "Hello, C Project!"); 
   
    addItemInLL(10);
    addItemInLL(15);
    addItemInLL(20);
    addItemInLL(25);
    addItemInLL(30);
    addItemInLL(35);
    displayItemInLL();
   // deleteItemInLL(15);
   // displayItemInLL();
    //findMidleNodeInLL();
    findMidleNodeInLLOpt();
    return 0;
}
