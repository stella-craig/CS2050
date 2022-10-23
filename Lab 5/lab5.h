#include <stdio.h>
#include <stdlib.h>

typedef struct {
	/* stores the result of the last
	 * calculation done on the array
	 */
	int lastCalculation;
	int size;
} ArrayInfo;

/*  This function will take an integer representing the size of the integer array 
to allocate. It will then allocate an integer array with the given size, and if
successful, it returns a pointer to the array with an ArrayInfo struct hidden 
before the array pointer. Otherwise it will return NULL */
int * createArray(int size);

/* This function will take an integer array with the array info hidden before the 
array pointer, and return the size of the array. */
int getSize(int *array);

/*This function will take an array with info hidden before the array pointer as an
ArrayInfo struct, and return a pointer to that struct. */
ArrayInfo * getInfo(int *array);

/*This function will take an integer array with the array info hidden before the 
array pointer as an ArrayInfo struct, and will print the value of the last 
calculation performed on the array, or -1 if one does not exist (you may assume 
that no calculation will result in -1). */
void printLastCalculation(int *array);

/*This function will take a pointer to an array with the array info hidden before 
the array pointer as an ArrayInfo struct, calculate the sum of all the fives in the 
array. The result of the calculation should be stored in the array info. */
void sumFives(int *array);

/*This function will take a pointer to an integer array with the array info hidden 
before the array pointer as an ArrayInfo struct, and free the memory allocated to 
it. */
void freeArray(int *array);
