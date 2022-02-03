/* Author Eric Dunlop 
 * Date: Nov, 2021
 * Discription: organizing data from files
 */
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void getfiles(FILE **fptr, FILE **lptr, FILE **cptr);
void genphone();
void processfiles(FILE *fptr, FILE *lptr, FILE *cptr, int *firstcounter);
void printsample(FILE *cptr, int firstcounter);

int main(){
	// declare some variables
	srand(time(NULL));
	int firstcounter = 0;
	FILE *fptr = NULL;
	FILE *lptr = NULL;
	FILE *cptr = NULL;
	// function calls
	getfiles(&fptr, &lptr, &cptr);
	
	processfiles(fptr, lptr, cptr, &firstcounter);

	printsample(cptr, firstcounter);
	
	// close all files
	fclose(fptr);
	fclose(lptr);
	fclose(cptr);
	return 0;
}

//==========================================================================
// gets the file names and opens the files

void getfiles(FILE **fptr, FILE **lptr, FILE **cptr){

	char firstfile[40] = "\0";
	char lastfile[40] = "\0";
	char contactsfile[40] = "\0";
	// gets file names from user
	printf("\nEnter the first names file name:\t");
	scanf(" %s", firstfile);
	printf("Enter the last names file name: \t");
	scanf(" %s", lastfile);
	printf("Enter the contacts file name:\t\t");
	scanf(" %s", contactsfile);
	// opens the files
	*fptr = fopen(firstfile, "r");
	*lptr = fopen(lastfile, "r");
	*cptr = fopen(contactsfile, "w+");
	// checks for errors opening files
	if(*fptr == NULL || *lptr == NULL || *cptr == NULL){
		printf("problem opening files\n");
		exit(-1);
	}
}

//==================================================================
// saves the information from the files to arays
// opens the 

void processfiles(FILE *fptr, FILE *lptr, FILE *cptr, int *firstcounter){
	// needed a bunch of variables for this
	char domains[][20] = {"@email.ca", "@sait.ca", "@bmw.ca", "@northK.gov", "@yeehaw.com", "@growe.swt"}; 
	char firstnames[500][40] = {"\0"};\
	char lastnames[500][20] = {"\0"};
	char emails[100][50] = {"\0"};
	char phone[15] = "\0";
	int lastcounter = 0;
	// make arrays of the names
	while(fscanf(fptr, " %s", firstnames[*firstcounter]) != EOF)
		*firstcounter += 1;
	
	while(fscanf(lptr, " %s", lastnames[lastcounter]) != EOF)
		lastcounter += 1;

	// loop to creat the random contacts 
	for(int i = 0; i < lastcounter; i++){
		if(*firstnames[i] != '\0'){
			// generates the phone number for this user
			genphone(phone);
			
			int randnum1 = rand() % *firstcounter;
			int randnum2 = rand() % lastcounter;
			int randnum3 = rand() % 6;
			// saves the email to an array becasue you said I had to 
			sprintf(emails[i], "%s.%s%s",  firstnames[randnum1], lastnames[randnum2], domains[randnum3]);
			// make the full name 1 string 
			strncat(firstnames[randnum1], " ", 2);
			strncat(firstnames[randnum1], lastnames[randnum2], sizeof(lastnames));
			//save the new user to the contats file
			fprintf(cptr, "%25s - %30s - %s \n", firstnames[randnum1], emails[i], phone);
		}
	}
}
//============================================================================
// generates a random phone number

void genphone(char *phone){
	// generate numbers in the appropriate ranges and save them to the string 
	int numsec = rand() % 300 + 400;
	sprintf(&phone[1], "%d", numsec);
	numsec = rand() % 800 + 200;
	sprintf(&phone[6], "%d", numsec);
	numsec = rand() % 10000;
	sprintf(&phone[10], "%d", numsec);
	// add the symbols to make it look legit
	phone[0] = '(';
	phone[4] = ')';
	phone[5] = ' ';
	phone[9] = '-';
}

//===========================================================================
// prints the results

void printsample(FILE *cptr, int firstcounter){
	
		printf("\n=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=\n");
	printf("\t\t\tSAMPLE\n");
	printf("=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=\n");
	// loop to print the 10 rand contacts
	for(int i = 0; i < 10; i++){
	// a buffer
	char contactline[100] = "\0";
		// resets to the start of the file
		rewind(cptr);
		// cycle through a random number of lines before printing one
		for(int j = 1; j <= rand()%(firstcounter-1)+1; j++){	
			fgets(contactline, 99, cptr);
		}
		printf("\n%s", contactline);	
		printf("________________________________________________________________________________\n");
	}
}

//=============================================================================





