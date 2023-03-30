#include <math.h>
#include <stdio.h>
#include <stdlib.h> /* Gives us access to atoi() */
#include <string.h> /* Give us access to strcmp() */

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

/* In addition to functions from the previoius example, we've added a square 
function and an exponentiation funciton. Is there a way we can implement a 
function that returns 2 to a given power, without using the math library? */
float square(float a){
    return pow(a, 2);
}
float expt(float a, float b){
    return pow(a, b);
}

int main(int argc, char* argv[]) {
    /** Here is an example of error control. If argc is not equal to  4, in 
     * which case sufficient arguments have not been supplied, main() will
     * print the following message to the console, then exit the program with 
     * the given exit code -1. Having these kinds of checks in  your code can 
     * help prevent difficult to debug errors like segmentation faults.
     */
    if (argc != 4) {
        printf("ERROR: Correct usage is %s <operator> <a> <b>\n", argv[0]);
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
    // return -1;
} /* end main() */
