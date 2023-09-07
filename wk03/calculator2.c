/**
 * @file calculator2.c
 * @author Ian Toy (iantoy@uab.edu)
 * @brief This version of our calculator supports two new operations, a square
 * function and an exponentiation function. It also introduces error handling 
 * for correct commandline usage. Our program will break unless the correct 
 * number of arguments are provided, so we add some code to deal with this.
 * 
 * It is important to note that since we are making use of the math system 
 * library, we need to include the "-lm" flag when we compile with gcc.
 * 
 * To compile: gcc calculator2.c -lm -o calculator2
 * To run: ./calculator2 <operator> <int a> <int b>
 *
 * @version 0.1
 * @date 2023-04-04
 * 
 * @copyright Copyright (c) 2023
 */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float add(float a, float b) {
    return a + b;
}
float sub(float a, float b) {
    return a - b;
}
float mult(float a, float b){
    return a * b;
}
float divide(float a, float b){
    return a / b;
}
/* Here are our new functions, square() and expt(). */
float square(float a){
    return pow(a, 2);
}
float expt(float a, float b){
    return pow(a, b);
}

int main(int argc, char* argv[]) {
    /** If argc is not equal to  4, then an incorrect number of arguments have
     * been provided. main() will print the following message to the console,
     * then exit the program with the given exit code -1. Having these kinds of
     * checks in your code can prevent segmentation faults and help testing. */
    if (argc != 4) {
        printf("ERROR: Correct usage is %s <operator> <int a> <int b>\n", argv[0]);
        printf("For example, %s add 1 2 \n", argv[0]);
        exit(-1);
    }
    char* myop = argv[1];
    int a = atoi(argv[2]);
    int b = atoi(argv[3]);

    /* How could we expand this code to handle math symbols? */
    if (strcmp(myop, "add") == 0){ 
        printf("%.2f\n", add(a, b));    // print the sum
    } else if (strcmp(myop, "sub") == 0){
        printf("%.2f\n", sub(a, b));    // print the difference
    } else if (strcmp(myop, "mult") == 0){ 
        printf("%.2f\n", mult(a, b));   // print the product
    } else if (strcmp(myop, "div") == 0){ 
        printf("%.2f\n", divide(a, b));    // print the quotient
    } else if (strcmp(myop, "square") == 0){
        printf("%.0f\n", square(a));      // print the number squared
    } else if (strcmp(myop, "expt") == 0){
        printf("%.0f\n", expt(a, b));     // print a raised to b
    }
} /* end main() */
