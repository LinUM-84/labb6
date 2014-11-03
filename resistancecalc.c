#include <stdbool.h>
#include <stdio.h>
#include <float.h>
#include "resistancecalc.h"

float calc_resistance ( int count, char conn, float *array ) {

	/* Process the parameters to decide which connection method to use */
	/* Check that we have more than zero components and a valid value for series or parallell connection */

	if ((count<2) || (conn != 'P' && conn != 'S')) {
		
		printf("Debug: count=%d, conn=%c", count, conn);
		return -1; /* Return the value of -1 to indicate erroneous input parameters */

	}

	
	/* Process the array of resistors*/
	
	int i;
	float resultingResistance = 0;
	bool isLast = false;
	bool isFirst = true;
	float curResistance=0, lastResistance=0, nxtResistance=0, maxResistance=0, minResistance=FLT_MAX;

	for (i=0; i < count; i++) {

		/* Get current resistance value */		
		curResistance=array[i];

		if (curResistance>=maxResistance)
			maxResistance=curResistance;
		if (curResistance<=minResistance)
			minResistance=curResistance;
		if (i == (count-1))
			isLast = true;
		

		switch (conn) {

			case 'P':
			/* Sanity check, check for zero values */
			if (curResistance == 0)
				return 0;

			if (isFirst) { /* Check if we are processing the first resistance */
				printf("Debug: First if true at iteration %d\n", i);
				nxtResistance = array[i+1];
				lastResistance = add_paralell(curResistance, nxtResistance);
				//i++; /* Pad the counter to offset for paralell addition */
				
			}

			else if (!isLast) { /* Check if we are processing a resistance which is neither the first nor the last */
				printf("Debug: Second if true at iteration %d\n", i);
				nxtResistance = array[i+1];
				lastResistance = add_paralell(lastResistance, nxtResistance);

			}

			else if (isLast) { /* Check if we are processing the last resistance */
				printf("Debug: Third if true at iteration %d\n", i);
				resultingResistance = lastResistance;

			}

			printf("Debug: conn=%c, i=%d, lastResistance=%f, curResistance=%f, nxtResistance=%f, resultingResistance=%f\n", conn, i, lastResistance, curResistance, nxtResistance, resultingResistance);
			
			break;

			case 'S':
			resultingResistance+=array[i];
			break;
		}
		

		isFirst = false; /* Set the isFirst flag to false after first loop */
	}

	printf("Debug: conn=%c, i=%d, maxResistance=%f, minResistance=%f, resultingResistance=%f\n", conn, i, maxResistance, minResistance, resultingResistance);

	/* Sanity check */
	/* For resistors connected in paralell the resulting sum must be less than the smallest ingoing resistor */
	if (conn == 'P' && resultingResistance < minResistance) {
			
		return resultingResistance;	/* Return the calculated value */		
			
	}

	else {

		return -1; /* Return -1 indicating an error */

	}

	/* For resistors connected in series the resulting sum must be greater than the largest ingoing resistor */
	if (conn == 'S' && resultingResistance > maxResistance) {
			
		return resultingResistance; /* Return the calculated value */
			
	}

	else {

		return -1; /* Return -1 indicating an error */

	}

}

float add_paralell ( float res1, float res2 ) {

	return (res1*res2/(res1+res2));

}
