/**
 * @file arcade1.c
 * @author Ian Toy (you@domain.com)
 * @brief A commandline arcade program that runs games using fork and exec. 
 * This implementation makes use of the promptuser() helper function.
 * @version 0.1
 * @date 2022-10-20
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define QUIT 0
#define TAMAGOTCHI 1
#define COWBOY 2

int promptuser();

int main(int argc, char* argv[]) {

    pid_t pid;
    int status;

    printf("Welcome to the Linux Arcade!\n");
    char mygame[16];

    int inuse = 1;
    while (inuse) {

        /** Prompt the user to choose a game and store it's name as mygame. 
         * When passing an executable name to an exec function, it is important 
         * to pass a null terminating string, hence the null escape characters 
         * '\0' at the end of these char* literals. */
        int input = promptuser();    
        switch (input) {
            case TAMAGOTCHI:
                strcpy(mygame, "./tamagotchi\0"); 
                break;
            case COWBOY:
                strcpy(mygame, "./cowboy2\0");
                break;
            case QUIT:
                printf("Goodbye!\n");
                inuse = 0;
                break;
            default:
                printf("Sorry, I didn't catch that...\n");
                break;
        } /* end switch (input) */

        if (strlen(mygame) != 0) {
            pid = fork();
            if (pid == 0) {
                char *args[] = {};
                execvp(mygame, args);   /* Run the game chosen by the user */
                perror("exec");
                exit(-1);
            } else if (pid > 0) {
                wait(&status); /* wait for the child process to terminate */

                if (WIFEXITED(status)) { /* child process terminated normally */
                    printf("Child process exited with status = %d\n", WEXITSTATUS(status));
                } else { /* child process did not terminate normally */
                    printf("ERROR: Child process did not terminate normally!\n");
                }
                strcpy(mygame,"");    /* clear mygame */
            } else {
                perror("fork");
                exit(EXIT_FAILURE);
            } /* end if-else (pid) block */
        } /* end if-else strlen(mygame) != 0 block*/
    } /* end while (inuse) */

    return 0;
} /* end main */

int promptuser() {
    int input;
    printf("What would you like to play?\n");
    printf("1. tamagotchi\n");
    printf("2. cowboy\n");
    printf("0. QUIT\n");
    scanf("%d", &input);
    return input;
} /* end promptuser() */