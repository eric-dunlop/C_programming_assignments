/* Author Eric Dunlop 
 * Date: Sept 14, 2021
 * Discription: Accepting inputs and calculating averages
 */
#include <stdio.h>

int main()
{
	// declaration and initialization of the variables 
	int intNum, intSum = 0, counter = 0;
	float floatNum, floatSum = 0, avg;
	printf("================================\n");
	// loop that accepts inputs, adds to intSum and iterates 5 times
	while(counter < 5){
		printf("please enter an int number: ");
		scanf("%d", &intNum);
		intSum += intNum;
		counter++;
		}
	// calculates the average typecast to float
	avg = (float) intSum / 5;
	// prints the results
	printf("\nSum of intergers is: %d\n", intSum);
	printf("The average is: %.2f\n\n", avg);
	
	counter = 0;	
	printf("================================\n");
	// loop that accepts inputs, adds to floatSum and iterates 5 times
	while(counter < 5){
		printf("please enter a float number: ");
		scanf("%f", &floatNum);
		floatSum += floatNum;
		counter++;
		}
	// calculates the average
	avg = floatSum / 5;
	// prints the results
	printf("\nSum of floats is: %.2f\n", floatSum);
	printf("The average is: %.2f\n\n", avg);
	
	
	return 0;
}

