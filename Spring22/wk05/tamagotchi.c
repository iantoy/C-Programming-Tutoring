/**
 * @file tamagotchi.c
 * @author Ian Toy (iantoy@uab.edu)
 * @brief The purpose of this program is to demonstrate the use of struct
 * pointers and arrow member accessor syntax by implementing a basic tamagotchi
 * application. The player can play with thier pet, feed their pet, or put 
 * their pet down for a nap. This code also shows how unary operators can be 
 * used with these struct accessors to update their value.
 * @version 0.1
 * @date 2022-02-24
 * @copyright Copyright (c) 2022
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tamagotchi {
    char name[16];
    int happiness;    
    int hunger; 
    int tiredness;    
} TAMA;

int main(int argc, char* argv[]){

    printf("Welcome to Tamagatchi Maker!\n");
    /* Ask the user to name their new tamagotchi and store it in myname */
    printf("What is your tamagatchi's name?: ");
    char myname[16];
    scanf("%s", &myname);

    /* Create a new TAMA struct with myname and initial values */
    TAMA mytama = {myname, 0, 0, 0};
    TAMA *ptr_tama; /* Initialize a TAMA pointer */
    ptr_tama = &mytama; /* Assign that pointer to the address of mytama */
    strcpy(ptr_tama->name, myname);
    printf("%s? That sounds like a great name!\n", ptr_tama->name);

    char input[8];
    int inuse = 1;

    /* Core game loop */
    while(inuse == 1) {

        /* User input prompts */
        printf("What would you and %s like to do?\n", ptr_tama->name);
        printf("(play, feed, nap, quit): ");
        scanf("%s", &input);

        /* User Actions */
        if(strcmp(input, "play") == 0){
            printf("Have fun!\n");
            ptr_tama->happiness++;
            ptr_tama->tiredness+=2;
            ptr_tama->hunger+=4;
        }
        if(strcmp(input, "feed") == 0){
            printf("Enjoy your meal!\n");
            ptr_tama->hunger = 0;
        }
        if(strcmp(input, "nap") == 0){
            printf("Sleep well!\n");
            ptr_tama->tiredness = 0;
        }
        if(strcmp(input, "quit") == 0){
            printf("Goodbye!\n");
            inuse = 0;
        }

        /* Status Alerts */
        if (ptr_tama->hunger >= 10){
            printf("%s is starving!\n", ptr_tama->name);
        }
        if (ptr_tama->tiredness >= 10) {
            printf("%s is feeling sleepy...\n", ptr_tama->name);
        }
    } /* end while(inuse) loop */
} /* end main() */