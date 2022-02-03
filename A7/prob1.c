/* Author Eric Dunlop 
 * Date: Dec, 2021
 * Discription: sorting numbers from a file
 */
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
int main(){

	char buffer[100] = "\n";
	int lowcount = 0, highcount = 0;
	
	// open the files
	FILE *numfile = fopen("numbers.txt", "r");
	FILE *lowfile = fopen("below55.txt", "w");
	FILE *highfile = fopen("above55.txt", "w");	
	
	// check that files opend correctly
	if(numfile == NULL || lowfile == NULL || highfile == NULL){
		printf("problem opening files\n");
		exit(-1);
		}
	// keeps getting the next word until EOF
	// also some counters for each file 
	while(fscanf(numfile, " %s", buffer) != EOF){
		// gets floats below 55.55 and saves them
		if(atof(&buffer[1]) < 55.55 && atof(&buffer[1]) > 0.00){
			fprintf(lowfile, "%7s\t", &buffer[1]);
			
			// adds a newline every 10th float
			if(lowcount % 10 == 9)
				fprintf(lowfile, "\n");
			lowcount++;
		}
		// same as above but for high numbers
		else if(atof(&buffer[1]) >= 55.55){
			fprintf(highfile, "%7s\t", &buffer[1]);
			
			if(highcount % 10 == 9)
				fprintf(highfile, "\n");
			highcount++;
		}
	}
	// print the results
	printf("\nTotal numbers processed: %d\n\n", highcount + lowcount);
	printf("There were - %d numbers below 55.55\n", lowcount);
	printf("There were - %d numbers above 55.55\n", highcount);
	// close the files		
	fclose(numfile);
	fclose(lowfile);
	fclose(highfile);
	return 0;
}

