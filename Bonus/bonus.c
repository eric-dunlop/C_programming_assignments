/* Discription: bonus assignment
 * Eric
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define COL 21
#define ROW 4

// prototypes

void getString(char input[][COL], char inputcpy[][COL]);
void fillArray(char random[]);
void checkArray(char input[][COL], char random[], int position[][COL]);
void printArry(char input[][COL], char inputcpy[][COL], int position[][COL]);

//=======================================================
// main only contains variable declorations and function calls

int main(){
	
	char input[ROW][COL] = {"\0"};
	char inputcpy[ROW][COL] = {"\0"};
	int position[ROW][COL] = {0};
	char random[16] = "\0";
	
	getString(input, inputcpy);
	
	fillArray(random);

	checkArray(input, random, position);

	printArry(input, inputcpy, position);
	
	return 0;
}

//=====================================================
// takes in ROW strings max COL long to the input array

void getString(char input[][COL], char inputcpy[][COL]){
	for(int i = 0; i < ROW; i++){
		printf("please enter a string: ");
		//takes in max 9 chars and then clears the buffer
		scanf(" %20[^\n]s", input[i]);
		scanf("%*[^\n]%*c");
	}
	printf("******************************************\n\n");
	
	// makes a copy of the input for printing in the printArray function
	// because the original gets altered in checkArray
	for(int i = 0; i < ROW; i++){
		for(int j = 0; j < COL; j++)
			inputcpy[i][j] = input[i][j];
	}
}

//===============================================
// creates a string 15 long of random number and lower case letters

void fillArray(char random[]){

	srand(time(NULL));
	
	for(int i = 0; i < 16; i++){
		int check = rand()%36;
		
		// 26/36 times it picks a letter
		if(check < 26)
			random[i] = (rand()%26) + 97;
			
		// 10/36 times it picks a number
		else 
			random[i] = (rand()%10) + 48;
	}
	
	printf("the original random array: %s\n\n", random);
	printf("******************************************\n\n");
}

//==================================================
// checks the input arrays against the random array 
// changes the input array character to a - if they match
// saves the positions the changes occured at to the positions 2d array

void checkArray(char input[][COL], char random[], int position[][COL]){

	// iterates through the input words
	for(int i = 0; i < ROW; i++){
		int count = 0;
		// iterates through input chars
		for(int j = 0; j < COL; j++){
			// breaks out if input position is \0 
			if(input[i][j] == '\0')
				break;	
			// iterates through the random array
			for(int k = 0; k < 16; k++){
				
				// changes the input array at current position to - if they match
				if(input[i][j] == random[k]){
					input[i][j] = '-';
		// saves the position of each removed letter to the position array
					position[i][count] = j + 1;
					count ++;
				}
			}
		}
	}
}
	
//================================================================
// prints the final results

void printArry(char input[][COL], char inputcpy[][COL], int position[][COL]){

	for(int i = 0; i != ROW; i++){
		printf("\noriginal:  %s", inputcpy[i]);
		printf("\naltered:   %s", input[i]);
		printf("\npositions: ");
		//loop to print through the positions array
		for(int j = 0; j < COL; j++){
			if(position[i][j] != 0)
				printf("%d, ", position[i][j]);		
		}
		printf("\n***************************\n");
	}	
}






