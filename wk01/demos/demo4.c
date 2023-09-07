/**
 * @file demo4.c
 * @author Ian Toy (iantoy@uab.edu)
 * @brief For this version of our temperature table we use a different helper 
 * function that further consolidates the work done in the previous examples.
 * @version 0.1
 * @date 2023-03-30
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <stdio.h>

/** For this version, we implement a different function called print_ftoc(), 
 * which further abstracts the work done by our previous code examples. Since
 * this function doesn't return a value, we set its return type to void.
*/
void print_ftoc(float f); /* Prints a line of a F to C conversion table */

int main(){

	float fahr, celsius;
	int lower, upper, step;

	upper = 300;
	lower = 0;
	step = 20;
	fahr = lower;

	printf("F to C Conversion Table\n"); /* Table header */

	/* Print the conversion table */
	while (fahr <= upper) {		
		/** print_ftoc the work of converting a temperature in fahrenheit to 
		 * celsius then printing both temperatures in a new line. */
		print_ftoc(fahr);
		fahr += step; /* Increment fahr by the step size. */ 
	} /* end while(fahr <= upper) loop */
} /* end main() */

/** print_ftoc() accepts a float, f, performs a conversion then prints the next
 * line of our temperature table. Since print_ftoc() doesn't return anything, 
 * we set its return type to void */
void print_ftoc(float f){
	float c;
	c = (5.0/9.0) * (f - 32.0);
	printf("%3.0f%6.1f\n", f, c); 
} /* end print_ftoc() */


