/* Author Eric Dunlop 
 * Date: Oct 2021
 * Discription: A5 prob2 first year iss
 */

#include <stdio.h>

void functionA();
void functionB();
int functionC(int row, int col, int (*array)[col]);


int main(){
	int row = 2;
	int col = 5;
	int arr[row][col];
	
	for(int i = 0; i < 5; i++)
		functionA();
		
	printf("\n/////////////////////////////\n\n");
		
	for(int i = 0; i < 5; i++)
		functionB();
		
	printf("\n/////////////////////////////\n\n");
		
	for(int i = 0; i < 5; i++)
		printf("[FUNA] The value now is: %d\n", functionC(row, col, arr));
		
	return 0;
}

//================================================

void functionA(void){
	int value = 100;
	printf("[FUNA] The value now is: %d\n", value);
	
	value +=1;
}
//===============================================

void functionB(void){
	static int value = 100;
	printf("[FUNB] The value now is: %d\n", value);
	
	value +=1;	
}

//================================================

int functionC(int row, int col, int (*array)[col]){
	static int value = 100;
	for(int i = 0; i < row; i++){
		for(int j = 0; j < col; j++){
			value +=1;
			}
		}
	return value;
}




