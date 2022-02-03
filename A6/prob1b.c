/* Author Eric Dunlop 
 * Date: Nov, 2021
 * Discription: do math from the command line sem 1 assignament
 */
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

// prototypes
void add(float *intarr, int argc, int);
void subtract(float *intarr, int argc, int);
void multiply(float *intarr, int argc, int);
void divide(float *intarr, int argc, int);

int main(int argc, char **argv){
    
    // because why would you need an input bigger then that
    if(argc > 100)
        exit(-1);	

    int runlen = argc;
	float floatarr[argc];	
    // converts the input to a float array with neg numbers
    // representing the operators
	for(int i = 1; i < argc; i++){
		switch(*argv[i]){
			case '+' :
				floatarr[i-1] = -1;
				break;
			case '-' :
				floatarr[i-1] = -2;
				break;
			case '*' :
				floatarr[i-1] = -3;
				break;
			case '/' :
				floatarr[i-1] = -4;
				break;
			default :
				floatarr[i-1] = atof(argv[i]);
		}
	}
    // checks for and performes the multiplication/division (see functions)
    // loop skips 1 each time so it only evaluates the operator positions
    // so that input of neg numbers wont break it
    for(int i = 1; i < runlen; i+=2){
        switch((int)floatarr[i]){
            case -3 :
	            multiply(floatarr, argc, i);
                // compinsates for the memmove in the function
                i-=2;
                // stops from running off the end of the 
                // input values after the memmove operation 
                runlen-=2;
                break;
                // same as above
            case -4 :
	            divide(floatarr, argc, i);
                i-=2;
                runlen-=2;
                break;
        }
    }
    // same as above for add and subtract
    for(int i = 1; i < argc; i+=2){
        switch((int)floatarr[i]){
            case -1 :
	            add(floatarr, argc, i);
                i-=2;
                runlen-=2;
                break;
            case -2 :
	            subtract(floatarr, argc, i);
                i-=2;
                runlen-=2;
                break;
         }
    }    
    printf("%.2f ", floatarr[0]);
	return 0;
}

// all functions at the same except for the operation they performe 
//=========================================

void add(float *floatarr, int argc, int i){
    // perormes the operation
	floatarr[i-1] += floatarr[i+1];
    // shifts the arry to remove the performed calculation
	memmove(&floatarr[i], &floatarr[i+2], (argc-i)*4);
}

//=========================================

void subtract(float *floatarr, int argc, int i){

    floatarr[i-1] -= floatarr[i+1];
	memmove(&floatarr[i], &floatarr[i+2], (argc-i)*4);
}

//=========================================

void multiply(float *floatarr, int argc, int i){

	floatarr[i-1] *= floatarr[i+1];
	memmove(&floatarr[i], &floatarr[i+2], (argc-i)*4);
}

//=========================================

void divide(float *floatarr, int argc, int i){

	floatarr[i-1] /= floatarr[i+1];
	memmove(&floatarr[i], &floatarr[i+2], (argc-i)*4);
}


