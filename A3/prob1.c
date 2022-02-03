/* Author Eric Dunlop
 * Date: Oct, 2021
 * Discription: change to title case or reverse 
 */
#include <stdio.h>
//function that takes in arrays of the alphabit in upper and lower case 
void titleSet(char *first, char *rest){
	char input[41];
	printf("\nPlease enter a string max 40 digits\n\n");
	scanf(" %[^\n]s", input);
	printf("\n****************************\n\n");
 	for(int i = 0; i < sizeof(input); i++){
		for(int j = 0; j < 26; j++){
			//check input[0] and sets it to the correct case
			if((i == 0) && (input[i] == rest[j] || input[i] == first[j])){
				input[i] = first[j];
			}
			//scan for " " and set the next char 
			else if((input[i] == ' ') && (input[i+1] == rest[j] ||
					 input[i+1] == first[j])){
				input[i+1] = first[j];	
				//skips the letter we just changed 		
				i++;
			}
			//sets every other letter
			else if(input[i] == first[j] || input[i] == rest[j]){
				input[i] = rest[j];
			}
		}
	}
		printf("In title case:    %s\n\n", input);
}
int main(){
	char lower[] = "abcdefghijklmnopqrstuvwxyz";
	char upper[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int tcase = '1';
	while(tcase == '1' || tcase == '2'){	
		printf("\n****************************\n\n");
		printf("Please select and option\n\n");
		printf("  1. For Title Case\n");
		printf("  2. fOR rEVERSE tITLE cASE\n");
		printf("  Q. to exit\n\n");
		printf("Selection: ");
		scanf(" %c", &tcase);
		if(tcase == '1'){
			titleSet(upper, lower);
		}
		else if(tcase == '2'){
			titleSet(lower, upper);
		}
		// any other input exits the program
		else{
			printf("\nThank You,\nhave a wonderful day\n\n");	
		}
	}
	return 0;
}
