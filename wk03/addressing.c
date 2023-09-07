#include <stdio.h>


int main() {

    int *ptr;

    int n = 8;

    ptr = &n;

    printf("ptr:\t%p\n", ptr); // prints the address stored in ptr
    printf("&n:\t%p\n", &n); // prints the address of n
    printf("*ptr:\t%d\n", *ptr); // prints the value at the address stored in ptr
    printf("n:\t%d\n", n); // prints the value of n
    printf("&ptr:\t%p\n", &ptr); // prints the address OF ptr

}
