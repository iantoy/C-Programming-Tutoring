/**
 * @file arcade2.c
 * @author Ian Toy (you@domain.com)
 * @brief A commandline arcade program that runs games using fork and exec. 
 * This implementation makes use of two helper functions, promptuser() and
 * setgame().
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
char* setgame(int input);

int main(int argc, char* argv[]) {

    pid_t pid;
    int status;

    printf("Welcome to the Linux Arcade!\n");
    char mygame[16];

    int inuse = 1;
    while (inuse) {

        int input = promptuser();       // set input with the return of promptuser    
        strcpy(mygame, setgame(input)); // pass input to setgame, return to mygame

        if (strlen(mygame) != 0) {      // if mygame is not an empty string...
            pid = fork();               // clone the current process with fork
            if (pid == 0) {             // if we are the child process...
                char *args[] = {};      // initialize an empty character array
                execvp(mygame, args);   // Run the game chosen by the user
                perror("exec");
                exit(-1);
            } else if (pid > 0) {       // if we are the parent process ...
                wait(&status);          // wait for the child process to terminate
                if (WIFEXITED(status)) {    // if child process terminated normally...
                    printf("Child process exited with status = %d\n", WEXITSTATUS(status));
                } else {                // child process did not terminate normally
                    printf("ERROR: Child process did not terminate normally!\n");
                }
                strcpy(mygame,"");      // clear mygame
            } else {
                perror("fork");
                exit(EXIT_FAILURE);
            } /* end if-else (pid) block */
        } else {    // if strlen(mygame) == 0, the user chose to quit 
            inuse = 0;
            printf("Thanks for playing!\n");
        } /* end if-else strlen(mygame) != 0 block*/
    } /* end while (inuse) */
    return 0;
} /* end main */

/**
 * @brief promptuser() prints a table of commands for the user and awaits input
 * using scanf. This is stored localy in input and returned.
 * 
 * @return int, the user's input, 1, 2, or 0
 */
int promptuser() {
    int input;
    printf("What would you like to play?\n");
    printf("1. tamagotchi\n");
    printf("2. cowboy\n");
    printf("0. QUIT\n");
    scanf("%d", &input);
    return input;
} /* end promptuser() */

/**
 * @brief setgame() accepts an integer, input, and returns an executable's name
 * as a null-terminated string.
 * 
 * @param input , an integer provided by the user, 1, 2, or 0
 * @return char* , the name of the executable to be run.
 */
char* setgame(int input) {
    switch (input) {
        case TAMAGOTCHI:
            return "./tamagotchi\0"; 
            break;
        case COWBOY:
            return "./cowboy2\0";
            break;
        case QUIT:
            return "";
            break;
        default:
            printf("Sorry, I didn't catch that...\n");
            break;
    } /* end switch (input) */
} /* end setgame */
