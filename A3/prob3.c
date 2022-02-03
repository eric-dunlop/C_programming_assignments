/* Author Eric Dunlop 
 * Date: oct, 2021
 * Discription: printing addresses and types
 */
#include <stdio.h>
int main(){
	int arrint[7];
	char arrchar[7];
	//accepts int inputs
	for(int i = 0; i < 6; i++){
		printf("please enter an int: ");
	 	scanf(" %d", &arrint[i]);
	 }
	 printf("\nplease enter a 6 char string: ");
	 //accepts char inputs
	 for(int i = 0; i < 6; i++){
	 	scanf(" %c", &arrchar[i]);
	 	}
	 	printf("\n==========================================================");
	 	printf("\nElement\t\tAddress\t\t  Hexidecimal\tDecimal");
	printf("\n*** *** *** *** *** *** *** *** *** *** *** *** *** *** ***\n");
	//prints int results
	 for(int i = 0; i < 6; i++){
	 	printf("||interger[%d]||\t%p||  0x%04X ||\t%03d\t||\n", i+1, &arrint[i], arrint[i], arrint[i]);
	 	}
	 	printf("|| = = = = = || = = = = = = = || = = = = || = = = = = = ||\n");
	 //prints char results
	 for(int i = 0; i < 6; i++){
	 	printf("|| arrchar[%i]||\t%p||  0x%04X ||\t%d\t||\n", i+1, &arrchar[i], arrchar[i], arrchar[i]);
		}
		printf("*** *** *** *** *** *** *** *** *** *** *** *** *** *** ***\n");
		printf("%p", &arrint[2] - &arrint[1]);
	return 0;
}
