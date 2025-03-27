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

    /*
    Time Complexity: O(n) (Single traversal)
    Space Complexity: O(1) (No extra memory used)
    */
}

//Reverse a link list
/**
 *  It has a time complexity of O(n), where n is the number of nodes in the list, as it iterates through the list once.
 *  The space complexity is O(1) as it uses a constant amount of extra space for the pointers.
 */
void revInLL()
{
    node *pPrev = NULL;
    node *pCur = pHeadNode;
    node *pNext = NULL;

    if(pCur == NULL || pCur->next == NULL)
    {
        LOG("INFO", BLUE, "No need for reversing a link list");
        return;
    }

    LOG("INFO", BLUE, "Reverse link list");

    while(pCur != NULL)
    {
        pNext = pCur->next;
        pCur->next = pPrev;
        pPrev = pCur;
        pCur = pNext;
    }
    pHeadNode = pPrev; 
    displayItemInLL();      
}

/**
 * Reverse link list using recursive function
 * Time compleO(n) Time and O(n) Space
 */
node * revInLLRec(node *revNode)
{
    if(revNode == NULL || revNode->next == NULL)
    {
        return revNode;
    }

    node * llNode = revInLLRec(revNode->next);

    revNode->next->next = revNode;
    revNode->next = NULL;
    return llNode;
}

/**
 * Rotate a link list
 * Given a singly linked list and an integer k, the task is to rotate the linked list to the left by k places.
 */
node * rotateLLByK(int pos)
{
    int lenLL = 1;
    int travLL = 0;
    node *lastNode  = pHeadNode;

    if (pHeadNode == NULL || pos < 0)
    {
        LOG("INFO", BLUE, "Error: Invalid position value or empty list");
        return pHeadNode;
    }

    //Check the position value is correct or wrong
    if(pos > 0)
    {
        LOG("INFO", BLUE, "Position Value %d ", pos);
        //Check the length of the link list
        while (lastNode ->next)
        {
            lenLL++;
            lastNode  = lastNode ->next;
        }

        pos = pos % lenLL;
        
        LOG("INFO", BLUE, "travLL Value %d ", pos);

        //Position is same to linked list length so no change
        if (pos == 0)
        {
            LOG("INFO", BLUE, "No travese required");
            return (node *) pHeadNode;
        }

        //Rebase the temp node pointer value
        node *temp = pHeadNode;        
        
        for (int i = 1; i < pos; i++)
        {
           temp = temp->next;
        }
 
        node *newHead = temp->next;
        temp->next = NULL;
        lastNode->next = pHeadNode;

        return newHead;  
    }
    else
    {
        LOG("ERROR", RED, "Wrong position value");        
    }   
    return pHeadNode;    
}
