/* Author Eric Dunlop 
 * Date: Oct, 2021
 * Discription: 
 */
 
#include "prob1.h"

int main(){

	char input[SIZE][COL] = {"\0"};
	char newStr[SIZE][COL] = {"\0"};
	// function calls.
	getStrings(input[0]);	
	isPalindrome(input, newStr);
		
	return 0;	
}

//============================
// gets SIZE number of inputs
void getStrings(char input[]){

	for(int i = 0; i < SIZE; i++){
		printf("please enter a string max 20 charaters: ");
		scanf(" %[^\n]s", &input[i*COL]);
	}
}

//============================
// I realize that this could be done in a way thats easier to read using 
// input[][COL] format, but its done and it works!

// loops through each input string from back to front and saves each valid
// digit to the revStr starting at the front
void reverseStr(char input[], char revStr[]){
	for(int i = 0; i < SIZE; i++){
		int counter = 0;
		for(int j = 0; j < COL-1; j++){
		
			// an abosolute catastrophy of maths
			if(input[(i+1)*COL-(j+2)] != '\0'){
				revStr[i*COL+counter] = input[(i+1)*COL-(j+2)];
				counter++;
			}
		}
	}
}

//==============================

void isPalindrome(char input[][COL], char revStr[][COL]){

	// reverse string function call
	reverseStr(input[0], revStr[0]);
	
	int palindroms = 0;
	// nested loops that compare the reversed string to the original
	for(int i = 0; i < SIZE; i++){
		int check = 0;
		for(int j = 0; j < COL; j++){
			if(input[i][j] != revStr[i][j]){
			check++;
		}
	}
		// print the results of each check
		if(check){
			printf("\n%s is not a palindrome.\n", input[i]);
		}
		else{
			palindroms++;
			printf("\n%s is a palindrome.\n", input[i]);
		}
	}
	printf("\n***************************\n");
	printf("\nNumber of palindroms: %d\n", palindroms);
}



