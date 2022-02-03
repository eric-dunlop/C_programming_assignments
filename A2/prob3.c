/* Author Eric Dunlop 
 * Date: Sept 20, 2021
 * Discription: adding numbers
 */
#include <stdio.h>
int main()
{
	// declares the variables 
	int num, sum = 0;
	float avg;
	
	// living life fancy
	printf("*** *** *** *** *** *** *** ***\n");
	printf("  *** *** *** *** *** *** ***\n\n");
	
	// loop to accept all the inputs  
	for(int i = 1; i < 11; i++){
		printf("please enter a number %02d: ", i);
		scanf(" %d",&num);
		sum += num;
		}
	// calculates the average
	avg = (float)sum / 10;
	// print the sum
	printf("\nThe sum is: %d\n", sum);
	
	// checks if odd or even and prints appropriate result 
	if(sum % 2 == 0){
		printf("The sum is even\n");
		}
	else{
		printf("The sum is odd\n");
		}
	// print average
	printf("The average is: %.2f\n\n", avg);
	
	// more fancy stuff
	printf("  *** *** *** *** *** *** ***\n");
	printf("*** *** *** *** *** *** *** ***\n");
	return 0;	
}
