#include <stdio.h>


int main() {

    int *ptr;

    int n = 8;

    ptr = &n;

    printf("ptr:\t%x\n", ptr);
    printf("&n:\t%x\n", &n);
    printf("*ptr:\t%d\n", *ptr);
    printf("n:\t%d\n", n);
    printf("&ptr:\t%x\n", &ptr);

}