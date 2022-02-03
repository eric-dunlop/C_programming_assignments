/* Author Eric Dunlop 
 * Date: Sept 19, 2021
 * Discription: stars 'n' loops 'n' stuff
 */
#include <stdio.h>
int main()
{
	// sets up the nested for loops
	// 7 rows high and 12 col
	for(int i = 0; i < 7; i++){
		for(int j = 0; j < 12;j++){	
	// check if first col and print \t 
			if(j == 0){
				printf("\t");
				}
	// check if it is an even row, if so this part runs
			else if(i % 2 == 0){
				if(j % 2 == 1){
					printf("*");
					}
				else{
					printf("o");
					}
				}	
	// if it's not even it must be odd and this part runs				
			else{
				if(j < 2 || j > 10){
					printf("o");
				}
				else{
					printf("*");
				}
			}
		}
		printf("\n");
	}
	return 0;
}
