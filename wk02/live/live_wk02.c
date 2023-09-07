/** Write a program that takes an array of integers and calculates the sum of
 * those array elements.
 */

#include <stdio.h>

int main() {

    printf("Please enter a number (this will be the size of your array): ");

    int size;
    scanf("%d", &size);

    printf("You entered %d.\n", size);

    int arr[size];

    int i = 0;

    while(i < size) {
        printf("enter a number: ");
        scanf("%d", &arr[i]);
        printf("arr[%d]: %d\n", i, arr[i]);
        i++;
    }

    int j;
    int sum = 0;

    for (j = 0; j < size; j++) {
        sum += arr[j];
    }

    printf("sum = %d\n", sum);
} /* end main() */































#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    // printf("hello!\n");
    printf("argc: %d\n", argc);
    printf("argv[0]: %s\n", argv[0]);

    int sum = 0;

    int i;
    for (i = 1; i < argc ; i++) {
        sum += atoi(argv[i]);
    }

    printf("sum: %d\n", sum);
} /* end main() */