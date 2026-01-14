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

/**
 * Given a Linked List of M nodes and a number N, find the value at the Nth node from the end of the Linked List.
 * If there is no Nth node from the end, print -1.
 * Input: 1 -> 2 -> 3 -> 4, N = 3
 * Output: 2
 */
int valatNNode(int num)
{
    node *mainNode = pHeadNode;
    node *refNode = pHeadNode;

    for (int i = 1; i < num; i++)
    {
        refNode = refNode->next; 
        if (refNode == NULL)
        {
            return -1;
        }        
    }

    LOG("INFO", BLUE, "ref node Value %d ", refNode->value);  

    while (refNode->next != NULL)
    {
        mainNode = mainNode->next;
        refNode = refNode->next;
    }

    LOG("INFO", BLUE, "main node Value %d ", mainNode->value);    

}


/**
 * Delete last occurrence of an item from linked list
 * Given a singly linked list and a key, the task is to delete the last occurrence of that key in the linked list.
 */
int delOccuNode(int key)
{
    node *tmpNode = pHeadNode;
    node *refNode = NULL;
    node *delNode = NULL;
    
    while (tmpNode != NULL)
    {
        if(tmpNode->value == key)
        {
            refNode = tmpNode; //Make a ref pointer to tmpNode
        }
        
        if (tmpNode->next != NULL && tmpNode->next->next == NULL)
        {
            delNode = tmpNode->next; //Just to store the previous node value
        }
        tmpNode = tmpNode->next;
    }

    // If no occurrence of key is found
    if (refNode == NULL)
    {
        LOG("INFO", BLUE, "No node found");
        return -1; // Return error code
    }

    if(refNode != NULL)
    {
        if(refNode->next == NULL) //Last node to delete
        {
            if (delNode != NULL)
            {
                delNode->next = NULL; //Use the previous store reference of ref node
            }            
            free(refNode); //Free the last occurence
        }
        else
        {
            delNode = refNode->next;
            key = delNode->value;
            delNode->value = refNode->value;
            refNode->value = key;
            refNode->next = delNode->next;
            free(delNode);
        }
    }
    else
    {
        LOG("INFO", BLUE, "No node found");   
    }
    
}

/**
 * Remove Duplicates from a Sorted Linked List
 * Given a singly linked list. The task is to remove duplicates (nodes with duplicate values) from the given list (if it exists)
 * Note: Try not to use extra space. The nodes are arranged in a sorted way.
 */

 int rmvDupInLL()
 {
    node *pPrevNod = pHeadNode;
    node *pNextNode = NULL;
    node *pDelNode = NULL;

    if (pHeadNode == NULL)
    {
        return 0;
    }
    
    if (pPrevNod->next == NULL)
    {
        return 0;
    }   

    if (pPrevNod != NULL && pPrevNod->next !=NULL)
    {
        pNextNode = pPrevNod->next; 
    }

    while (pNextNode != NULL)
    {
        if (pPrevNod->value == pNextNode->value)
        {
            //Delete the duplicate next node and travese to next packet
            pDelNode = pNextNode;
            pNextNode = pNextNode->next;
            pPrevNod->next = pNextNode;
            free(pDelNode);
        }
        else
        {
            pPrevNod = pPrevNod->next;
            pNextNode = pNextNode->next;
        }
        
    }  
    return 0;
 }

 /**
  * Detect Loop or Cycle in Linked List
  * The slow and fast pointer approach (also called the Tortoise and Hare Algorithm) is an efficient method 
  * used to detect cycles in a linked list.
  * Time Complexity: O(n) (Linear Time)
  * Space Complexity: O(1) (Constant Space)
  * Using Floyd’s Cycle Detection Algorithm – O(n) Time and O(1) Space
  */
 int detLoopInLL()
 {
    node *pSlowPtr = pHeadNode;
    node *pFastPtr = pHeadNode;

    if(pHeadNode == NULL)
    {
        return 0;      
    }
 
    while (pFastPtr != NULL && pFastPtr->next != NULL)
    {
        pFastPtr = pFastPtr->next->next;
        pSlowPtr = pSlowPtr->next;

        //Check for loop exist or not
        if (pSlowPtr == pFastPtr)
        {
            return 1;
        }             
    }
    return 0;  

 }

/**
* Function to detect and remove loop in a linked list that
* may contain loop
*/
int rmvLoopInLL()
{
    node *pFastPtr = pHeadNode;
    node *pSlowPtr = pHeadNode;

    if (pHeadNode == NULL)
    {
        return 0;
    }

    while (pFastPtr != NULL && pFastPtr->next != NULL)
    {
        pFastPtr = pFastPtr->next->next;
        pSlowPtr = pSlowPtr->next;

        //Condition to check for loop in LL
        if(pFastPtr == pSlowPtr)
        {
            /*
            Code to remove the loop in link list
            */
           pSlowPtr = pHeadNode;
           //Loop at the start of the linklist
           if (pSlowPtr == pFastPtr)
           {
             while(pFastPtr->next != pSlowPtr)
             {
                pFastPtr = pFastPtr->next;
             }
           }
           else
           {
            while(pSlowPtr->next != pFastPtr->next)
            {
                pSlowPtr = pSlowPtr->next;
                pFastPtr = pFastPtr->next;
            }

           }          
           pFastPtr->next = NULL;           
           return 1;
        }
    }
    return 0;    
}
