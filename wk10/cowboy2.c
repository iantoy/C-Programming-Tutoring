/**
 * @file cowboy.c
 * @author Ian Toy (iantoy@uab.edu)
 * @brief This implementation of "Cowboy" makes use of struct pointers and 
 * functions that accept struct pointers as parameters. The code has been 
 * refactored to use helper functions that update our player structs by 
 * accessing their member variables via a pointer to that struct.
 * @version 0.1
 * @date 2022-10-12
 * @copyright Copyright (c) 2022
 */

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
#include <time.h>

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

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
    int action;
} PLAYER;

/* FUNCTION PROTOTYPES */
void getp1action(PLAYER *ptr1);
void setp2action(PLAYER *ptr2);
void printstats(PLAYER *ptr1, PLAYER *ptr2);
void resolveactions(PLAYER *ptr1, PLAYER *ptr2);
int checkforwinner(PLAYER *ptr1, PLAYER *ptr2);

/* MAIN DRIVER */
int main(int argc, char* argv[]){
    printf("Welcome to Cowboy!\n");
    printf("Would you like to play? (Y or N): ");
    fflush(stdout);

    char input;
    scanf("%c", &input);


    int fderr;
    /* Open standard error stream, error handling */
    if ((fderr = open("stderr.txt", O_CREAT | O_APPEND | O_WRONLY, 0755)) == -1) {
        printf("Error opening file stderr.txt for error\n");
    } /* end file open error handling*/
    dup2(fderr, 2);

    if ( input == 'Y' || input == 'y' ) {
        printf("Alright, lets play!\n");
        srand(time(NULL)); /* Generate a random seed based on the current time */

        /* Initialize our player structs */
        PLAYER p1 = {3, 0, 3, -1};
        PLAYER p2 = {3, 0, 3, -1};

        /* Initialize our PLAYER struct pointers */
        PLAYER *ptr1 = &p1;
        PLAYER *ptr2 = &p2;

        /* Initialize an inuse flag and set to 1 */
        int inuse = 1;


        /* While inuse, loop through the core gameplay until a winner exists */
        while (inuse == 1) {
            setp2action(ptr2);
            printstats(ptr1, ptr2);
            getp1action(ptr1);
            printf("\n");
            resolveactions(ptr1, ptr2);
            printf("\n");
            inuse = checkforwinner(ptr1, ptr2); // exit this loop if we have a winner
        } /* end while(inuse) */
    } else {
        printf("Maybe another time then...\n");
        fprintf(fderr, "Maybe another time then...\n");

    }
    return 0;
} /* end main() */

/**
 * @brief Prompt the user to take a game action and store in p1 struct.
 * 
 * @param ptr1 a pointer to the player 1 struct
 */
void getp1action(PLAYER *ptr1) {
    char myaction[8];
    while (ptr1->action == -1) {
        printf("What is your action? (SHIELD, SHOOT, or RELOAD):\n");
        scanf("%s", myaction);
        if (strcmp(myaction, "shield") == 0 && ptr1->shield == 0) {
            printf("\nYou don't have any shields left!\n");
            continue;
        } else if (strcmp(myaction, "shoot") == 0 && ptr1->ammo == 0) {
            printf("\nYou don't have any ammo!\n");
            continue;
        } else if (strcmp(myaction, "reload") == 0 && ptr1->ammo == 3) {
            printf("\nYou can't have more than 3 ammo!\n");
            continue;
        }

        if (strcmp(myaction, "shield") == 0) {
            ptr1->action = SHIELD;
        } else if (strcmp(myaction, "shoot") == 0) {
            ptr1->action = SHOOT;
        } else if (strcmp(myaction, "reload") == 0) {
            ptr1->action = RELOAD;
        } /* end if(myaction) block */
    } /* end while (ptr1->action == -1) loop */
} /* end getp1action() */

/**
 * @brief Determine the computer players action randomly, correcting for 
 * illegal plays if they occur.
 * 
 * @param ptr2 a pointer to the player 2 struct
 */
void setp2action(PLAYER *ptr2) {
    while (ptr2->action == -1) { /* CPU action error handling */
        int myaction = rand() % 3; /* Generate an int between 0-2 (inclusive) */
        /* Cannot use shield if shiled is empty */
        if ((myaction == SHIELD) && (ptr2->shield == 0)) {
            continue;
        /* Cannot use shoot if ammo is 0 */
        } else if ((myaction == SHOOT) && (ptr2->ammo == 0)) {
            continue;
        /* Cannot reload if ammo is at max, 3 */
        } else if ((myaction == RELOAD) && (ptr2->ammo == 3)) {
            continue;
        }
        ptr2->action = myaction;
    } /* end while (ptr2->action == -1) loop */
} /* end setp2action */

/**
 * @brief Display the stats of player 1 and player 2 to the terminal.
 * 
 * @param ptr1 a pointer to the player 1 struct
 * @param ptr2 a pointer to the player 2 struct
 */
void printstats(PLAYER *ptr1, PLAYER *ptr2) {
    printf("\tYou\tOpponent\n");
    printf("HP:\t%d\t%d\n", ptr1->hp, ptr2->hp);
    printf("AMMO:\t%d\t%d\n", ptr1->ammo, ptr2->ammo);
    printf("SHLD:\t%d\t%d\n", ptr1->shield, ptr2->shield);
} /* end printstats() */

/**
 * @brief Updates player structs based on the actions taken.
 * 
 * @param ptr1 a pointer to the player 1 struct
 * @param ptr2 a pointer to the player 2 struct
 */
void resolveactions(PLAYER *ptr1, PLAYER *ptr2) {
    switch(ptr1->action) {
        case SHIELD:
            switch(ptr2->action) {
                case SHIELD:
                    printf("You both shielded!\n");
                    break;
                case SHOOT:
                    printf("You blocked a shot!\n");
                    ptr1->shield--;
                    ptr2->ammo--;
                    break;
                case RELOAD:
                    printf("Your opponent reloaded!\n");
                    ptr2->ammo++;
                    break;
            }
            break;
        case SHOOT:
            switch(ptr2->action) {
                case SHIELD:
                    printf("Your shot was blocked!\n");
                    ptr1->ammo--;
                    ptr2->shield--;
                    break;
                case SHOOT:
                    printf("You both hit one another!\n");
                    ptr1->hp--;
                    ptr1->ammo--;
                    ptr2->hp--;
                    ptr2->ammo--;
                    break;
                case RELOAD:
                    printf("You got a hit while your opponent was reloading!\n");
                    ptr1->ammo--;
                    ptr2->hp--;
                    ptr2->ammo++;
                    break;
            }
            break;
        case RELOAD:
            switch(ptr2->action) {
                case SHIELD:
                    printf("You reloaded while your opponent shielded!\n");
                    ptr1->ammo++;
                    break;
                case SHOOT:
                    printf("You took a hit while reloading!\n");
                    ptr1->hp--;
                    ptr1->ammo++;
                    ptr2->ammo--;
                    break;
                case RELOAD:
                    printf("You both reloaded!\n");
                    ptr1->ammo++;
                    ptr2->ammo++;
                    break;
            }
            break;
    } /* end switch ptr1->action */
    /* reset player actions for next round */
    ptr1->action = -1;
    ptr2->action = -1;
} /* end compareactions() */

/**
 * @brief Checks if both or either player has reached 0hp. Returns 0 if a 
 * player has won and returns 1 if no winner exists.
 * 
 * @param ptr1 a pointer to the player 1 struct
 * @param ptr2 a pointer to the player 2 struct
 * @return int result, 0 or 1
 */
int checkforwinner(PLAYER *ptr1, PLAYER *ptr2) {
    int result = 1;
    if (ptr1->hp == 0 && ptr2->hp == 0) {
        printf("STALEMATE!\n");
        result = 0;
    } else if (ptr1->hp == 0) {
        printf("YOU LOSE!\n");
        result = 0;
    } else if (ptr2->hp == 0) {
        printf("YOU WIN!\n");
        result = 0;
    }
    return result;
} /* end checkforwinner() */
