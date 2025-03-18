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
        LOG("ERR", YELLOW, "Empty Link List");
        return;
    }

    LOG("INFO", YELLOW, "Linked List Contents:");

    while (pTempNode != NULL)
    {
        LOG("INFO", YELLOW, "Node Value %d", pTempNode->value);
        pTempNode = pTempNode->next;
    }     
}

void deleteItemInLL(ListDataType Val)
{
    node *pTempNode = pHeadNode;
    node *pPrevNode = NULL;

    if(pTempNode == NULL)
    {
        LOG("ERROR", RED, "No item in link list to delete ");
        return;
    }
    //Search for the item in LL
    while (pTempNode != NULL)
    {
        //Check for the item to be deleted
        if(pTempNode->value == Val)
        {
            //Check for Head Node
            if(pTempNode == pHeadNode)
            {
                LOG("INFO", BLUE, "Head to be deleted ");
                pHeadNode = pHeadNode->next; 
                free(pTempNode);
                pTempNode = pHeadNode;             
            }
            else
            {
                pPrevNode->next = pTempNode->next;
                LOG("INFO", BLUE, "Node found to be deleted ");
                free(pTempNode);
                pTempNode = pPrevNode->next;;
            }
        }
        else
        {
            pPrevNode = pTempNode;
            pTempNode = pTempNode->next;
        }
    }

    displayItemInLL();    
}

/*
API is used to identify the middle node of the link list.
 */
void findMidleNodeInLL()
{
   node *tempNode = pHeadNode;
   int llLen = 0;
   int lenVal= 0;

   //Check the length of the link list
   while(tempNode != NULL)
   {
      llLen++;
      tempNode = tempNode->next;
   }

   LOG("INFO", BLUE, "Link List length %d ", llLen);

   //To get the middle node
   lenVal = llLen;
   llLen = llLen/2;   

   LOG("INFO", BLUE, "Half Link List length %d ", llLen);

   tempNode = pHeadNode;
   while (llLen)
   {
    tempNode = tempNode->next;
    llLen--;
   }

   //Check for event number
   if (lenVal % 2 == 0)
   {
        LOG("INFO", BLUE, "Middle Node Value for even number list %d ", tempNode->value);
   }
   else
   {
        LOG("INFO", BLUE, "Middle Node Value for odd number linst %d ", tempNode->value);
   }   
}

//Optimize version of finding the middle node of link list
void findMidleNodeInLLOpt()
{
    node *pSlow = pHeadNode;
    node *pFast = pHeadNode;

    while(pFast != NULL && pFast->next != NULL)
    {
        pSlow = pSlow->next;
        pFast = pFast->next->next;
    }

    LOG("INFO", BLUE, "Middle Node Value %d ", pSlow->value);
}

//Reverse a link list
void revInLL()
{
    node *pTail = pHeadNode;
    node *pMiddle = pTail->next;
    node *pTop = pMiddle->next;

    LOG("INFO", BLUE, "Reverse link list");

    if (pTail != NULL)
    {
        pTail->next = NULL; //Make the tail to the last node;
    }

    while (pTop != NULL)
    {
        pMiddle->next = pTail;  //Point to the previous link
        pTail = pMiddle;
        pMiddle = pTop;
        pTop = pTop->next;
    }

    pMiddle->next = pTail;
    pTail = pMiddle;
    pHeadNode = pTail; //Head point to tail    

    displayItemInLL();  
    
}
