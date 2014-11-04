#include <stdio.h>
#include <math.h>
#include "resistancecalc.h"
#include "test_rescalc.h"

/* Define the maximum allowable length for data entry */
#define MAX_STRING_LENGTH 512

int main ( int argc, char* argv[] ) {
	

	runTestCaseScenarios();
	return 0;

}

void runTestCaseScenarios() {

	int tcCount = 8;
	int tcStatus[tcCount];

	/* Test case 1: zero pointer */
	/* Expected result: -1 */
	float expectedResult = -1;
	float *zeroarray = 0;
	int count = 10;
	char conn = 'P';
	int tc = 1;
	char *tcDesc = "Zero pointer";
	tcStatus[tc-1] = runTestCase(tc, tcDesc, expectedResult, count, conn, zeroarray);
	
	/* Test case 2: Ten resistors connected in series where R=5*x and 0<x<=10 */
	expectedResult = 275;
	float array[10] = {5,10,15,20,25,30,35,40,45,50};
	count = 10;
	conn = 'S';
	tc = 2;
	tcDesc = "Ten resistors in series where R=5*x and 0<x<=10";
	tcStatus[tc-1] = runTestCase(tc, tcDesc, expectedResult, count, conn, array);

	/* Test case 3: Ten resistors connected in paralell where R=5*x and 0<x<=10 */
	expectedResult = 1.707086;
	count = 10;
	conn = 'P';
	tc = 3;
	tcDesc = "Ten resistors in paralell where R=5*x and 0<x<=10";
	tcStatus[tc-1] = runTestCase(tc, tcDesc, expectedResult, count, conn, array);

	/* Test case 4: Paralell connection with a zero ohm resistor */
	expectedResult = 0;	
	float array2[10] = {5,10,15,0,25,30,35,40,45,50};
	count = 10;
	conn = 'P';
	tc = 4;
	tcDesc = "Paralell connection with a zero ohm resistor";
	tcStatus[tc-1] = runTestCase(tc, tcDesc, expectedResult, count, conn, array2);

	/* Test case 5: Incorrect parameters - connection mode*/
	expectedResult = -1;	
	count = 10;
	conn = 'A';
	tc = 5;
	tcDesc = "Incorrect parameters - connection mode";
	tcStatus[tc-1] = runTestCase(tc, tcDesc, expectedResult, count, conn, array);

	/* Test case 6: Incorrect parameters - number of components */
	expectedResult = -1;	
	float array3[1] = {5};
	count = 1;
	conn = 'P';
	tc = 6;
	tcDesc = "Incorrect parameters - number of components";
	tcStatus[tc-1] = runTestCase(tc, tcDesc, expectedResult, count, conn, array3);


	/* Test case 7: entire E12 resistor list connected in series*/
	expectedResult = 5766619;
	float array4[61] =	{10, 12, 15, 18, 22, 27, 33, 39, 47, 56, 68, 82,
				 100, 120, 150, 180, 220, 270, 330, 390, 470, 560, 680, 820,
				 1000, 1200, 1500, 1800, 2200, 2700, 3300, 3900, 4700, 5600, 6800, 8200,
				 10e3, 12e3, 15e3, 18e3, 22e3, 27e3, 33e3, 39e3, 47e3, 56e3, 68e3, 82e3,
				 10e4, 12e4, 15e4, 18e4, 22e4, 27e4, 33e4, 39e4, 47e4, 56e4, 68e4, 82e4,
				 10e5};
	count = 61;
	conn = 'S';
	tc = 7;
	tcDesc = "entire E12 resistor list connected in series";
	tcStatus[tc-1] = runTestCase(tc, tcDesc, expectedResult, count, conn, array4);

	/* Test case 8: entire E12 resistor list connected in paralell*/
	expectedResult = 1.764631;
	count = 61;
	conn = 'P';
	tc = 8;
	tcDesc = "entire E12 resistor list connected in paralell";
	tcStatus[tc-1] = runTestCase(tc, tcDesc, expectedResult, count, conn, array4);
	
	int i, tcSuccesses = 0, tcFailures = 0;
	
	for (i=0;i<tcCount;i++) {
		
		if (tcStatus[i] == 1)
			tcSuccesses++;
		else if (tcStatus[i] == 0)
			tcFailures++;
		
	}

	printf("Summary: after testing %d test cases, %d succeded and %d failed!\n", tcCount, tcSuccesses, tcFailures);

}

int runTestCase ( int testCase, char* testCaseDesc, float expectedResult, int count, char conn, float *array ) {

	/* Use function calc_resistance to perform processing and calculation */
	float resultingResistance = calc_resistance(count, conn, array); 
	char *result;
	int passed;
	float rresult = roundf(resultingResistance * 1000000) / 1000000;

	if ( rresult == expectedResult ) {
		result = "passed";
		passed=1;
	}
	
	else {
		result = "failed";
		passed=0;

	}
	
	printf ("\nExecuting testcase #%d: %s\n", testCase, testCaseDesc);
	printf ("Expected result was %.4f, actual result was %.4f\n", expectedResult, rresult);
	printf ("Test case #%d %s\n", testCase, result);

	return passed;

}
