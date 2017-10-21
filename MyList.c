/*
 * MyList.c
 *
 *  Created on: 21 áàå÷× 2017
 *      Author: michael
 */

#include "MyList.h"


typedef struct my_list_t{
	int length;
	MyNode* head;
	MyNode* last;
}MyList;

MyList* InitList(){
	MyList* list = (MyList*)malloc(sizeof(MyList));
	list->head = InitNode(0,0);
	list->head->previous = NULL;
	list->last = list->head;
	list->length = 0;
	return list;
}

bool IsEmpty(MyList* list){
	if(list->length == 0){
		return true;
	}
	return false;
}

int InsertNewNode(MyList* list,long val,int index){
	MyNode* newnode = InitNode(val,index);
	if(IsEmpty(list)){
		list->head->next = newnode;
		newnode->previous = list->head;
		list->last = newnode;
		newnode->next = NULL;
	}
	else{
		list->last->next = newnode;
		newnode->previous = list->last;
		list->last = newnode;
	}
	list->length++;
	return 0;
}

int PopLast(MyList* list){
	MyNode* temp = list->last->previous;
	printf("Popped: %d\n\n",list->last->index);
	DestroyNode(list->last);
	list->last = temp;
	list->length--;
	return 0;
}

int DestroyList(MyList* list){
	printf("Destroying list, starting to pop all nodes\n");
	while(list->length!= 0){
		PopLast(list);
	}
	free(list);
	return 0;
}

void PrintList(MyList* list){
	if(list->length == 0){
		printf("List empty!\n\n");
	}
	else{
		MyNode* temp = list->head->next;
		printf("Printing list: ");
		while(temp != list->last){
			printf("(%d,%ld)",temp->index,temp->value);
			temp = temp->next;
		}
		printf("(%d,%ld)",temp->index,temp->value);
		printf("List length: %d\n",list->length);
		printf("\n");
	}
}

MyNode* GetNodeByIndex(MyList* list,int dex){
	if(IsEmpty(list)){
		//printf("List is empty - index %d doesn't exist\n\n",dex);
		return NULL;
	}
	MyNode* temp = list->head->next;
	while(temp != list->last){
		if(temp->index == dex){
			return temp;
		}
		temp = temp->next;
	}
	if(temp->index == dex){
		return temp;
	}
	return NULL;
}

bool IsExists(MyList* list,int dex){
	if(IsEmpty(list)){
		//printf("List is empty - index %d doesn't exist\n\n",dex);
		return false;
	}
	MyNode* temp = list->head->next;
	while(temp != list->last){
		if(temp->index == dex){
			return true;
		}
		temp = temp->next;
	}
	if(temp->index == dex){
		return true;
	}
	return false;
}




