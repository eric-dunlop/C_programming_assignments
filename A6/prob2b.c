/* Author Eric Dunlop 
 * Date: Nov, 2021
 * Discription: 
 * References:
 * https://www.tutorialspoint.com/c_standard_library/c_function_strtok.htm
 */
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <getopt.h>
#include <time.h>

void getletters(char *letters, char *input);
void getRandStr(char *randletters, char *inputletters, int length);
void filesave(char *randletters, FILE *fptr);
void printfile(char *filename, FILE *fptr);

int main(int argc, char **argv){
	
	srand(time(NULL));
	
	char letters[11] = "\0";
	char mode[2] = "\0";
	char filename[50] = "\0";
	int cols = 0;
	int rows = 0;

	// loops through argv and organises the inputs into named variables
	for(int i = 0; i < argc - 1; i++){
	
		if(!strcmp(argv[i], "--letters"))
			getletters(letters, argv[i+1]);
			
		else if(!strcmp(argv[i], "--len"))
			cols = atoi(argv[i+1]) * 2;
				
		else if(!strcmp(argv[i], "-c"))
			rows = atoi(argv[i+1]);
				
		else if(!strcmp(argv[i], "-f"))
			strcpy(filename, argv[i+1]);
				
		else if(!strcmp(argv[i], "-m"))
			strcpy(mode,argv[i+1]);	
	}
	
	printf("\n********************************\n\n");
	char  randletters[cols+1];
	// opens file 
	FILE *fptr = fopen(filename, mode);
	if(fptr == NULL){
		printf("problem opening file\n");
		exit(-1);
	}
	// for read mode
	if(!strcmp(mode, "r")){
		printfile(filename, fptr);
	}
	// for write or append mode
	else{
		for(int i =0; i < rows; i++){
			getRandStr(randletters, letters, cols);
			filesave(randletters, fptr);
			puts(randletters);
		}
	}
	// closes file
	fclose(fptr);
	return 0;
}

//====================================================================
// takes the letters from the input and removes the commas
// saves the modified string to letters arrray

void getletters(char *letters, char *input){
	
	// because it says max 10 letters added
	if (strlen(input) > 19){
		printf("too many letters entered");
		exit(-2);
	}
	int j = 0;
	char *token;
	
	// saves the first token 
	token = strtok(input, ",");
	// saves the rest of the tokens
	while(token != NULL ) {
		letters[j] = *token;
		j++;
		token = strtok(NULL, ",");
	}
}

//=====================================================================
// saves a string of random charaters according to the inputs

void getRandStr(char *randletters, char *inputletters, int length){
	
	int inputnum = strlen(inputletters);

	for(int i =0; i < length; i++){
		if(i % 2 == 1)
			randletters[i] = ' ';
		else{
			randletters[i] = inputletters[ rand() % inputnum];
		
			randletters[length] = '\0';
		}
	}	
}

//======================================================================
// saves the created string to the selected file

void filesave(char *randletters, FILE *fptr){

	fprintf(fptr,"%s\n", randletters);

}

//=====================================================================
// prints the file contents if read mode is selected

void printfile(char *filename, FILE *fptr){

	int linecounter = 1;
	printf("read from file: %s\n\n", filename);
	char tempchar[100];

	while(fgets(tempchar, 99, fptr)){
		printf("Line %2d: ", linecounter);
		printf("%s", tempchar);
		linecounter++;		
	}	

}











