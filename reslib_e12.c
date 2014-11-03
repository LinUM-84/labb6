#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

int main ( int argc, char* argv[] ) {

	/* use E12 series resistor values */ 
	float resistance[] =	{1, 1.2, 1.5, 1.8, 2.2, 2.7, 3.3, 
				 3.9, 4.7, 5.6, 6.8, 8.2, 10, 12, 
				 15, 18, 22, 27, 33, 39, 47, 56, 68,
				 82, 100, 120, 150, 180, 220, 270, 
				 330, 390, 470, 560, 680, 820, 1000,
				 1200, 1500, 1800, 2200, 2700, 3300,
				 3900, 4700, 5600, 6800, 8200, 10e3,
				 12e3, 15e3, 18e3, 22e3, 27e3, 33e3,
				 39e3, 47e3, 56e3, 68e3, 82e3, 10e4,
				 12e4, 15e4, 18e4, 22e4, 27e4, 33e4,
				 39e4, 47e4, 56e4, 68e4, 82e4, 10e5,
				 12e5, 15e5, 18e5, 22e5, 27e5, 33e5,
				 39e5, 47e5, 56e5, 68e5, 82e5, 10e6};
	int e12count = 61;

	/* Print all values in the array*/

	printf("E12 resistance series consists of:\n");
	int i;
	for (i=0; i < e12count; i++) {

		
		printf("%.1f\n", resistance[i]);


	}
	printf("Print-out complete\n");
}



