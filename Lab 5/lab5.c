#include "lab5.h"

/*
typedef struct {
	int lastCalculation;
	int size;
} ArrayInfo;
*/


/*  This function will take an integer representing the size of the integer array 
to allocate. It will then allocate an integer array with the given size, and if
successful, it returns a pointer to the array with an ArrayInfo struct hidden 
before the array pointer. Otherwise it will return NULL */
int * createArray(int size)
{
	ArrayInfo * array; //create an array of ArrayInfos because it simplifies things later
	ArrayInfo hidden; //create the ArrayInfo that will be hidden in front of the int array
	(hidden).size = size; //set the size of the hidden ArrayInfo to the size of the int array so can be accessed later
	(hidden).lastCalculation = -1; //set lastCalculation to -1 because no previous calculations have been performed yet
	array = malloc(size * sizeof(int) + sizeof(ArrayInfo)); //allocated enough memory in the array for the number of ints we need plus an ArrayInfo
	array[0] = hidden; //set first item in array to our hidden ArrayInfo
	
	if(!(int*)(array+1)) //returns NULL (for error checking)
	{
		return NULL;
	}
	
	return(int *)(array + 1); //returns a pointer to the int array (so typecasted it) with an ArrayInfo struct hidden before the array pointer (hense the -1)
}



/* This function will take an integer array with the array info hidden before the 
array pointer, and return the size of the array. */
int getSize(int *array)
{
	ArrayInfo * p;
	p = (ArrayInfo *)array; //typecast the array to ArrayInfo
	int size = p[-1].size; //get the size from the hidden ArrayInfo in front of array
	return size;
}


/*This function will take an array with info hidden before the array pointer as an
ArrayInfo struct, and return a pointer to that struct. */
ArrayInfo * getInfo(int *array)
{
	ArrayInfo * p;
	p = (ArrayInfo *)array; //typecast the array to ArrayInfo
	return &p[-1]; //returns a pointer to the ArrayInfo struct so we can access the information from it
}


/*This function will take an integer array with the array info hidden before the 
array pointer as an ArrayInfo struct, and will print the value of the last 
calculation performed on the array, or -1 if one does not exist (you may assume 
that no calculation will result in -1). */
void printLastCalculation(int *array)
{
	ArrayInfo * testing;
	testing = getInfo(array); //testing is a pointer to the ArrayInfo thats hidden before array
	
	if ((testing->lastCalculation)==-1) //if the lastCalc is -1, we assume no calculations have been performed
	{
		printf("// No previous calculation performed \nLast calculation: -1\n");
	}
	else //if the lastCalc isn't -1, we assume that a calculation has been performed and we return what that is
	{
		printf("// Previous calculation resulted in %d \nLast calculation: %d\n", testing->lastCalculation, testing->lastCalculation);
	}	
	//printf("Testing lastCalc is %d\n\n", testing->lastCalculation);
	
}


/*This function will take a pointer to an array with the array info hidden before 
the array pointer as an ArrayInfo struct, calculate the sum of all the fives in the 
array. The result of the calculation should be stored in the array info. */
void sumFives(int *array)
{
	ArrayInfo * info;
	info = getInfo(array); //info is a pointer to the ArrayInfo hidden before the array
	
	int size = info->size; //get the size from the hidden ArrayInfo
	//printf("\nsumFives: the size is %d\n", size);
	
	int numOfFives = 0; //a counter for the number of fives
	
	for(int i = 0; i < size; i++) //we use the size to know how many times we should go through the array and check if there is a five
	{
		if (array[i]==5)
		{
			numOfFives++; //if theres a five, increase the counter for number of fives
		}
	}
	
	if (numOfFives == 0) //if there are no fives, no calculation has been made and we leave lastCalculation in the ArrayInfo alone
	{
		return;
	}
	
	else //if there are some fives, we can add them together and change the lastCalculation to that
	{
		int calculation = 0;
		for(int i = 0; i < numOfFives; i++)
		{
			calculation = calculation + 5; //calculation is the sum of all the 5s
		}
		info->lastCalculation = calculation; //set lastCalculation in our hidden ArrayInfo to the sum of the 5s
	}
	
}


/*This function will take a pointer to an integer array with the array info hidden 
before the array pointer as an ArrayInfo struct, and free the memory allocated to 
it. */
void freeArray(int *array)
{
	ArrayInfo * p;
	p = (ArrayInfo*)array; //typecast the array
	free(p-1); //free the array, making sure to minus 1 so we also free the hidden ArrayInfo struct
}
