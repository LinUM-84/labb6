#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "electrotest.h"
#include "libresistance.h"
#include "libpower.h"

/* Define the maximum allowable length for data entry */
#define MAX_STRING_LENGTH 20

void powerCalc(char* str);

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
	
	/* Parse the entry */
	long menuChoice = parseMenuSelection(str);
	
	/* Perform desired action */
	switch (menuChoice) {

	case 1:
		resCalc(str);
		break;

	case 2:
	        powerCalc(str); 
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

void powerCalc(char* str){

  	printf("Räkna från resistans eller ampere? (r | a). Ange q för att gå tillbaka till menyn. \n"); 
  	fgets (str, MAX_STRING_LENGTH, stdin); 

  	float amp = 0; 
  	float resistance = 0; 
  	float volt = 0; 
  	float watt = 0; 

  	switch(str[0]){

  	case 'r':
    		printf("Ange ressistansen (ohm): ");
    		fgets (str, MAX_STRING_LENGTH, stdin); 
   		 resistance = strtof(str, NULL); 
    
    		printf("Ange volt: "); 
    		fgets (str, MAX_STRING_LENGTH, stdin); 
    		volt = strtof(str, NULL); 

    		watt = calc_power_r(volt, resistance); 
    
    		printf("Watt: %.2f \n", watt); 
    	break; 

  	case 'a':
    		printf("Ange flödet (amp): ");
    		fgets (str, MAX_STRING_LENGTH, stdin); 
   		amp = strtof(str, NULL); 
    
    		printf("Ange volt: "); 
    		fgets (str, MAX_STRING_LENGTH, stdin); 
    		volt = strtof(str, NULL); 

    		watt = calc_power_i(volt, amp); 
    		printf("Watt: %.2f \n", watt); 

    	break;

  	case 'q':
    	break;

  	default:
    		powerCalc(str); 
    	break;
  	}
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

float resCalc(char* str) {

	/* Allocate memory for the string of numbers */
	
	long count = -1;
	do {
		printf("Hur många komponenter vill du ange? ");
		count = getInt(str);
	
	} while (count == -1 || count < 0);

	
	float *array = malloc (count * sizeof(float));
	if (str == NULL) {

		printf("Otillräckligt ledigt minne");
		return -1;

	}
	
	int i;
	
	for (i=0;i<count;i++) {
		
		long r = -1;
		do {
		printf("\nAnge resistans för resistor %d: ", (i+1));
		r = getInt(str);
		
		} while (r == -1 || r < 0);
		
		array[i]=r;
		
	}
	
	char conn = 'x';
	long choice = -1;
		
	do {
	
	printf("Vill du beräkna ersättningsresistans vid serie- (1) eller parallell-koppling (2)? ");
	choice = getInt(str);
	
	if (choice == 1)
		conn = 'S';
	else if (choice == 2)
		conn = 'P';
	} while (choice == -1 || choice < 1);
	
	/*fgets(str, MAX_STRING_LENGTH, stdin);
	const char* matches = "PS";
	if (strchr(matches, str[0]) != NULL) {
		strncpy(str, conn, 1);
		printf("\nConn är %s", conn);
	}*/
	
	float result = calc_resistance(count, conn, array);
	printf("\nErsättningsresistansen är: %.2f\n", result);
	return result;

}

/* getInt reads a long from standard in */
long getInt(char* str) {
	
	long int i;
	char *rest;
  
	if (fgets(str, MAX_STRING_LENGTH, stdin) != NULL) {
		i = strtol(str, &rest, 0);
    
		if (str[0] != '\n' && (*rest == '\n' || *rest == '\0'))
			return i; 
		else 
			return -1;
	}  
}
