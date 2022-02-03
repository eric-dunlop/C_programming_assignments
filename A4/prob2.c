/* Author Eric Dunlop 
 * Date: Sept 19, 2021
 * Discription: A4 Prob2
 */

#include "prob2.h"

int main(){
	int tries = 0;
	// only allows the program to run 3 times
	while(tries < 3){
	
		char input[COL] = "\0";
		getInput(input);
		tries ++;	
	}
	return 0;
}

//====================================
// gets the user input and calls doMath()
void getInput(char input[]){
	
	printf("please input a stiring: ");
	scanf(" %20[^\n]s", input);
	scanf("%*[^\n]%*c");
	printf("\n***********************************\n");
	doMath(input);
}
//=====================================
// checks if the input is accepted and calls the appropriate function 
void doMath(char input[]){
	int len = 0, result = 0;
	//gets the string length 
	for(int i = 0; i < COL; i++){
		if(input[i] != '\0'){
			len++;
		}
	}
	// the math part
	for(int i = 0; i < len; i++){
		result+=input[i] * (len - i);
	}
	// if the code passes calls challanges()
	if(result == 7234)
		challanges();
	// if not it calls randchars()
	else{
		printf("Welcome you may proceed\n\n");
		randchars();
		printf("\n***********************************\n\n");
	}
}

//=====================================
// randomly asks one of 3 riddles and checks the answer
void challanges(){
srand(time(NULL));
int randnum = rand()%3;
	if(randnum == 0){
		char answer[] = "incorrectly";
		char guess[21] = "\0";
		printf("What word is always pronounced incorrectly?   ");
		scanf(" %20[0-9a-zA-Z ]s", guess);
		scanf("%*[^\n]%*c");
		for(int i = 0; i < sizeof(answer)-1; i++){
			if(answer[i] != guess[i]){
				printf("\nThanks for comin' out guy.\n\n");
				return;	
			}	
		}
	}
	else if(randnum == 1){
		char answer[] = "edam";
		char guess[21] = "\0";
		printf("What type of cheese is made backward?  ");
		scanf(" %20[0-9a-zA-Z ]s", guess);
		scanf("%*[^\n]%*c");
		for(int i = 0; i < sizeof(answer)-1; i++){
			if(answer[i] != guess[i]){
				printf("\nThanks for comin' out guy.\n\n");
				return;	
			}	
		}	
	}
	else if(randnum == 2){
		char answer[] = "wet";		
		char guess[21] = "\0";
		printf("If you drop a yellow hat in the Red Sea, what does it become?   ");
		scanf(" %20[0-9a-zA-Z ]s", guess);
		scanf("%*[^\n]%*c");
		for(int i = 0; i < sizeof(answer)-1; i++){
			if(answer[i] != guess[i]){
				printf("\nThanks for comin' out guy.\n\n");
				return;	
			}	
		}	
		
	}
	// only runs if the answer to the riddle is correct
	printf("\n<=========================>\n");
	printf("  You are SoOoOoOo smart!\n");
	printf("<=========================>\n");
	// exits the program
	exit(-1);
}

//=============================================================
// prints a random string
void randchars(){
	srand(time(NULL));
	// randomly selects the length of the string
	int randindex = (rand()%12) + 7;
		for(int i = 0; i < randindex; i++){
			// prints a randome char for each loop
			char randchar = (rand()%95) + 32;
			printf("%c", randchar);
		
	}
	printf("\n");
}
	





