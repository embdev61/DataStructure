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
  //  findMidleNodeInLLOpt();
    revInLL();
    node *revHead;
    revHead = revInLLRec(pHeadNode);

    LOG("INFO", YELLOW, "Reverse Link List:");

    while (revHead != NULL)
    {
        LOG("INFO", YELLOW, "Node Value %d", revHead->value);
        revHead = revHead->next;
    }  

    LOG("INFO", YELLOW, "END");

    return 0;
}
