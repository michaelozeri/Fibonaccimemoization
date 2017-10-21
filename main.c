/*
 * main.c
 *
 *  Created on: 21 срхїз 2017
 *      Author: michael
 */

/*
 * this is a bad implementation for a dictionary since searching for a member takes o(n)
 * still need to check why is there an overflow of long at fibonacci 46
 */

#include "MyList.h"
#include <time.h>


long FindFibonacciAtIndex(int index,MyList* list){
	if(index <=2){
		return 1;
	}
	else{
		long a,b;
		if(IsExists(list,index-1)){
			a = GetNodeByIndex(list,index-1)->value;
		}
		else{
			a = FindFibonacciAtIndex(index-1,list);
			InsertNewNode(list,a,index-1);
		}
		if(IsExists(list,index-2)){
			b = GetNodeByIndex(list,index-2)->value;
		}
		else{
			b = FindFibonacciAtIndex(index-2,list);
			InsertNewNode(list,b,index-2);
		}
		return a+b;
	}
}

int main(int argc,char** argv){

	int i;
	clock_t start, end;
	double cpu_time_used;
	MyList* dict = InitList();

	start = clock();

	for(i=0;i<101;i++){ //46 is one before overflow of double
		printf("(%d,%ld)\n",i,FindFibonacciAtIndex(i,dict));
	}
	end = clock();

	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("Time taken: %f\n",cpu_time_used);

	return 1;
}
