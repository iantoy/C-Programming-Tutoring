/**
 * @file arcade4.c
 * @author Ian Toy (you@domain.com)
 * @brief A commandline arcade program that runs games using fork and exec. 
 * This implementation makes use of output redirection to generate a "gamelog"
 * file which records all terminal output to a .txt file with a new game exe,
 * rock paper scissors (rps.c).
 * @version 0.1
 * @date 2022-11-09
 * 
 * @copyright Copyright (c) 2022
 */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include "arcade_header.h"

int main(int argc, char* argv[]) {

    pid_t pid;
    int status;
    int fderr;

    /* Signal Handling */
    if (signal(SIGINT, sig_child) == SIG_ERR) {
        printf("Can't catch SIGINT\n");
    }
    if (signal(SIGTSTP, sig_child) == SIG_ERR) {
        printf("Can't catch SIGTSTP\n");
    }

    printf("Welcome to the Linux Arcade!\n");
    if ((fderr = open("gamelog.txt", O_CREAT | O_APPEND | O_WRONLY, 0755)) == -1) {
        printf("Error opening file crashlog.txt for error\n");
    } /* end file open error handling*/
    dup2(fderr, STDERR_FILENO);

    char mygame[16];
    int inuse = 1;
    while (inuse) {
        strcpy(mygame, "");      // clear mygame
        int input = promptuser();       // set input with the return of promptuser    
        strcpy(mygame, setgame(input)); // pass input to setgame, return to mygame

        if (strcmp(mygame, "QUIT") == 0) {  // if mygame is not "QUIT"...
            inuse = 0;
        } else if (strlen(mygame) > 0) {  // if mygame is not an empty string...
            pid = fork();               // clone the current process with fork
            if (pid == 0) {             // if we are the child process...
                execvp(mygame, NULL);   // Run the game chosen by the user
                perror("exec");
                exit(-1);
            } else if (pid > 0) {       // if we are the parent process ...
                wait(&status);          // wait for the child process to terminate
                if (WIFEXITED(status)) {    // if child process terminated normally...
                    fprintf(stderr, "Child process exited with status = %d\n", WEXITSTATUS(status));
                } else {                // child process did not terminate normally
                    fprintf(stderr, "ERROR: Child process did not terminate normally!\n");
                }
            } else {
                perror("fork");
                exit(EXIT_FAILURE);
            } /* end if-else (pid) block */
        } /* end if-else mygame != "QUIT" block*/
    } /* end while (inuse) */
    printf("Thanks for playing!\n");
    return 0;
} /* end main */
