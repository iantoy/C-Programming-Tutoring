#include <stdio.h>
#include <stdlib.h> /* Gives us access to atoi() */
#include <string.h> /* Give us access to strcmp() */

/* Here, we have a set of simple arithmetic functions */
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

// float twospow(int e) {
//     return 1 << e;
// }

/* Here, main is our driver function. It expects some number of command-line
arguments, an operation, followed by two operrands */
int main(int argc, char* argv[]) {

    char* myop = argv[1]; /* localize inputs */
    float a = atoi(argv[2]); /* use atoi() to convert char* args to ints */
    float b = atoi(argv[3]);

    /** Here, we use strcmp() to compare the given opperator with one of the 
     * following, add, sub, mult, or div. strcmp() compares two strings and 
     * returns the number of DIFFERENCES between them. Therefore, if two 
     * strings are identical, strcmp() returns 0. This is how we check string
     * equivalence in C. 
     */
    if (strcmp(myop, "add") == 0){ 
        printf("%.2f\n", add(a, b));    // print the sum
    } else if (strcmp(myop, "sub") == 0){
        printf("%.2f\n", sub(a, b));    // print the difference
    } else if (strcmp(myop, "mult") == 0){ 
        printf("%.2f\n", mult(a, b));   // print the product
    } else if (strcmp(myop, "div") == 0){ 
        printf("%.2f\n", divide(a, b));    // print the quotient
    } /* end if-else block*/

    // if (strcmp(myop, "twospow") == 0) {
    //     printf("%.2f\n", twospow(a));
    // }

} /* end main() */
