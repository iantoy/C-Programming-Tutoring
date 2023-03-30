/**
 * @file demo2.c
 * @author Ian Toy (iantoy@uab.edu)
 * @brief This program prints a short Fahrenheit to Celsius conversion table. 
 * This code is from p. 12 of The C Programming Language by Kernigan & Ritchie.
 * @version 0.1
 * @date 2023-03-30
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <stdio.h>

int main() { 

	/** Like in our demo1.c code, we declare our variables here. If you want
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

		/** The format specifiers here provide more information about how we 
		 * want to display floats in this print statement. The numbers between
		 * the % sign and the f indicate how many characters of width should be
		 * used to display the number, followed by how many decimal places 
		 * should be 
		 * 
		 * "3.0" indicates that
		 * 3 characters will be used to display fahr and 0 of which will 
		 * represent the decimal. "6.1" indicates that 6 characters of space 
		 * will be used to display celsius, 1 character of which should display
		 * the decimal. */
		printf("%3.0f %6.2f\n", fahr, celsius);	/* Print the next line */

		/* This is abbreviated syntax of the previous example. */
		fahr += step;	/* Increase fahr by the step size */
	} /* end while (fahr <= upper) loop */
} /* end main() */
