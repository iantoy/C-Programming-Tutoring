/**
 * @file tamagotchi.c
 * @author Ian Toy (you@domain.com)
 * @brief A command line Tamagotchi emulator
 * @version 0.1
 * @date 2022-09-29
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <stdio.h>
#include <string.h>

typedef struct tamagotchi {
    char name[32];
    int happiness;
    int hunger;
    int tiredness;
} TAMA;

int main() {

    char name[32];
    printf("Name your Tamagotchi: ");
    scanf("%s", name);
    printf("%s sounds like a great name!\n", name);

    TAMA mypet = {"", 0, 0, 0};
    strcpy(mypet.name, name);

    int inuse = 1;  /* tracks whether or not the game is inuse */
    char input[8];

    while(inuse) {
        printf("\nWhat would you like to do with %s?\n", mypet.name);
        printf("(play, feed, nap, quit): ");
        scanf("%s", input);

	if (strcmp(input, "play") == 0) {
            printf("\n%s looks like they're having fun!\n", mypet.name);
            mypet.happiness++;
            mypet.hunger += 4;
            mypet.tiredness += 2;
        } else if (strcmp(input, "feed") == 0) {
            printf("\nEnjoy your meal, %s!\n", mypet.name);
            mypet.hunger = 0;
        } else if (strcmp(input, "nap") == 0) {
            printf("\nSleep well, %s!\n", mypet.name);
            mypet.tiredness = 0;
            mypet.hunger += 2;
        } else if (strcmp(input, "quit") == 0) {
            printf("\nGoodbye!\n");
            inuse = 0;
        } else {
            printf("Sorry, I didn't catch that.\n");
        }

        /* Status Alerts */
        if (mypet.hunger >= 5) {
            printf("\n%s is hungry!\n", mypet.name);
        } else if (mypet.tiredness >= 5) {
            printf("\n%s is sleepy!\n", mypet.name);
        }
    } /* end while(inuse) */

    return 0;
} /* end main() */
