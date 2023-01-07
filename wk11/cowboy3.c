/**
 * @file cowboy.c
 * @author Ian Toy (iantoy@uab.edu)
 * @brief This implementation of "Cowboy" makes use of struct pointers and 
 * functions that accept struct pointers as parameters. The code has been 
 * refactored to use helper functions that update our player structs by 
 * accessing their member variables via a pointer to that struct. Also, this 
 * implementation uses define to set strings used frequently and fprintf to 
 * write output to stderr as well.
 * @version 0.1
 * @date 2022-10-12
 * @copyright Copyright (c) 2022
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* Define int variables with names representing the computer's action */
#define SHIELD 0
#define SHOOT 1
#define RELOAD 2

#define WELCOME "Welcome to Cowboy!\n"
#define PLAY_HUH "Would you like to play? (Y or N): "
#define PLAY_YES "Alright, lets play!\n"
#define PLAY_NO "Maybe another time then...\n"

#define STAT_TABLE "\tYou\tOpponent\nHP:\t%d\t%d\nAMMO:\t%d\t%d\nSHLD:\t%d\t%d\n"

#define ACTION_HUH "What is your action? (SHIELD, SHOOT, or RELOAD):\n"
#define NO_SHIELDS "\nYou don't have any shields left!\n"
#define NO_AMMO "\nYou don't have any ammo!\n"
#define MAX_AMMO "\nYou can't have more than 3 ammo!\n"

#define BOTH_SHIELD "You both shielded!\n"
#define BOTH_SHOOT "You both hit one another!\n"
#define BOTH_RELOAD "You both reloaded!\n"

#define SHIELD_SHOOT "You blocked a shot!\n"
#define SHIELD_RELOAD "Your opponent reloaded!\n"

#define SHOOT_SHIELD "Your shot was blocked!\n"
#define SHOOT_RELOAD "You got a hit while your opponent was reloading!\n"

#define RELOAD_SHIELD "You reloaded while your opponent shielded!\n"
#define RELOAD_SHOOT "You took a hit while reloading!\n"


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
    printf(WELCOME);
    printf(PLAY_HUH);
    fflush(stdout);

    char input;
    scanf("%c", &input);

    if ( input == 'Y' || input == 'y' ) {
        printf(PLAY_YES);
        fprintf(stderr, PLAY_YES);
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

/**
 * @brief Prompt the user to take a game action and store in p1 struct.
 * 
 * @param ptr1 a pointer to the player 1 struct
 */
void getp1action(PLAYER *ptr1) {
    char myaction[8];
    while (ptr1->action == -1) {
        printf(ACTION_HUH);
        fprintf(stderr, ACTION_HUH);
        scanf("%s", myaction);
        if (strcmp(myaction, "shield") == 0 && ptr1->shield == 0) {
            printf(NO_SHIELDS);
            fprintf(stderr, NO_SHIELDS);
            continue;
        } else if (strcmp(myaction, "shoot") == 0 && ptr1->ammo == 0) {
            printf(NO_AMMO);
            fprintf(stderr, NO_AMMO);
            continue;
        } else if (strcmp(myaction, "reload") == 0 && ptr1->ammo == 3) {
            printf(MAX_AMMO);
            fprintf(stderr, MAX_AMMO);
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
    printf(STAT_TABLE, ptr1->hp, ptr2->hp, ptr1->ammo, ptr2->ammo, ptr1->shield, ptr2->shield);
    fprintf(stderr, STAT_TABLE, ptr1->hp, ptr2->hp, ptr1->ammo, ptr2->ammo, ptr1->shield, ptr2->shield);
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
                    printf(BOTH_SHIELD);
                    fprintf(stderr, BOTH_SHIELD);
                    break;
                case SHOOT:
                    printf(SHIELD_SHOOT);
                    fprintf(stderr, SHIELD_SHOOT);
                    ptr1->shield--;
                    ptr2->ammo--;
                    break;
                case RELOAD:
                    printf(SHIELD_RELOAD);
                    fprintf(stderr, SHIELD_RELOAD);
                    ptr2->ammo++;
                    break;
            }
            break;
        case SHOOT:
            switch(ptr2->action) {
                case SHIELD:
                    printf(SHOOT_SHIELD);
                    fprintf(stderr, SHOOT_SHIELD);
                    ptr1->ammo--;
                    ptr2->shield--;
                    break;
                case SHOOT:
                    printf(BOTH_SHOOT);
                    fprintf(stderr, BOTH_SHOOT);
                    ptr1->hp--;
                    ptr1->ammo--;
                    ptr2->hp--;
                    ptr2->ammo--;
                    break;
                case RELOAD:
                    printf(SHOOT_RELOAD);
                    fprintf(stderr, SHOOT_RELOAD);
                    ptr1->ammo--;
                    ptr2->hp--;
                    ptr2->ammo++;
                    break;
            }
            break;
        case RELOAD:
            switch(ptr2->action) {
                case SHIELD:
                    printf(RELOAD_SHIELD);
                    fprintf(stderr, RELOAD_SHIELD);
                    ptr1->ammo++;
                    break;
                case SHOOT:
                    printf(RELOAD_SHOOT);
                    fprintf(stderr, RELOAD_SHOOT);
                    ptr1->hp--;
                    ptr1->ammo++;
                    ptr2->ammo--;
                    break;
                case RELOAD:
                    printf(BOTH_RELOAD);
                    fprintf(stderr, BOTH_RELOAD);
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
