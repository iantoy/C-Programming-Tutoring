/**
 * @file demo1.c
 * @author Ian Toy (iantoy@uab.edu)
 * @brief This program is an introduction to how pointers an addressing work in
 * C using the scanf() system library function. It also goes over pointer 
 * syntax and dereferencing.
 * @version 0.1
 * @date 2023-03-30
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <stdio.h>

int main(int argc, char *argv[]) {
    /* Here we initialize a pointer, ptr. To declare a variable as a pointer, 
     * prepend the variable name with an asterix, "*". */
    int *ptr;

    /* Declare two int variables, n and sum, and initialize their value as 0 */
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

    /** Here we have a for loop that sums all the numbers between 1 and n. 
     * Before defining our for loop, we declare our counter variable, i, then 
     * initialize it to 1 in the parentheses of the loop. In newer C standards,
     * this can be accomplished in the same line, i.e. for (int i = 0; ...), 
     * but if you're working on an older standard, keep this syntax in mind. */
    int i;
    for (i = 1; i <= n; i++) {
        sum += i;
    }

    printf("The sum of the numbers from 1 to %d is %d\n", n, sum);
} /* end main() */

