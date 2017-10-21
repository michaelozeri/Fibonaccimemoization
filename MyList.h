/*
 * MyList.h
 *
 *  Created on: 21 срхїз 2017
 *      Author: michael
 */

#ifndef MYLIST_H_
#define MYLIST_H_

#include "MyNode.h"

typedef struct my_list_t MyList;

MyList* InitList();

bool IsEmpty(MyList* list);

int InsertNewNode(MyList* list,long val,int index);

int PopLast(MyList* list);

int DestroyList(MyList* list);

void PrintList(MyList* list);

MyNode* GetNodeByIndex(MyList* list,int dex);

bool IsExists(MyList* list,int dex);

#endif /* MYLIST_H_ */
