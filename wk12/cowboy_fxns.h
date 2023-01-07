#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "cowboy_macros.h"
#include "cowboy_types.h"

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
        fprintf(stderr, "STALEMATE!\n");
        result = 0;
    } else if (ptr1->hp == 0) {
        printf("YOU LOSE!\n");
        fprintf(stderr, "YOU LOSE!\n");
        result = 0;
    } else if (ptr2->hp == 0) {
        printf("YOU WIN!\n");
        fprintf(stderr, "YOU WIN!\n");
        result = 0;
    }
    return result;
} /* end checkforwinner() */