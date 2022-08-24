/**
 * @file cowboy.c
 * @author Ian Toy (iantoy@uab.edu)
 * @brief "Cowboy" is a simple turn-based rock-paper-scissors variant. The 
 * purpose of this program is to demonstrate the use of structs and basic 
 * control flow through the use of a while loop and if-else branching
 * statements. Cowboy also makes use of the time and rand functions in C to
 * determine the Computer's actions. Error handling is implemented to prevent
 * illegal actions from being taken.
 * @version 0.1
 * @date 2022-02-24
 * @copyright Copyright (c) 2022
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Define int variables with names representing the computer's action */
#define SHIELD 0
#define SHOOT 1
#define RELOAD 2

/* Here we define a PLAYER struct with typedef, allowing us to declare structs
of this type by simply writing PLAYER before the new variable name, as opposed
to "struct Player" like in previous weeks examples. */
typedef struct Players {
    int hp;
    int ammo;
    int shield;
} PLAYER;

/* Our main function is our driver for the program */
int main(int argc, char* argv[]){
    printf("Welcome to Cowboy!\n");
    printf("Would you like to play? (Y or N): ");

    char input;
    scanf("%c", &input);

    if ( input == 'Y' || input == 'y' ) {
        printf("Alright, lets play!\n");
        srand(time(NULL)); /* Generate a random seed based on the current time */

        /* Initialize our player structs */
        PLAYER me = {3, 0, 3};
        PLAYER op = {3, 0, 3};

        /* Initialize the int inuse which acts as a flag, and myaction, which 
        stores the players action taken */
        int inuse = 1;
        char myaction[8];

        while (inuse == 1) {
    
            /* Determine the computer's action with error handling */
            int opaction = -1; /* Initialize opaction to -1 */
            int opaction_set = 0; /* A flag to track if opaction is set */
            while (opaction_set == 0) { /* CPU action error handling */
                opaction = rand() % 3; /* Generate an int between 0-2 (inclusive) */
                /* Cannot use shield if shiled is empty */
                if ((opaction == SHIELD) && (op.shield == 0)) {
                    opaction = -1;
                    continue;
                /* Cannot use shoot if ammo is 0 */
                } else if ((opaction == SHOOT) && (op.ammo == 0)) {
                    opaction = -1;
                    continue;
                /* Cannot reload if ammo is at max, 3 */
                } else if ((opaction == RELOAD) && (op.ammo == 3)) {
                    opaction = -1;
                    continue;
                }
                opaction_set = 1;
            }

            /* Print a table showing the current game information */
            printf("\tYou\tOpponent\n");
            printf("HP:\t%d\t%d\n", me.hp, op.hp);
            printf("AMMO:\t%d\t%d\n", me.ammo, op.ammo);
            printf("SHLD:\t%d\t%d\n", me.shield, op.shield);

            printf("What is your action? (SHIELD, SHOOT, or RELOAD):\n");
            scanf("%s", &myaction);

            /* Player action error handling like above opaction code */
            if (strcmp(myaction, "shield") == 0 && me.shield == 0) {
                printf("\nYou don't have any shields left, so you can't throw shield\n");
                continue;
            } else if (strcmp(myaction, "shoot") == 0 && me.ammo == 0) {
                printf("\nYou don't have any ammo, so you can't throw shoot\n");
                continue;
            } else if (strcmp(myaction, "reload") == 0 && me.ammo == 3) {
                printf("\nYou can't have more than 3 ammo.\n");
                continue;
            }

            /* Player and CPU Action Comparisons */
            if ((strcmp(myaction, "shield") == 0) && (opaction == SHIELD)) {
                printf("\nYou and your opponent both threw shield! Nothing happens...\n");
            } else if ((strcmp(myaction, "shield") == 0) && (opaction == SHOOT)) {
                printf("\nYou blocked your opponent's shot!\n");
                me.shield--;
                op.ammo--;
            } else if ((strcmp(myaction, "shield") == 0) && (opaction == RELOAD)) {
                printf("\nYou throw shield while your opponent reloads!\n");
                op.ammo++;
            } else if ((strcmp(myaction, "shoot") == 0) && (opaction == SHIELD)) {
                printf("\nYour opponent blocked your shot!\n");
                me.ammo--;
                op.shield--;
            } else if ((strcmp(myaction, "shoot") == 0) && (opaction == SHOOT)) {
                printf("\nYou and your opponent both throw shoot!\n");
                me.ammo--;
                me.hp--;
                op.ammo--;
                op.hp--;
            } else if ((strcmp(myaction, "shoot") == 0) && (opaction == RELOAD)) {
                printf("\nYou threw shoot while your opponent was reloading! It's a hit!\n");
                me.ammo--;
                op.hp--;
            } else if ((strcmp(myaction, "reload") == 0) && (opaction == SHIELD)) {
                printf("\nYou reloaded while your opponent was shielding!\n");
                me.ammo++;
            } else if ((strcmp(myaction, "reload") == 0) && (opaction == SHOOT)) {
                printf("\nWhile you were reloading, your opponent threw shoot! You took a hit! \n");
                me.ammo++;
                me.hp--;
                op.ammo--;
            } else if ((strcmp(myaction, "reload") == 0) && (opaction == RELOAD)) {
                printf("\nYou both threw reload!\n");
                me.ammo++;
                op.ammo++;
            } else if (strcmp(myaction, "end") == 0) {
                inuse = 0;
            }

            /* WIN/LOSS/DRAW conditions. Determine the outcome then exit */
            if (me.hp == 0 && op.hp == 0) {
                printf("It's a draw!\n");
                inuse = 0;
            } else if (me.hp == 0) {
                printf("You lost!\n");
                inuse = 0;
            } else if (op.hp == 0) {
                printf("You won!\n");
                inuse = 0;
            }

        } /* end while(inuse) */
    } else {
        printf("Maybe another time then...\n");
    }
} /* end main() */
