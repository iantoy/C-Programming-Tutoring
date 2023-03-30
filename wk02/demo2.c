#include <stdio.h>
#include <stdlib.h>
// #include <string.h> /* We make use of a new header file, string.h */
// #include <math.h>

int main(int argc, char* argv[]) {

    /** This version of our program makes use of COMMAND-LINE ARGUMENTS. Like 
     * any function, main expects some perameters, argc and *argv[]. argc 
     * indicates the number of arguments passed to the function and *argv[] is
     * the string array of those arguments. */
    printf("argc: %d\n", argc);
    printf("argv[0]: %s\n", argv[0]); /* argv[0] is always the programs name */

    int n, sum; /* variable declaration */

    /** Any argument given to the command line is accepted as a STRING (char*).
     * Therefore, in these print statements, we're using the %s format 
     * specifier. */
    printf("argv[1]: %s\n", argv[1]); 

    /** Since were calculating a sum based on this input, we have to perform a
     * type conversion. We do this with the function atoi() from the string.h
     * header file. Conversely, the itoa() function converts ints to strings.*/
    n = atoi(argv[1]);
    // n = pow(n, 2);
    // n = argv[1];
    printf("n = %d\n", n);

    /** If we tried to make this assignment without converting, what would 
     * happen? Try commenting out line 23 and un-commenting out the line below
     * and compile to see. */
    // n = argv[1];

    /* Gauss' formula */
    sum = (n * (n + 1))/2;
    printf("The sum of numbers 1 to %d is %d\n", n, sum);

    return 0;
} /* end main() */
