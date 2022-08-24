/**
 * @file rps3.c
 * @author Ian Toy (iantoy@uab.edu)
 * @brief This application is a simple command-line rock paper scissors game. 
 * The purpose of this game is to demonstrate some C programming basics. This 
 * implementation uses functions to abstract the work being done by our main
 * driver function. It also demonstrates passing values by reference to update
 * variables in the scope of main with the helper function playnextgame().
 * 
 * @version 0.1
 * @date 2022-03-05
 * 
 * @copyright Copyright (c) 2022
 */

/* Preprocessor Commands & Definitions */
#include <stdio.h>
#include <time.h>
#define ROCK 1
#define PAPER 2
#define SCISSORS 3
#define YES 1
#define NO 2

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
    printf("Welcome to Rock Paper Scissors!\n");
    /* Writes print statement to stderr as well using fprintf */
    fprintf(stderr, "Welcome to Rock Paper Scissors!\n");

    int inuse = 1;
    while (inuse) {
        /* Prompt and sture the user's throw */
        int input = handleinput();

        /* Determine the computer's action by generating 1 2 or 3 randomly */
        int opaction = 1 + (rand() % 3);

        /* Determine the winner or loop again (in case of a draw) */
        if (input == opaction) {
            printf("You both threw the same thing!\n");
            fprintf(stderr, "You both threw the same thing!\n");

            continue; /* Exit this iteration of the loop */
        } else {
            checkwinner(input, opaction); /* Call checkwinner to see who won */
        } /* end wincon if-else block */

        /* Continue to the next loop if the user wants to play again */
        playnextgame(&inuse);
    } /* end while(inuse) */
    return 0;
} /* end main() */

/* FUNCTION DEFINITIONS */

/**
 * @brief handleinput() prompts the user to enter 1 2 or 3 to throw rock, 
 * paper, or scissors respectively. Using scanf, the users input is stored then
 * returned.
 * 
 * @return int myinput
 */
int handleinput() {
    /* Prompt the user to enter 1 2 or 3 to throw rock paper or scissors */
    printf("Choose what to throw:\n");
    printf("1. rock\n");
    printf("2. paper\n");
    printf("3. scissors\n");

    fprintf(stderr, "Choose what to throw:\n");
    fprintf(stderr, "1. rock\n");
    fprintf(stderr, "2. paper\n");
    fprintf(stderr, "3. scissors\n");


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
        printf("Paper beats rock, you lose!\n");
        fprintf(stderr, "Paper beats rock, you lose!\n");
    } else if (_input == ROCK && _opaction == SCISSORS) { /* rock scissors */
        printf("Rock beats scissors, you win!\n");
        fprintf(stderr, "Rock beats scissors, you win!\n");
    } else if (_input == PAPER && _opaction == ROCK) {
        printf("Paper beats rock, you win!\n");
        fprintf(stderr, "Paper beats rock, you win!\n");
    } else if (_input == PAPER && _opaction == SCISSORS) { /* rock scissors */
        printf("Scissors beats paper, you lose!\n");
        fprintf(stderr, "Scissors beats paper, you lose!\n");
    } else if (_input == SCISSORS && _opaction == ROCK) {
        printf("Rock beats scissors, you lose!\n");
        fprintf(stderr, "Rock beats scissors, you lose!\n");
    } else if (_input == SCISSORS && _opaction == PAPER) { /* rock paper */
        printf("Scissors beats paper, you win!\n");
        fprintf(stderr, "Scissors beats paper, you win!\n");
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
    printf("Would you like to play again?\n");
    printf("1. Yes\n2. No\n");

    fprintf(stderr, "Would you like to play again?\n");
    fprintf(stderr, "1. Yes\n2. No\n");

    /* Initialize an in playagain and store the users input here */
    int playagain;
    scanf("%d", &playagain);
    /* If the user wants to play again, continue to the next loop */
    if(playagain == YES) {
        printf("Great, lets play again!\n");
        fprintf(stderr, "Great, lets play again!\n");
    /* If not, print a message to the screen then set inuse to 0 */
    } else if (playagain == NO) {
        printf("Thanks for playing, goodbye!\n");
        fprintf(stderr, "Thanks for playing, goodbye!\n");
        *_inuse = 0;
    } /* end playagain if-else block */
} /* end playnextgame() */
