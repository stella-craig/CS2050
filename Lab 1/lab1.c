/* Function getAvg gets the average of the values of the array it is inputted.
	It is important to check if there is an error, returning -1 if so.
	The errors we check for are if the array pointer is null or if the size is less than 1.
	If there is not an error, we return 0.
	We then set the result to the average that we calculate.
	If there is an error, set the result to -1 to represent that error.
	*/

#include "lab1.h"

int getAvg(int size, int *array, double *result){
	
	if (size > 0){ 				//Check that size is at least 1
		if (array != NULL){		//Check that the array pointer is not null
			
			double sum = 0;		//The sum will be used to add up all the values in the array 
			double average;		//This is a temporary variable, so the code looks less ugly
			
			for(int i = 0; i < size; i++){ //Loop through the array and add up all the values, saving it in sum.
				sum = sum + array[i];
			}
			average = sum / size; //Take the average by dividing the total sum by how many values were in the array (the size)
			
			*result = average;	//Change the original result (in the main func) to the average
			
			return 0;			//It was successful
		}
		else {					//Else it is an error
			*result = -1;		//Change the original result to -1 to show that there was an error in getAvg
			return -1;		
		}
	}
	else {						//Else it is an error
		*result = -1;			//Change the original result to -1 to show that there was an error in getAvg
		return -1;
	}
	
}
