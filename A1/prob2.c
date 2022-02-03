/* Author Eric Dunlop 
 * Date: Sept 14, 2021
 * Discription: Accepting inputs of charaters 
 */
#include <stdio.h>
int main()
{
	char userInput;
	// opening of menue 
	printf("******************************************\n");
	printf("******************************************\n\n");
	printf(" S. Snowboarding\n");
	printf(" J. Juggling\n");
	printf(" P. Playing Guitar\n");
	printf(" H. Hiking\n");
	printf(" C. Climbing\n");
	printf(" G. Golfing\n");
	printf(" W. Writing Code\n");
	printf(" B. Burning Things\n\n");
	printf("What would you like to do today?\n");
	printf("Please select the letter of your choice: ");
	// accepts the input 
	scanf("%c", &userInput);
	// confirmation of input.
	printf("\nYou Have selected %c.\n", userInput);
	printf("Thank you and enjoy your day ");
	// checks the input and customizes the output
	switch(userInput){
		case 'S' :
			printf("snowboarding.");
			break;
		case 'J' :
			printf("juggling.");
			break;
		case 'P' :
			printf("playing guitar.");
			break;
		case 'H' :
			printf("hiking.");
			break;
		case 'C' :
			printf("climbing.");
			break;
		case 'G' :
			printf("golfing.");
			break;
		case 'W' :
			printf("writing Code.");
			break;
		case 'B' :
			printf("burning things.");
			break;
			//covers cases where input isn't on list
		default :
			printf("doing whatever.");
			
	}
	printf("\n\n******************************************\n");
	printf("******************************************\n");

	return 0;
}
