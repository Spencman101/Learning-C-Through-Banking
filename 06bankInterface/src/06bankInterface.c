/*
 ============================================================================
 Name        : 06bankInterface.c
 Author      : Spencer Reynolds
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct account account; // Establishes struct account, and lets me use just account without struct
typedef struct user user_t; // Similar to above, defining struct user, but using user_t as it's name in code
typedef struct userList userList_t; // Same here

// The following code is to simulate the underlying functions
// of a bank account, containing base info that would then be
// modified. This is done by using a structure that is accessed
// through pointers to change core data, the pointers are then
// used again to display the modified user information to verify.
struct account
{
	int accountNum;
	char name[50];
	float balance;
	struct account *next;
};

struct user
{
	char username[15];
	char password[15];
	account *accounts;
};

struct userList
{
	user_t user_entry;
	userList_t *user_next;
};

// Sets the global head pointers
userList_t *userHead = NULL;
struct account *head = NULL;

// This function is needed to compare 2 strings,
// 		as it is something standard C can't do
int stringEquals(char *str1, char *str2)
{
	while (*str1 && *str2)
	{
		if (*str1 != *str2)
			return 0;
		str1++;
		str2++;
	}
	return *str1 == '\0' && *str2 == '\0';
}

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

// This function takes a pointer from 1 account to call a print function,
// after which it then access the next variable of the structure to find
// the next account to print out.
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

// This is to demonstrate passing parameters
// (function receives copy, changes made don't
// affect original variable).
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

void startMenu()
{
	printf("Welcome to the banking interface, made to simulate everything "
			"a user would traditionally interact with in a bank.");
	printf("You will first be prompted to login, or create an account. Enjoy!");
}

void loginMenu(char* username, char* password) // Passing in char* as I need entire string, as it's a char
{
	printf("\nSign in\n");
	printf("\n\tEnter Username:");
	fflush(stdout);
	scanf("%s", username);
	printf("\n\tEnter Password:");
	fflush(stdout);
	scanf("%s", password);
}

int verifyLogin(char* username, char* password)
{
	userList_t *current = userHead;
	while (current != NULL) {
		if (stringEquals(current->user_entry.username, username) &&
			stringEquals(current->user_entry.password, password)) {
			printf("Found account: ");
			displayInfo(current->user_entry.accounts);
			return 1;
		}
		current = current->user_next;
	}
	printf("Account does not exist.\n");
	return 0;
}

void bankInteraction()
{
	int choice;

		do {
			menu();
			fflush(stdout);
			scanf("%d", &choice);

			if (choice == 1) // Add Account
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
			if (choice == 2) // Display All Accounts
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
			if (choice == 4) // Find Account
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
}


int main(void)
{

	// Not first* as I need the object as a whole, not its contents
	// Initialize three accounts completely rather than needing to user pointers like first->name
	account first = {123, "Bill", 4567.89, NULL};
	account second = {456, "Bob", 7891.23, NULL};
	account third = {789, "Joy", 3120.75, NULL};

	// Link accounts to users
	user_t users[] = {
		{"BillWill", "Billing96", &first},
		{"MoneyBobbing", "Jr87", &second},
		{"JoeyTheMan", "Kangaroo64", &third}
	};

	// Build the user linked list from array
	for (int i = 0; i < 3; ++i) {
		userList_t* newNode = (userList_t*)malloc(sizeof(userList_t));
		newNode->user_entry = users[i];
		newNode->user_next = userHead;
		userHead = newNode;
	}

	startMenu();

	char username[15];
	char password[15];
	 // Verifies that the user is logged in (needed for program)
	int loggedIn = 0;
	do {
		loginMenu(username, password);
		loggedIn = verifyLogin(username, password);
		if (!loggedIn) // Can do this here as its now a boolean, checking if its 1 or 0
		{
			// Demonstrating interacting with characters rather than switch case
			char response;
			printf("Would you like to try again (T)? or create an account (C)?" );
			fflush(stdout);
			scanf(" %c", &response); // Space needed in case of entries on a new line
			if (response == 'C' || response == 'c') // Case shouldn't matter
			{
				userList_t* newUser = (userList_t*)malloc(sizeof(userList_t));
				printf("\nCreating new account.\n");
				printf("Enter new username: ");
				fflush(stdout);
				scanf("%s", newUser->user_entry.username);
				printf("Enter new password: ");
				fflush(stdout);
				scanf("%s", newUser->user_entry.password);

				newUser->user_entry.accounts = NULL; // start with no accounts
				newUser->user_next = userHead;
				userHead = newUser;

				loggedIn = 1;
			}
			// The else statement is unneeded, as it will prompt login again if the user doesn't create an account
		}
	} while (!loggedIn);

	editMenu();
	bankInteraction();

	return EXIT_SUCCESS;
}

