/* Author Eric Dunlop 
 * Date: Sept 21, 2021
 * Discription: printing variable info
 */
#include <stdio.h>
int main()
{
	short int aval = 100;
	int bval = 100;
	float cval = 100;
	double dval = 100;
	char eval = 100;
	unsigned char fval = 100;
	//for each type the required info is printed
	printf("Address of aval: %p\nValue of aval: %d\nSize of aval: %ld bytes\n", &aval, aval, sizeof(aval));
	printf("*********************************\n");
		
	printf("Address of bval: %p\nValue of bval: %d\nSize of bval: %ld bytes\n", &bval, bval, sizeof(bval));
	printf("*********************************\n");
	
	printf("Address of cval: %p\nValue of cval: %0.2f\nSize of cval: %ld bytes\n", &cval, cval, sizeof(cval));
	printf("*********************************\n");
	
	printf("Address of dval: %p\nValue of dval: %0.2lf\nSize of dval: %ld bytes\n", &dval, dval, sizeof(dval));
	printf("*********************************\n");
	
	printf("Address of eval: %p\nValue of eval: %c\nSize of eval: %ld bytes\n", &eval, eval, sizeof(eval));
	printf("*********************************\n");
	
	printf("Address of fval: %p\nValue of fval: %u\nSize of fval: %ld bytes\n", &fval, fval, sizeof(fval));
	
	return 0;
}
