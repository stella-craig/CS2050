/* Function getAvg gets the average of the values of the array it is inputted.
	It is important to check if there is an error, returning -1 if so.
	The errors we check for are if the array pointer is null or if the size is less than 1.
	If there is not an error, we return 0.
	We then set the result to the average that we calculate.
	If there is an error, set the result to -1 to represent that error.
	*/

#include "lab1.h"

int main() {
	int size = 9, error,
			array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	double dResult;

	error = getAvg(size, array, &dResult);
	printf("getAvg() returned %d, result = %f\n", error, dResult);
	puts("Testing NULL checking");
	error = getAvg(size, NULL, &dResult);
	printf("getAvg() returned %d, result = %f\n", error, dResult);
	puts("Testing zero size checking");
	error = getAvg(0, array, &dResult);
	printf("getAvg() returned %d, result = %f\n", error, dResult);
	puts("Testing both");
	error = getAvg(0, NULL, &dResult);
	printf("getAvg() returned %d, result = %f\n", error, dResult);
}
