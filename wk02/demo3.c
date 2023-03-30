/**
 * @file demo3.c
 * @author Ian Toy (iantoy@uab.edu)
 * @brief This version of our summing program makes use of some commandline
 * error handling. Supplying too many arguments won't break our executable, but
 * too few will cause a segmentation fault. Therefore, we want to prevent this
 * from happening so our program can exit safely.
 * @version 0.1
 * @date 2023-03-30
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {


    /** Instead of printing specific elements of argv[], this version loops 
     * through and prints all of the commandline arguments provided. */
    int i;
    printf("argv[]: ");
    for (i = 0; i < argc; i++) printf("%s ", argv[i]);
    printf("\n");

    /** To avoid our program seg-faulting, we want to check that a number has 
     * been provided. Here we check if the number of arguments is not 2 (one 
     * for the executable name, one for the number provided). If this is the
     * case, we will print a message to the user then exit with code -1. */
    if (argc != 2) {
        printf("ERROR: Incorrect number of commandline arguments provided.\n");
        printf("Correct usage: ./demo3 <INTEGER>\n");
        exit(-1);
    }

    int n, sum;
    n = atoi(argv[1]);

    /* Instead of a loop, we can use Gauss' formula to sum 1 through n. */
    sum = (n * (n + 1))/2;
    printf("The sum of numbers 1 to %d is %d\n", n, sum);

    return 0; 
} /* end main() */
