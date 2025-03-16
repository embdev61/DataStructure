#include <stdio.h>
#include "stdlib.h"
#include "linklist.h"

node *pHeadNode = NULL;

void addItemInLL(ListDataType Val)
{
    node *pNewNode = (node *) malloc(sizeof(node));

    if(pNewNode == NULL)
    {
        LOG("ERROR", RED, "Memory allocation failed for value %d", Val);
        return;
    }

    //Intialize the value and next pointer of newly added node
    pNewNode->value = Val;
    pNewNode->next = NULL;

    LOG("INFO", BLUE, "Add Item %d in link list.", Val);

    //Check for LL is empty or not
    if(pHeadNode == NULL)
    {
        pHeadNode = pNewNode;
        LOG("INFO", BLUE, "Head Node Value %d ", pHeadNode->value);
        return;
    }

    //Traverse to end of the node and add item in LL
    node *pTempNode = pHeadNode;
    while (pTempNode->next != NULL)
    {
        pTempNode = pTempNode->next;
    }

    pTempNode->next = pNewNode;   
    pTempNode = pTempNode->next;
    LOG("INFO", BLUE, "TempNode Value %d ", pTempNode->value);
}

void displayItemInLL()
{
    node *pTempNode = pHeadNode; 
    if(pTempNode == NULL)
    {
        LOG("INFO", YELLOW, "Empty Link List");
        return;
    }

    LOG("INFO", YELLOW, "Linked List Contents:");

    while (pTempNode != NULL)
    {
        LOG("INFO", YELLOW, "Node Value %d", pTempNode->value);
        pTempNode = pTempNode->next;
    }     
}
