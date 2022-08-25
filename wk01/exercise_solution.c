/** Write a program that takes user input for an amount in pounds and prints 
 * its equivalent in kilograms.
 */

#include <stdio.h>

int main() {

    printf("Welcome to the lb/kg converter!\n");
    printf("Enter an amount in pounds:\n");

    int lbs;
    scanf("%d", &lbs);

    float kgs = lbs * 0.45359237;
    printf("%d pounds is equivalent to %f kilograms.\n");

} // end main()