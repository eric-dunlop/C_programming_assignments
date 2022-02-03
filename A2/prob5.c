/* Author Eric Dunlop 
 * Date: Sept 26, 2021
 * Discription: backwords hex algo
 * 
 */
#include <stdio.h>
int main()
{
	int input = 0, digit;
	// first print and scan, only run at the beginning to get things started 
	printf("\n\tPlease enter a number from range 0 and 65535 inclusive: ");
	scanf(" %d", &input);
	// as long as input is below 65536 the program will loop
	while(input < 65536){
		printf("\t  Your number as a hexadecimal (reversed) is: ");
	// inner loop processes the input and prints digits 
		for(int i = 0; i < 5; i++){
			digit = input % 16;
			input = input / 16;
	// prints if digit is below 10
			if(digit < 10){
				printf("%d", digit);
			}
	// handles digits 10 and over
			else{
				switch (digit){
				case 10 :
					printf("%c",'A');
					break;
				case 11 :
					printf("%c",'B');
					break;
				case 12 :
					printf("%c",'C');
					break;
				case 13 :
					printf("%c",'D');
					break;
				case 14 :
					printf("%c",'E');
					break;
				case 15 :
					printf("%c",'F');		
				}
			}
		}
	// accepts all inputs after the first one
		printf("\n\n\n\tplease enter a number from range 0 and 65535 inclusive: ");
		scanf(" %d", &input);	
	}
	// exit confirmation
	printf("\n\t    QUITTING\n\t    %d is larger than 65535\n", input);
	return 0;
}
