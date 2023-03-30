/**
 * @file demo3.c
 * @author Ian Toy (iantoy@uab.edu)
 * @brief For this version of our temperature table we use helper functions.
 * @version 0.1
 * @date 2023-03-30
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <stdio.h>

/** Here we have a function prototype. Like declaring a variable before
 * assigning it a value, we declare a function before defining the work that
 * it does. We do this before main() so that main() knows that these functions
 * exist. When we declare a function, we first write the data type that the 
 * function returns, the name of the function, and then in parenthesis the 
 * parameters that it expects. */

float ftoc(float f); /* Converts a temperature in Fahrenheit to Celsius */

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
		/* We call ftoc() to convert fahr to celsius and store it there */
		celsius = ftoc(fahr);
		printf("%3.0f %6.1f\n", fahr, celsius); /* Print the next line */
		
		fahr += step; /* Increment fahr by the step size. */ 
	} /* end while(fahr <= upper) loop */
} /* end main() */

/** Here we have our function definition. ftoc() accepts a float, f, as an 
 * argument and returns a float. */
float ftoc(float f) { /* Here is our definition of ftoc() */
	return (5.0/9.0) * (f - 32);
} /* end ftoc() */