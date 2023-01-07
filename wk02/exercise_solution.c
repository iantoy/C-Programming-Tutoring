/** Extend the program from the previous example to calculate the average of 
 * of the given array elements.
 */

#include <stdio.h>

int avgarray(int *arr, int len) {
    float avg, sum = 0.0;
    int i = 0;
    /* Using a for loop over the indecies of the array */
    for (i = 0; i < len; i++) {
        sum += arr[i];
    }

    avg = sum / len;
    return avg;
}

int main() {

    int testlen = 8;
    int testarr[8] = {14, 3, 18, 2, 10, 5, 14, 12};
    int testavg = avgarray(testarr, testlen);

    printf("The average of the elements in the test array is %f.\n", testavg);

    return 0;
}