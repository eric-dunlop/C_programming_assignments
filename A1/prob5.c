#include <stdio.h>

int main()
{
	//changed both variable names to be diffent and more descriptive
	int valueInt = 2;
	
	//changed the "-" to an "=" and added ";".
	float valueFloat = 25.8;
	
	//changed variable names to match in the rest of the program.
	printf("Float: %f, Interger: %d\n", valueFloat, valueInt); 
	
	valueInt = (int) valueFloat;
	printf("Float: %f, Interger: %d\n", valueFloat, valueInt);
	
	return 0; 
}
