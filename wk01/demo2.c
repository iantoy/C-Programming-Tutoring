/* The purpose of this program is to print a short Fahrenheit to Celsius 
 * temperature conversion table. This code is from p. 12 of The C Programming
 * Language by Kernigan and Ritchie. */

#include <stdio.h>

int main() { 

	/** Like in our ftoc_int.c code, we declare our variables here. If you want
	 * to declare multiple variables of the same type, you can do so in one
	 * line by writing the data type followed by the variable names seperated
	 * by commas, as shown below */
	float fahr, celsius;
	int lower, upper, step;

	/* Variable assignments. */
	lower = 0; 		/* Lower limit. */
	upper = 300; 	/* Upper limit. */
	step = 20; 		/* Step size. */

	fahr = lower; /* What happens when we assign an int to a float? */

	printf("F to C Conversion Table\n"); /* Table header */

	while (fahr <= upper) { /* While fahr is less than or equal to upper... */

		/* Floating point arithmetic */
		celsius = (5.0/9.0) * (fahr - 32.0);

		/** The format specifiers here provide some more information about how
		 * we want the floats to be displayed in this print statement. "3.0" 
		 * indicates that we want to reserve 3 characters width to display fahr
		 * and 0 points after the decimal. "6.1" indicates that we want 6 
		 * characters of width to be reserved for celsius and 1 point after the
		 * decimal should be shown. */
		printf("%3.0f %6.1f\n", fahr, celsius);	/* Print the next line */

		/* This is abbreviated syntax of the previous example. */
		fahr += step;	/* Increase fahr by the step size */

	} /* end while (fahr <= upper) loop */
} /* end main() */
