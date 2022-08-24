#include<stdio.h>
int global_int = 5;
// see: https://man7.org/linux/man-pages/man3/end.3.html
extern etext;
extern edata;
extern end;

void new_func(){
    printf("Location of new_funct is %p\n", &new_func);
    int i = 15;
    printf("inside func, i is %d (%p)\n", i, &i);
    global_int++;
    printf("inside new_func, global++ is %d (%p)\n", global_int, &global_int);
    
    //return;
}

int main(){
    printf("...Location of main is %p\n", &main);
    printf("etext %p\n", &etext);
    printf("edata %p\n", &edata);
    printf("end %p\n", &end);
    register void *sp asm ("sp");
    printf("stack pointer %p\n", sp);
    int i = 10;

    {
        int i = 7;
        printf("inside block, i is %d (%p)\n", i, &i);
        printf("inside block, global is %d (%p)\n", global_int, &global_int);
        global_int++;
        printf("inside block, global++ is %d\n", global_int);
    }

    printf("outside block, i is %d (%p)\n", i, &i);
    printf("outside block, global is %d\n", global_int);

    new_func();
    printf("outside block, after func call, global is %d\n", global_int);

    return 0;
}