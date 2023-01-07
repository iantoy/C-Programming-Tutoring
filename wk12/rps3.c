/**
 * @file rps2.c
 * @author Ian Toy (iantoy@uab.edu)
 * @brief This application is a simple command-line rock paper scissors game. 
 * this implementation refactors the functions and macros from previous 
 * implementations to their own respective header files and are imported with 
 * our other preprocessor commands.
 * 
 * @version 0.1
 * @date 2022-11-09
 * 
 * @copyright Copyright (c) 2022
 */

/* Preprocessor Commands & Definitions */
#include <stdio.h>
#include <time.h>
#include "rps_macros.h"
#include "rps_fxns.h"

/**
 * @brief main() is the driver function of our rock paper scissors game. It 
 * generates a random seed which is then used to generate the computer's game
 * actions. Then, it sets a flag variable, inuse, to 1 and runs the game while
 * the application is being used. It calls the helper functions declared above
 * and defined below to run the program.
 * 
 * In every C program, main expects two parameters, argc and argv. We won't use
 * them in this application, but they allow our executables
 * @param argc 
 * @param argv 
 * @return int 
 */
int main(int argc, char* argv[]) {
    srand(time(NULL)); /* Generate a random seed based on the current time */
    /* Prints welcome statement to stdout & stderr using rpint & fprintf */
    printf(WELCOME);
    fprintf(stderr, WELCOME);

    int inuse = 1;
    while (inuse) {
        /* Prompt and sture the user's throw */
        int input = handleinput();

        /* Determine the computer's action by generating 1 2 or 3 randomly */
        int opaction = 1 + (rand() % 3);

        /* Determine the winner or loop again (in case of a draw) */
        if (input == opaction) {
            printf(DRAW);
            fprintf(stderr, DRAW);
            continue; /* Exit this iteration of the loop */
        } else {
            checkwinner(input, opaction); /* Call checkwinner to see who won */
        } /* end wincon if-else block */

        /* Continue to the next loop if the user wants to play again */
        playnextgame(&inuse);
    } /* end while(inuse) */
    return 0;
} /* end main() */


