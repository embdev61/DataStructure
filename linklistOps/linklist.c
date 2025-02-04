#include "stdlib.h"
#include "linklist.h"


node *pHeadNode = NULL;

node * addItemInLL(ListDataType Val)
{
    node *pNewNode = (node *)malloc(sizeof(node));
    if(pNewNode != NULL)
    {
        pNewNode->value = Val;        
    }
    /*Check the empty list and add first node in link list*/
    if (pHeadNode == NULL)
    {
        pNewNode->next = NULL;
        pHeadNode = pNewNode;
    }
    
}

//Insert Item in linked list =
 // Start, End and specific location.

//Deletion Item in linked list
// Start, End and specific location.

//Traversal
//Traverse the linked list to visit each node and perform operations like printing the data.

//Search
//Find a node with a specific value in the linked list.

/*
Advanced Operations
Reverse:

Reverse the order of the nodes in the linked list.

Find Middle:

Find the middle node of the linked list.

Detect Cycle:

Check if the linked list contains a cycle (loop).

Merge:

Merge two linked lists into one.

Remove Duplicates:

Remove duplicate nodes from the linked list.

*/

