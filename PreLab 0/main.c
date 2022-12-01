#include "prelab0.h"

int main(void)
//The main function primarily serves to test our other functions.
{
	//These are our test size and array. The user would use whichever size and array would be useful to them.
	int size = 5;
	int array[] = {1, 2, 3, 4, 5};
	
	//The user will input the query. Our program will see how many integers are in our array that are greater than or equal to our query.
	int query;
	printf("What is our query?\n");
	scanf("%d", &query);
	
	//Here we are using our function and printing a statement back to the user. This puts our important information onto the console and shows us that our test was successful.
	int solution = howManyGreaterThanOrEqualTo(array, size, query);
	printf("There are %d integers in our array that are greater than or equal to %d.\n", solution, query);	
	
	//Our main function is of type int, so it must return an integer.
	return 0;
}