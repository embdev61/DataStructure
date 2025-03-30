#ifndef LINK_LIST_H
#define LINK_LIST_H
#include "config.h"

typedef struct node {
    ListDataType value;
    struct node *next;
}node;

//Declare extern so that can be used in main file
extern node *pHeadNode;

void addItemInLL(ListDataType Val);
void displayItemInLL();
void deleteItemInLL(ListDataType Val);
void findMidleNodeInLL();
void findMidleNodeInLLOpt();
void revInLL();
node * revInLLRec(node *revNode);
node * rotateLLByK(int pos);
int valatNNode(int num);
int delOccuNode(int key);
int rmvDupInLL();
int detLoopInLL();

#endif