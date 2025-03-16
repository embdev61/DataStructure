#include <stdio.h>
#include "stdlib.h"
#include "linklist.h"

node *pHeadNode = NULL;

void addItemInLL(ListDataType Val)
{
    node *pNewNode = (node *)malloc(sizeof(node));
    node *pTempNode = pHeadNode;

    LOG("INFO", BLUE, "Add Item %d in link list.", Val);

    if(pNewNode != NULL)
    {   
        pNewNode->value = Val; 
        pNewNode->next = NULL;       
    }
    /*Check the empty list and add first node in link list*/
    if (pHeadNode == NULL)
    {
        LOG("INFO", BLUE, "Add First Node into link list");
        pHeadNode = pNewNode;        
        LOG("INFO", BLUE, "HeadpNode Value %d ", pHeadNode->value);
    }
    else
    {
        while(pTempNode->next != NULL)
        {
            pTempNode = pTempNode->next;
        }
        pTempNode->next = pNewNode;
        pTempNode = pTempNode->next;
        LOG("INFO", BLUE, "TempNode Value %d ", pTempNode->value);
    }
}

void displayItemInLL()
{
    node *pTempNode = pHeadNode; 
    if(pTempNode == NULL)
    {
        LOG("INFO", YELLOW, "Empty Link List");
        return;
    }
    else
    {
        while (pTempNode->next != NULL)
        {
            LOG("INFO", YELLOW, "Node Value %d", pTempNode->value);
            pTempNode = pTempNode->next;
        }    
        
        if (pTempNode->next == NULL)
        {
            LOG("INFO", YELLOW, "Node Value %d", pTempNode->value);
        }
        
    }    
}
