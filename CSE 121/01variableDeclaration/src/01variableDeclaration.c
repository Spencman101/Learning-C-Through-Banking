/*
 ============================================================================
 Name        : 01variableDeclaration.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main() {

	// Declare integer
	int number;

	// Input number
	printf("Enter the integer: ");
	scanf("%d", &number);

	// Display number
	printf("Number inputed by user: %d\n", number);


	// Declare floating point value
	float decimal;

	// Input decimal
	printf("Enter the decimal: ");
	scanf("%f", &decimal);

	// Display decimal
	printf("Scientific version of decimal: %e\n", decimal);
	printf("Fixed Point version of decimal: %2.3f\n", decimal);
	printf("Shortest version of decimal: %g\n", decimal);

	// Declare array
	char str[50];

	// Input array
	printf("Enter the string: ");
	scanf("%s", str);

	// Display string
	printf("Here is the string: %s\n", str);


	// Declare duo numbers
	int num1;
	int num2;

	// Input duo numbers
	printf("Enter the first number: ");
	scanf("%d", &num1);
	printf("Enter the second number: ");
	scanf("%d", &num2);

	// Print out the minimum
	if (num1 < num2)
		printf("The minimum is: %d\n", num1);
	else
		printf("The minimum is: %d\n", num2);

	return 0;
}
