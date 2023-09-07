/**
 * @file demo2.c
 * @author Ian Toy (iantoy@uab.edu)
 * @brief This version of our program makes use of COMMAND-LINE ARGUMENTS. Like
 * any function, main expects some perameters, argc and *argv[]. argc indicates
 * the number of arguments passed to the function and *argv[] is the string 
 * array of those arguments.
 * @version 0.1
 * @date 2023-03-30
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {

    /* Print the number of commandline args and the first element of argv */
    printf("argc: %d\n", argc);
    printf("argv[0]: %s\n", argv[0]); /* argv[0] is always the programs name */

    int n, sum;

    /** Any argument given to the command line is accepted as a STRING (char*).
     * Therefore, in these print statements, we're using the %s format 
     * specifier. */
    printf("argv[1]: %s\n", argv[1]); 

    /** Since were calculating a sum based on this input, we have to perform a
     * type conversion. We do this with the function atoi() from the stdlib.h
     * header file. Conversely, the itoa() function converts ints to strings.*/
    n = atoi(argv[1]);
    printf("n = %d\n", n);

    /** If we tried to make this assignment without converting, what would 
     * happen? Try commenting out line 36 and un-commenting out the line below,
     * then compile to see what happens. */
    // n = argv[1];

    /* For loops that execute a sinlge line can be written like this... */
    int i;
    for (i = 1; i <= n; i++) sum += i;

    printf("The sum of numbers 1 to %d is %d\n", n, sum);
} /* end main() */
