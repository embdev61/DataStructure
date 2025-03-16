#ifndef LINK_LIST_H
#define LINK_LIST_H
#include "config.h"

typedef struct node {
    ListDataType value;
    struct node *next;
}node;

void addItemInLL(ListDataType Val);
void displayItemInLL();
void deleteItemInLL(ListDataType Val);

#endif