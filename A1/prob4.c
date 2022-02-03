#include <stdio.h>

int main()
{
	/* declaration of the variables 
	 * unsinged indicates there is no internal math operator and the
	 * number can only be positive
	 * short indicates that only 2 bytes should be used for this
	 * variable */
	unsigned short int aval = 65535;
	unsigned short int bval = 0;
	int cval;
	
	/* printing statements that will display each variable name and its
	 * value on the terminal*/
	printf("First printf statement\n");
	printf("\taval: %d\n\tbval: %d\n\tcval: %d\n", aval, bval, cval);
	
	/* redefining bval to aval + 1 (65536) since the unsigned short
	 * int data type can only hold positive numbers up to 65535 it will
	 * roll over to 0 */
	bval = aval + 1;
	
	/* redefining cval to aval + 1  the int data type can store
	 * positive numbers up to 2,147,483647 so this one works as
	 * expected*/
	cval = aval + 1;
	
	// printing the redefined values
	printf("second printf statment:\n");
	printf("\taval: %d\n\tbval: %d\n\tcval: %d\n", aval, bval, cval);

	return 0;
}
