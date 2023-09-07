/** Write a program that takes an array of integers and calculates the sum of
 * those array elements.
 */

#include <stdio.h>

int sumarray(int *arr, int len) {
    int sum = 0;

    int i = 0;
    /* Using a for loop over the indecies of the array */
    for (i = 0; i < len; i++) {
        sum += arr[i];
    }

    return sum;
}

int main() {

    int testlen = 8;
    int testarr[8] = {14, 3, 18, 2, 10, 5, 14, 12};
    int testsum = sumarray(testarr, testlen);

    printf("The sum of all elements in the test array is %d.\n", testsum);

    return 0;
}