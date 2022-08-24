/** The purpose of this program is to print a short Fahrenheit to Celsius 
 * temperature conversion table. This code is from p. 9 of The C Programming 
 * Language by Kernigan & Ritchie. 
 * */

/** This is a preprocessor command. This tells the compiler that we want to 
 * include the standard input and output header file, <stdio.h>, when we create
 * our executable, which allows our program to use the printf function. */
#include <stdio.h> 

main() { /* This is our main function. */

	/** These are our variable declarations. The type of the variable must 
	 * precede the variable name */
	int fahr;		/* a temperature in degrees F */
	int celsius;	/* a temperature in degrees C */
	int lower;		/* The lower limit of our conversion table */
	int upper;		/* Upper limit */
	int step;		/* Step size */

	/* These are variable assignments. */
	lower = 0; 
	upper = 300; 
	step = 20; 

	/* Assign the value of lower to fahr */
	fahr = lower;

	/* Print the table header */
	printf("F to C Conversion Table\n");

	/** This is a while loop. It performs the enclosed work repeatedly until 
	 * its condition is no longer true. */
	while (fahr <= upper) { /* While farh is less than or equal to upper... */ 

		/* Convert fahr to to celsius and store the result in celsius */
		celsius = 5.0/9.0 * (fahr - 32.0);

		/** Here, we print the next line of the table. This print statement 
		 * uses format specifiers and escape characters. The '%d's indicate 
		 * where an int will be displayed. '\t' indicates that a tab character
		 * is to be instered here, and '\n' creates a new line. */
		printf("%d\t%d\n", fahr, celsius);

		fahr = fahr + step;	/* Increase fahr by the step size */

	} /* end while (fahr <= upper) loop */
} /* end main() */
