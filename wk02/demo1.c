#include <stdio.h>
// #include "assignment2.h"

int main(int argc, char *argv[]) {
    // hello();   
    /* Here we initialize a pointer, ptr */
    int *ptr;

    int n, sum;
    n = sum = 0;

    printf("Welcome to the Gaussian Sum Calculator!\n");
    printf("Please enter an integer number:\n");

    /** Here, we take a the user's input, parse it as an integer, and store it
     * at the ADDRESS (&) of n */
    scanf("%d", &n);

    ptr = &n; /* Now, we assign our pointer to POINT TO the address of n */

    /* These print statements illustrate how & where our program stores data */
    printf("The value you entered was: %d\n", n); /* Display the variable, n */
    printf("This information is stored at the address %p\n\n", &n);

    /** When you see these on the console, notice how the pointer and the 
     * address of n share the same address. This is because we assigned our ptr
     * to POINT TO this location in memory. */
    printf("The pointer pointing to n has the address %p\n", ptr);
    printf("We can use this pointer to access the value at this location.\n\n");

    /** We can access the value at this location by DEREFERENCING ptr. This is
     * accomplished by putting an asterix (*) in front of the name of our 
     * pointer. This tells our program to "access THE VALUE AT ptr". This value
     * will match the value of n printed above. */  
    printf("For example, *ptr gives us %d\n\n", *ptr);

    /** Before defining our for loop, we declare our counter variable, i, then 
     * initialize it to 1 in the parentheses of the loop. In newer C standards,
     * this can be accomplished in the same line, i.e. for (int i = 0; ...). 
     * HOWEVER, since Vulcan is a dinosaur-server, we have to adhere to C89 
     * standards, in which this syntax is not supported. Get used this, 
     * because when you start working, there is a good to fair chance that 
     * you'll be working on a server or codebase older than you or I put 
    //  * together. */
    // int i;
    // for (i = 1; i <= n; i++) {
    //     sum += i;
    // }

    /* For loops that execute a sinlge line can be written like this... */
    // int i;
    // for (i = 1; i <= n; i++)
        // sum += i;

    /* Of course we can find the solution using Gauss' formula, written below */
    sum = (n * (n + 1))/2;

    printf("The sum of the numbers from 1 to %d is %d\n", n, sum);

} /* end main() */

