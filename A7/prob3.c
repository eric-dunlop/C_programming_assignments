/* Author Eric Dunlop 
 * Date: Nov, 2021
 * Discription: 
 */
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void getfile(FILE **fptr);
void getbytes(unsigned char *hexarr, FILE *fptr, int *linecounter);
void printmagic(unsigned char *hexarr);
void printline(unsigned char *hexarr, int *plettercounter, int counter);
void printsummery(int *plettercounter, int totalcounter);

int main(){
	
	int firstline = 1, run = 1;
	int totalcounter = 0;
	int counter = 0;
	int lettercounter = 0;
	int *plinecounter = &counter;
	int *plettercounter = & lettercounter; 
	unsigned char hexarr[17] = "\0";
	FILE *fptr = NULL;

	getfile(&fptr);
	if(fptr == NULL){
		// checks for errors opening file.
		printf("error opening files");
		exit(-1);	
	}
	// run changes from 1 to 0 when feof is reached
	while(run){
		// gets the next 16 bytes from the file
		getbytes(hexarr, fptr, plinecounter);
		
		// prints the magcic number abd file type on the first cycle
		if(firstline){
			printmagic(hexarr);
			firstline = 0;
		}
		// prints formatted output
		printline(hexarr, plettercounter, counter);
		totalcounter += counter;
		// allows incrimenting of 10 lines at a time.
		if(totalcounter % 160 == 0){
			printf("\n\nPress enter to show 10 more lines");
			getchar();
		}
		// stops the while loop at feof
		if(feof(fptr))
			run = 0;
		printf("\n");
	}
	// prints the final analysis
	printsummery(plettercounter, totalcounter);
	fclose(fptr);
	return 0;
}

//=========================================================================
// get file name and open the requested file

void getfile(FILE **fptr){
	
	char filename[30] = "\0";
	printf("which file would you like to open? \n");
	scanf(" %s", filename);
	// clears the buffer
	getchar();
	*fptr = fopen(filename, "rb");
}
	
//==========================================================================
// gets the next 16 bytes of the file and saves them to hexarr

void getbytes(unsigned char *hexarr, FILE *fptr, int *plinecounter){
	// this is not required but I thought it was a cool function.
	memset(hexarr, '\0', 16);
	
	for(*plinecounter = 0; *plinecounter < 16; *plinecounter += 1){
		if(feof(fptr))
		return;
		else
			hexarr[*plinecounter] = getc(fptr);
	}
}

//========================================================================
// prints the magic number and file type at the top

void printmagic(unsigned char *hexarr){

	
	printf("\n*************************************************\n");
	printf("\nthis number is very magical: 0x ");

	for(int i = 4; i >= 0; i--){
		printf("%02X", hexarr[i]);
	}
	printf("\n\nFile Type: ");
	for(int i = 0; i < 4; i++)
		printf("%c", hexarr[i]);
	// prints the titles
	printf("\n\n*************************************************\n\n");
	printf("offset\t\t\t\t\tHexvalues\t\t\tchar values\n");
	printf("\n*************************************************");
	printf("***************************************\n\n");
}

//============================================================================
// formats the data and prints a line to the output

void printline(unsigned char *hexarr, int *plettercounter, int counter){

	static int linenum = 0;	

	printf("%06X  |  ", linenum);
	linenum += 0x10;
	
	for(int  i = 0; i < counter; i++){
	
		printf("%02X ", hexarr[i]);
		if(i == 7)
			printf("- ");
	}
	for(int i = 0; i < 16 - counter; i++)
		printf("   ");
		
	printf("  |  ");
	for(int i = 0; i < 16; i++){
		if(hexarr[i] > 32 && hexarr[i] < 126){
			printf("%c", hexarr[i]);
			*plettercounter +=1;
			}
		else
			printf(".");
	}
}

//==================================================================

void printsummery(int *plettercounter, int totalcounter){
	
	float letterpercent = (float)*plettercounter / totalcounter * 100;
	printf("\nThe file is %0.1lf%c letters \n", letterpercent, '%');
	
	if(letterpercent < 25)
		printf("NO WAY that this is a text file!");
		
	else if(letterpercent < 75)
		printf("\nThis might be a janky text file~\n");
		
	else
		printf("Maybe it's a story we can read!!!!");
}










	
