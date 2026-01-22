/*
 ============================================================================
 Name        : 04bankAccounts.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

// The following 3 functions are reused from 03pointerBank
// Past Explanation: using a structure that is accessed
// through pointers to change core data
struct account
{
	int accountNum;
	char name[50];
	float balance;
	struct account *next;
};

void inputInfo(struct account* ptr)
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

void displayInfo(struct account* ptr)
{
	printf("\nAccount info: Number-%d Name-%s Balance-%f", ptr->accountNum, ptr->name, ptr->balance);

}


// Task 2
// This function takes a pointer from 1 account to call a print function,
// after which it then access the next variable of the structure to find
// the next account to print out.
void displayAllInfo(struct account* ptr)
{
	while (ptr->next != NULL)
	{
		displayInfo(ptr);
		ptr = ptr->next;
	}
	displayInfo(ptr);
}

int main(void) {

	// Task 1
	// The following code allocates data for 3 structures using malloc,
	// then pre-establishes the 'next' variable to connect the structs'.
	struct account *first  = (struct account*)malloc(sizeof(struct account));
	struct account *second = (struct account*)malloc(sizeof(struct account));
	struct account *third  = (struct account*)malloc(sizeof(struct account));

	first->next  = second;
	second->next = third;
	third->next  = NULL;

	inputInfo(first);
	inputInfo(second);
	inputInfo(third);

	displayAllInfo(first);
	return EXIT_SUCCESS;
}
