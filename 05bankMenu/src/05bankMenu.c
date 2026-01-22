/*
 ============================================================================
 Name        : 05bankMenu.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

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

	ptr->next = NULL;
}

void displayInfo(struct account* ptr)
{
	printf("\nAccount info: Number-%d Name-%s Balance-%f", ptr->accountNum, ptr->name, ptr->balance);

}

void displayAllInfo(struct account* ptr)
{
	while (ptr != NULL)
	{
		displayInfo(ptr);
		ptr = ptr->next;
		printf("\n");
	}
}

void menu()
{
	printf("\nMain menu:\n");
	printf("\t1. Add an Account\n\t2. Display all accounts\n\t3. Find account\n\t4. Edit Account\n\t5. Quit program\n");
	printf("Your choice: ");
}

void editMenu()
{
	printf("\nEdit Menu:\n");
	printf("1. Account Number\t2. Account Name\t3. Account Balance\n");
	printf("Your choice: ");
}

void editAcc(int choice, struct account* ptr)
{
	if (choice == 1)
	{
		printf("\nPlease enter your new account number: ");
		fflush(stdout);
		scanf("%d", &ptr->accountNum);
	}
	if (choice == 2)
	{
		printf("\nPlease enter the new name under your account: ");
		fflush(stdout);
		scanf("%s", ptr->name);
	}
	if (choice == 3)
	{
		printf("\nPlease enter your new account balance: ");
		fflush(stdout);
		scanf("%f", &ptr->balance);
	}
}

int main(void) {

	struct account *head = NULL;
	int choice;

	do {
		menu();
		fflush(stdout);
		scanf("%d", &choice);
		if (choice == 1)
		{
			struct account *new_acc  = (struct account*)malloc(sizeof(struct account));
			inputInfo(new_acc);
			new_acc->next = NULL;
			if (head == NULL)
			{
				head = new_acc;
			}
			else
			{
				struct account* tail  = head;
				while (tail->next != NULL)
				{
					tail = tail->next;
				}
				tail->next = new_acc;
			}
		}
		if (choice == 2)
			displayAllInfo(head);
		if (choice == 3)
		{
			int acc_num;
			printf("What is the account number:");
			fflush(stdout);
			scanf("%d", &acc_num);

			struct account *current = head;
			int found = 0;
			while (current != NULL)
			{
				if (current->accountNum == acc_num)
				{
					printf("Found account: ");
					displayInfo(current);
					found = 1;
					break;
				}
				current = current->next;
			}
			if (!found)
			{
				printf("Account not found.\n");
			}
		}
		if (choice == 4)
		{
			int acc_num;
			printf("What is the account number:");
			fflush(stdout);
			scanf("%d", &acc_num);
			struct account *current = head;
			int found = 0;
			while (current != NULL)
			{
				if (current->accountNum == acc_num)
				{
					printf("Found account: ");
					displayInfo(current);
					found = 1;
					editMenu();
					int editChoice;
					fflush(stdout);
					scanf("%d", &editChoice);
					editAcc(editChoice, current);
					displayInfo(current);
					break;
				}
				current = current->next;
			}
			if (!found)
			{
				printf("Account not found.\n");
			}
		}
	} while (choice != 5);
	return EXIT_SUCCESS;
}
