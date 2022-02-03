#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

//prototypes

void getInput(char *input);
int checkFirst(char *input);
int checkPassword(char *input);

int main(){

char input[11] = "\0";

	getInput(input);
	
	if(checkFirst(input))
		printf("you should never start a password with a letter\n");
		
	else if(!checkPassword(input))
		printf("OH NO! you have guessed my password!\n");
		
	else
		printf("You will never figure it out!\n");
	
	return 0;	
}

	/*char s[21];
	printf("\nPrompt to get string: ");
	
	fgets(s, 21, stdin);
	printf("\n*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*\n");
	printf("%s", s);
	printf("*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*");
	
//================================================================

	char s[5];
	printf("\nPrompt to get string: ");
	// can save to memory locations outside the size of s
	gets(s);

	printf("%s\n", s);

	*/
	
void getInput(char input[]){

	printf("Enter the 10 char password\t");
	fread(input, 1, 10, stdin);
	scanf("%*[^\n]%*c");
	printf("*******************\n\n");
}
	
//=================================================================
	
int checkFirst(char *input){

	printf("%d\n", isalpha((unsigned char)input[0]));

	return (isalpha((unsigned char)input[0]));
}
	
//==================================================================
	
int checkPassword(char *input){ 

	char password[] = "1234567890";
	return (strncmp(password, input, 11));
	

}





