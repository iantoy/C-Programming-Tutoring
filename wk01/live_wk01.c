/** Write a program that prints a short pounds to kilograms conversion table.
 * For this example, we will use the following ratio: 0.45359237lb = 1kg
 */

#include <stdio.h>

int main() {

    float kilos, lbs;
    int upper, lower, step;

    upper = 100;
    lower = 10;
    step = 10;

    lbs = lower;

    while(lbs <= upper){
        kilos = lbs * 0.45359237;
        printf("kilos:\t%f\tlbs:\t%f\n", kilos, lbs);
        lbs += step;
    }

    return 0;

} /* end main() */