#include <stdio.h>
#include "linklist.h"

typedef struct node {
    ListDataType value;
    //int value;
    struct node *next;
}node;

 node pHead = {0, NULL};
 node *pNextNode = NULL;

int main() {
    printf("Hello, C Project!\n");

    // Print pHead value
    pHead.value = 10;
    pHead.next = NULL;

    printf("pHead value: %d\n", pHead.value);

    return 0;
}
