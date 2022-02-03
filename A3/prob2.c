/* Author Eric Dunlop 
 * Date: Oct, 2021
 * Discription: take a binary input and convert it
 */
#include <stdio.h>
int main(){	
	while(1){
		int counter = 1;
		unsigned long int dec = 0, mult = 1;
		char arr[33] = "\0";
		printf("\n***********************************************\n");
		printf("\nPlease enter a binary number up to 32 digits: ");
		scanf("%s", arr);
		//checks the length of the input and sets the variables correctly 
		for(int i = 0; i < sizeof(arr); i++){
			if(arr[i] != '\0' && i != 0){ 
				mult *= 2;
				counter++;
			}
		}
		//converts each digit to an int and filters for binary 
		for(int i = 0; i < counter; i++){
			int num = arr[i] - 48;
			//validates the input
			//checks if the input is not binary, or too long
			if ((num != 0 && num != 1) || arr[sizeof(arr) - 1] != '\0'){
				printf("\n/*/*/*/* Invalid input /*/*/*/*");
				printf("\n/*/*/*/* 1s & 0s only /*/*/*/*");
				printf("\n/*/*/*/* Max 32 digits /*/*/*/*\n\n");
				return 0;
			}
			//adds to the total 
			else{
				dec +=num * mult;
				mult /= 2;
			}			
		}
		//print result
		printf("\ndecimal equivalent: %ld	--> hex: 0x%02x\n\n", dec, dec);	
	}
return 0;
}
