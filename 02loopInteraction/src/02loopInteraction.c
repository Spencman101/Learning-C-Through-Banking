/*
 ============================================================================
 Name        : 02loopInteraction.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>


// Problem 5 - Lower function
int lower(int number1, int number2)
   {
    if (number1 < number2)
    	return number1;
    return number2;
   }

int main(void) {

	// Problem 1
	// This problem is designed to utilize a menu with switch cases to display to
	// the user their selections, looping until the user picks the choice to end.
	int choice = 0;
    printf("Welcome to Hargrave's weapon smith shop! "
           "We have anything you could need for your adventures!!\n");

    do {
        // Display menu
        printf("\n1. Buy two daggers.\n");
        printf("2. Buy a short sword.\n");
        printf("3. Buy an Axe.\n");
        printf("4. Buy a Shield.\n");
        printf("5. No more purchasing.\n");

        printf("Enter your choice: ");
        fflush(stdout); // Makes sure the question/prompt shows up first before taking an input

        scanf("%d", &choice);

        // Process user choice
        switch (choice) {
            case 1:
                printf("You can acquire two daggers for 6 gold pieces!\n");
                break;
            case 2:
                printf("You can acquire a short sword for 8 gold pieces!\n");
                break;
            case 3:
                printf("You can acquire an axe for 7 gold pieces!\n");
                break;
            case 4:
                printf("You can acquire a shield for 5 gold pieces!\n");
                break;
            case 5:
                printf("So it seems your purchasing is done! Hargrave's shop door is always open!\n");
                break;
            default:
                printf("Well, if you'd like something special, I have a magic item for 10 gold!\n");
        }

    } while (choice != 5);  // Continue until user chooses to exit

    // Problem 2
    // This problem utilizes a for loop to create a temporary variable that is
    // increased by one each run through to display all numbers up to 10.
    printf("\nCounting from 1 to 10\n");
    for(int i = 1; i < 11; i++)
    {
    	printf("%d ", i);
    }

    // Problem 3
    // This problem additionally uses a for loop to instead count down to 1,
    // subtracting 1 from the temporary variable until it reaches 0.
    printf("\nCounting down from 10 to 1\n");
    for(int i = 10; i > 0; i--)
    {
        printf("%d ", i);
    }

    // Problem 4
    // Using predefined variables, 10 floating numbers are gathered from the user
    // these are then parsed through a series of if statements to gather a maximum,
    // minimum, and sum. After which all numbers are displayed out to the user,
    // as well as  the minimum, maximum, and average of the array.
    float numbers[10];
    float maximum;
    float minimum;
    float sum = 0.0;
    for (int i = 0; i < 10; i++) {
        printf("\nEnter a floating point number: ");
        fflush(stdout);

        scanf("%f", &numbers[i]);  // Directly read into array
        if (i == 0)
        {
        	maximum = numbers[0];
        	minimum = numbers[0];
        }
        if (numbers[i] > maximum)
        	maximum = numbers[i];
        if (numbers[i] < minimum)
        	minimum = numbers[i];
        sum += numbers[i];
    }
    printf("\nNumbers you entered:\n");
    for(int i = 0; i < 10; i++)
    {
    	printf("Inputed Number: %g\n", numbers[i]);
    }
    printf("Maximum: %g\n", maximum);
    printf("Minimum: %g\n", minimum);
    printf("Average: %g\n", sum / 10);

    // Problem 5
    // With user inputs, two numbers are passed into a function to find the minimum
    // of the two numbers, which is then displayed to the user.
    int number1;
    int number2;
    printf("\nPlease input two numbers in order to find the lower number.\n");
    printf("Enter the first number: ");
    fflush(stdout);
    scanf("%d", &number1);
    printf("Enter the second number: ");
    fflush(stdout);
    scanf("%d", &number2);

    int min = lower(number1, number2);

    printf("The minimum number is: %d\n", min);

    return 0;
}
