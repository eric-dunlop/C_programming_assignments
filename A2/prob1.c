/* Author Eric Dunlop 
 * Date: Sept 19, 2021
 * Discription: build a half full square with loops
 */
#include <stdio.h>
int main(){
	
	// for loop that prints rows based on j
	for(int j = 0; j < 10; j++){
	// for loop that iterates the cols 
		for(int i = 0; i < 21; i++){
	// checks if its the first col and prints the tabs 
			if(i ==0){
				printf("\t");
			}
	// prints all cases where a * is required
			else if((j == 0 && i % 2 == 1) || (i < j * 2 && i % 2 == 1) || i == 19){
				printf("*");
			}
	// every case where a * is not printed, a " " is.
			else{
				printf(" ");
			}
		}
	// starts next line
		printf("\n"); 
	}
	return 0;
}

