#include <stdio.h>
#include "rps_macros.h"

/** Prototype Function Declarations. When we declare a funciton in C, we need 
 * to specify the return type, the name of the function, and the type and name
 * of the parameters that the function expects.
 * 
 * This may seem unusual compared to languages you've used prior to C, but in
 * order for main() to know of and have access to these functions, they MUST be
 * declared before its definition. If we wanted to, we could put these entire 
 * function definitions before main(). This would also work, but largely just a 
 * matter of developer prefernece.
 * 
 * It is important to note that this does NOT mean we can have two different 
 * functions that share a name. Both the prototype and the definitions refer to
 * the same function.
 */
void checkwinner(int _input, int _opaction);
int handleinput();
void playnextgame(int *_inuse);


/* FUNCTION DEFINITIONS */

/**
 * @brief handleinput() prompts the user to enter 1 2 or 3 to throw rock, 
 * paper, or scissors respectively. Using scanf, the users input is stored then
 * returned.
 * 
 * @return int myinput
 */
int handleinput() {
    printf(PROMPT);
    fprintf(stderr, PROMPT);

    /* Hanlde user input with scanf, then return that value */
    int myinput;
    scanf("%d", &myinput);
    return myinput;
} /* end promptinput() */

/**
 * @brief checkwinner expects two integers, _input and _opaction, to determine
 * the winner of this game of rock paper scissors. This function compares who
 * threw what, determines the winner, and prints a message to that effect to 
 * the user. 
 * 
 * @param _input, the user's action
 * @param _opaction, the computer's action
 */
void checkwinner(int _input, int _opaction) {
    if (_input == ROCK && _opaction == PAPER) { /* rock paper */
        printf(ROCK_LOSE);
        fprintf(stderr, ROCK_LOSE);
    } else if (_input == ROCK && _opaction == SCISSORS) { /* rock scissors */
        printf(ROCK_WIN);
        fprintf(stderr, ROCK_WIN);
    } else if (_input == PAPER && _opaction == ROCK) {
        printf(PAPER_WIN);
        fprintf(stderr, PAPER_WIN);
    } else if (_input == PAPER && _opaction == SCISSORS) { /* rock scissors */
        printf(PAPER_LOSE);
        fprintf(stderr, PAPER_LOSE);
    } else if (_input == SCISSORS && _opaction == ROCK) {
        printf(SCISSORS_LOSE);
        fprintf(stderr, SCISSORS_LOSE);
    } else if (_input == SCISSORS && _opaction == PAPER) { /* rock paper */
        printf(SCISSORS_WIN);
        fprintf(stderr, SCISSORS_WIN);
    } /* end wincon if-else block */
} /* end checkwinner() */

/**
 * @brief playnextgame() accepts an integer pointer, _inuse, and updates it 
 * based on whether or not the user wants to continue playing rock paper 
 * scissors.
 * 
 * @param _inuse, the pointer to the inuse flag in the driver function. If the
 * user wants to continue playing, _inuse is unchanged. If the user does NOT
 * want to continue playing, the value at _inuse's address is set to 0, which 
 * should terminate the while(inuse) loop in the driver function 
 */
void playnextgame(int *_inuse) {
    /* As the user if they would like to play again and promtp for input */
    printf(AGAIN_HUH);
    fprintf(stderr, AGAIN_HUH);

    /* Initialize an in playagain and store the users input here */
    int playagain;
    scanf("%d", &playagain);
    /* If the user wants to play again, continue to the next loop */
    if(playagain == YES) {
        printf(AGAIN_YES);
        fprintf(stderr, AGAIN_YES);
    /* If not, print a message to the screen then set inuse to 0 */
    } else if (playagain == NO) {
        printf(AGAIN_NO);
        fprintf(stderr, AGAIN_NO);
        *_inuse = 0;
    } /* end playagain if-else block */
} /* end playnextgame() */