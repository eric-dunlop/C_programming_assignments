#include<stdio.h>
#include<stdlib.h>
#include<string.h>
// function that scans the input string and counts the spaces, 
// ignoring multiple spaces in a row and the first col
int countSpaces(char *mystr)
{
    int count = 0;
    int space = 0;

    while(mystr[count] != '\0')
    {
        if(mystr[count] == ' ' && (count != 0 && mystr[count-1 ] != ' '))
           	 space++;
       		 count++;
    }
    return space;
}

//=====================================
// main accepts agrument count and argument vector from the command line
// are they doing anything in this program?
int main (int argc, char *argv[]){

	char input[94] = "\0";
	char fileCall[101] = "ls -al ";
	// the part I added to allow the user to input a path to a dir.
	printf("Enter the path to a folder\n\n\t: ");
	scanf(" %93[^\n]s", input);
	scanf("%*[^\n]%*c");
	for(int i = 0; i < sizeof(fileCall); i++){
		if(input[i] != '\0'){
			fileCall[7+i] = input[i];
		}
	}
	// grabs the information displayed by the command "ls -al /usr/include"
    FILE *program_output = popen(fileCall, "r");
	// if nothing is returned by "ls -al /usr/include" the program exits
    if(program_output == NULL)
    {
        printf("Quitting\n");
        exit(-1);
    }
	// declares 2 strings and a string pointer
    char buf[92] = {"\0"};
    char perms[11] = "\0";
    char *str;
	// prints the top of the table spaces between the titles
    printf("\t===========================================================\n");
    printf("\t     %s %22s\n", "Permissions", "Directories/Files");
    printf("\t===========================================================\n");
	// saves each line to the buffer one at a time until it reaches end of file
    while( fscanf(program_output, "%[^\n]", buf) != EOF )
    {
    	// gets the next char from the output and casts it to int
    	// removes the LF char for the current cycle
    	//printf("%d\n", fgetc(program_output));
        fgetc(program_output);
        
        // checks for directories and symbolic links
        // added '-' to print files as per Q1
        if( buf[0] == 'd' || buf[0] == 'l' || buf[0] == '-')
        {
        	// count the spaces in the buffer using the function 
            int spaces = countSpaces(buf);
            // strtok() breaks the string into seperate tokens at each set of spaces
            // copy first token in the buffer to perms
            strncpy(perms, strtok(buf, " "), 10);
			
            while(spaces > 0)
            {
            	// continues cutting out the next token until it runs out 
            	// of spaces saves the last one to str
                str = strtok(NULL, " ");
                spaces--;
            }
            // prints the permissions for directories and symbolic links
            // in an easier to read formatt
            fprintf(stdout, "\t%15s     -->     %-30s\n", perms, str);
         }
    }
    // closes the popen() from the top
    pclose(program_output);
    return 0;
}

