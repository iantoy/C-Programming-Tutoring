/**
 * @file cowboy.c
 * @author Ian Toy (iantoy@uab.edu)
 * @brief This implementation of "Cowboy" refactors the macros, functions, and 
 * type definitions from previous implementations into respective header files.
 * They have been included with our system header preprocessor commands.
 * @version 0.1
 * @date 2022-10-12
 * @copyright Copyright (c) 2022
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "cowboy_fxns.h"
#include "cowboy_macros.h"
#include "cowboy_types.h"

/* MAIN DRIVER */
int main(int argc, char* argv[]){
    printf(WELCOME);
    printf(PLAY_HUH);
    fflush(stdout);

    char input;
    scanf("%c", &input);

    if ( input == 'Y' || input == 'y' ) {
        printf(PLAY_YES);
        fprintf(stderr, PLAY_YES);
        srand(time(NULL)); /* Generate a random seed based on the current time */
        PLAYER p1 = {3, 0, 3, -1};
        PLAYER p2 = {3, 0, 3, -1};
        PLAYER *ptr1 = &p1;
        PLAYER *ptr2 = &p2;
        int inuse = 1;
        while (inuse == 1) {
            setp2action(ptr2);
            printstats(ptr1, ptr2);
            getp1action(ptr1);
            printf("\n");
            fprintf(stderr, "\n");
            resolveactions(ptr1, ptr2);
            printf("\n");
            fprintf(stderr, "\n");
            inuse = checkforwinner(ptr1, ptr2); // exit this loop if we have a winner
        } /* end while(inuse) */
    } else {
        printf(PLAY_NO);
        fprintf(stderr, PLAY_NO);
    }
    return 0;
} /* end main() */

