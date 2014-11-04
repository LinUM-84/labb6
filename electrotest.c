#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "electrotest.h"

/* Define the maximum allowable length for data entry */
#define MAX_STRING_LENGTH 20

int main ( int argc, char* argv[] ) {
	
	/* Allocate memory for the string of numbers */
	char *str = malloc (MAX_STRING_LENGTH);
	if (str == NULL) {

		printf("No memory available\n");
		return 1;

	}
	
	int menuChoice = 0;
	do {
		menuChoice = start(str);

	} while ( menuChoice != 4 );

	/* Cleanup, free memory and exit */
	free (str);
	return 0;

}

int start(char* str) {

	/* Ask the user to select a function */
	printf("%s", generateMenu());

	fgets (str, MAX_STRING_LENGTH, stdin);

	//printf("Input %s", str);

	/* Parse the entry */
	long menuChoice = parseMenuSelection(str);
	
	/* Perform desired action */
	switch (menuChoice) {

	case 1:
		
		break;

	case 2:
		break;

	case 3:
		break;

	case 4:
		
		break;

	default:
		break;



	}

	return menuChoice;



}

long parseMenuSelection(char* str) {

	/* Process the entered string and remove an eventual newline character */
	/* If length of the entered string is greater than zero and the last character is a newline, remove it */
	if ((strlen(str)>0) && (str[strlen (str) - 1] == '\n')) {
		str[strlen (str) - 1]='\0';
	}
	
	/* Process the array */
	
	long menuChoice = strtol(str, NULL, 0);

	if (menuChoice > 0 && menuChoice < 6)
		return menuChoice;
	else
		return -1;
	
}

char* generateMenu() {

	char *menuString = 	"***Electrotest menu***\n"
				"1. Beräkna ersättningsresistans\n"
				"2. Beräkna värmeutveckling i resistor\n"
				"3. Hitta ersättningsresistorer i E12-serier\n"
				"4. Avsluta\n"
				"Välj en funktion: ";

	return menuString;

}
