#include "lab5.h"

/*This is essentially to test my lab5.h functions :) */
int main()
{
	int size = 42;
	int * array = createArray(size);
	
	if(!array)
	{
		printf("ERROR: createArray failure\n");
		return -1;
	}
	else
	{
		printf("create Array sucess!\n\n");
	}
	
	int testSize = getSize(array);
	
	printf("Size is supposed to be %d\n", size);
	printf("getSize function returns %d\n\n", testSize);
	
	ArrayInfo * testing;
	testing = getInfo(array);
	printf("Testing size is %d\n", testing->size);
	printf("Testing lastCalc is %d\n\n", testing->lastCalculation);
	
	printLastCalculation(array);
	
	sumFives(array);
	
	printLastCalculation(array);
	
	array[4] = 5;
	array[5] = 5;
	array[6] = 5;
	
	sumFives(array);
	printLastCalculation(array);
	
	freeArray(array);	
	
	return 0;
}
