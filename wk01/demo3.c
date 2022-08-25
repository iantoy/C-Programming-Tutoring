#include <stdio.h>

/** Here we have our function prototypes. Like declaring a variable before
 * assigning it a value, we declare a function before defining the work that
 * it does. We do this before main() so that main() knows that these functions
 * exist. When we declare a function, we first write the data type that the 
 * function returns, the name of the function, and then in parenthesis the 
 * parameters that it expects. */

float ftoc(float f); /* Converts a temperature in Fahrenheit to Celsius */
void print_ftoc(float f); /* Prints a line of a F to C conversion table */

int main(){

	/* variable declaration */
	float fahr, celsius;
	int lower, upper, step;

	/* variabel initialization */
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
		
		/** We can abstract this work further by calling print_ftoc, which does
		 * the work of the two lines above. Try commenting out lines 29-30 and 
		 * un-commenting out the line below. The table should print the same.*/
		// print_ftoc(fahr); /* Print the next line of the table */

		fahr += step; /* Increment fahr by the step size. */ 

	} /* end while(fahr <= upper) loop */
} /* end main() */

/** Here we have our function definitions. ftoc() accepts a float, f, as an 
 * argument and returns a float. print_ftoc() accepts a float, f, calculates
 * the conversion to celsius, then prints a line of the temperature conversion
 * table. Since print_ftoc() doesn't return anything, we set its return type to
 * void */
float ftoc(float f) { /* Here is our definition of ftoc() */
	return (5.0/9.0) * (f - 32);
} /* end ftoc() */

void print_ftoc(float f){
	float c;
	c = (5.0/9.0) * (f - 32.0);
	printf("%3.0f %6.1f\n", f, c); 
} /* end print_ftoc() */


