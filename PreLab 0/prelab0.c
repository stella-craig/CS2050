#include "prelab0.h"

//This function takes an array, the size of the array, and a query integer.
//It will return an integer that describes the number of integers in the array that are greater than or equal to our query.
//O(n)
int howManyGreaterThanOrEqualTo(int array[], int size, int query)
{
	//We start with our counter at zero, because this is our baseline. For every integer that meets our requirements, we will increase the counter by 1.
	int counter = 0;
	
	//Loop through the entire array so we can check against every integer in it. O(n)
	for (int i = 0; i < size; i++)
	{
		//If the integer in this location is greater than or equal to our query, increment our counter.
		if(array[i] >= query)
		{
			counter++;
		}
	}
	
	//Return the counter. This is the number of integers in our array that are greater than or equal to our query value.
	return counter;
}