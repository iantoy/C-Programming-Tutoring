/** Write a program that prints a short pounds to kilograms conversion table.
 * For this example, we will use the following ratio: 0.45359237lb = 1kg
 */

#include <stdio.h>

int main() {

    int lower, upper, step, lbs;
    float kgs;
    
    lower = 1;
    upper = 10;
    step = 1;
    
    lbs = lower;
    
    printf("Pounds to Kilograms Conversion Table:\n");
    while(lbs <= upper) {
        kgs = lbs * 0.45359237;
        printf("%dlbs\t=\t%fkgs\n", lbs, kgs);
        lbs += step;
    }

    return 0;
}