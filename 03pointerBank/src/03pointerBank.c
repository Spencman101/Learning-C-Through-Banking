/*
 ============================================================================
 Name        : 03pointerBank.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>


// Task 1- Function 1
// Function path to ask for a number to modify and display
// along with the original.
void function(int value)
{
	value += 3;
	printf("New number: %d\n", value);
}

// Task 1- Function 2
// This function is used to demonstrate how passing by
// reference allows the original variable to actually be
// changed rather than just the copy of it.

void integerPointer(int* ptr)
{
	*ptr += 3;
	printf("\nModified pointer: %d", *ptr);
}


// Task 2
	// The following code is to simulate the underlying functions
	// of a bank account, containing base info that would then be
	// modified. This is done by using a structure that is accessed
	// through pointers to change core data, the pointers are then
	// used again to display the modified user information to verify.
struct bank
{
	int accountNum;
	char name[50];
	float balance;
};

void inputInfo(struct bank* ptr)
{
	printf("\nPlease enter your account number: ");
	fflush(stdout);
	scanf("%d", &ptr->accountNum);

	printf("\nPlease enter the name under your account: ");
	fflush(stdout);
	scanf("%s", ptr->name);

	printf("\nPlease enter your account balance: ");
	fflush(stdout);
	scanf("%f", &ptr->balance);
}

void displayInfo(struct bank* ptr)
{
	printf("\nAccount info: Number-%d Name-%s Balance-%f", ptr->accountNum, ptr->name, ptr->balance);

}

int main(void) {

	// Task 1- Function 1
	// This is to demonstrate passing parameters
	// (function receives copy, changes made don't
	// affect original variable).
	int userValue;

	printf("\nPlease input a whole number: ");
	fflush(stdout);
	scanf("%d", &userValue);

	function(userValue);
	printf("\nOriginial User Input: %d", userValue);

	// Task 1 - Function 2
	integerPointer(&userValue);
	printf("\nModified original: %d\n", userValue);


	// Task 2 - Bank
	struct bank myAccount;
	inputInfo(&myAccount);
	displayInfo(&myAccount);


	return EXIT_SUCCESS;
}



