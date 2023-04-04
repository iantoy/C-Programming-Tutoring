/**
 * @file calculator1.c
 * @author Ian Toy (iantoy@uab.edu)
 * @brief This is a simple calculator application that accepts commandline
 * arguments and returns a result based on the opperation and operands 
 * provided. The supported operators are "add" to add two numbers, "sub" to 
 * subtract two numbers, "mult" to multiply two numbers, and "div" to divide
 * those numbers.
 * 
 * It is important to note that since we are making use of the math system 
 * library, we need to include the "-lm" flag when we compile with gcc.
 * 
 * To compile: gcc calculator.c -lm -o calculator

 * 
 * Usage: a.out <operator> <int a> <int b>
 * 
 * @version 0.1
 * @date 2023-04-04
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <stdio.h>
#include <stdlib.h> /* Gives us access to atoi() */
#include <string.h> /* Gives us access to strcmp() */

/* Here, we have a set of simple arithmetic functions */
float add(float a, float b) {
    return a + b;
}
float sub(float a, float b) {
    return a - b;
}
float mult(float a, float b) {
    return a * b;
}
float divide(float a, float b) {
    return a / b;
}

int main(int argc, char* argv[]) {
    char* myop = argv[1];       /* localize inputs */
    float a = atoi(argv[2]);    /* use atoi() to convert char* args to ints */
    float b = atoi(argv[3]);

    /** Here, we use strcmp() to compare the provided operator with our 
     * supported operations. strcmp() compares two strings and returns the 
     * number of DIFFERENT characters between them. Identical strings, 
     * therefore, will return 0. This is how we compare strings in C. */
    if (strcmp(myop, "add") == 0){ 
        printf("%.2f\n", add(a, b));    // print the sum
    } else if (strcmp(myop, "sub") == 0){
        printf("%.2f\n", sub(a, b));    // print the difference
    } else if (strcmp(myop, "mult") == 0){ 
        printf("%.2f\n", mult(a, b));   // print the product
    } else if (strcmp(myop, "div") == 0){ 
        printf("%.2f\n", divide(a, b)); // print the quotient
    } /* end if-else block*/
} /* end main() */
