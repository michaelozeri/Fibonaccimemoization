/*
 * MyNode.h
 *
 *  Created on: 21 срхїз 2017
 *      Author: michael
 */

#ifndef MYNODE_H_
#define MYNODE_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct my_node_t{
	int index;
	long value;
	struct my_node_t* next;
	struct my_node_t* previous;
} MyNode;

MyNode* InitNode(long value,int index);

void DestroyNode(MyNode* node);


#endif /* MYNODE_H_ */
