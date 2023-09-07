/**
 * @file arcade3.c
 * @author Ian Toy (you@domain.com)
 * @brief A commandline arcade program that runs games using fork and exec. 
 * This implementation makes use signal handling 
 * @version 0.1
 * @date 2022-10-24
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
void sig_child(int signo);


int main(int argc, char* argv[]) {

    pid_t pid;
    int status;

    /* Signal Handling */
    if (signal(SIGINT, sig_child) == SIG_ERR) {
        printf("Can't catch SIGINT\n");
    }
    if (signal(SIGTSTP, sig_child) == SIG_ERR) {
        printf("Can't catch SIGTSTP\n");
    }

    printf("Welcome to the Linux Arcade!\n");
    char mygame[16];

    int inuse = 1;
    while (inuse) {

        int input = promptuser();       // set input with the return of promptuser    
        strcpy(mygame, setgame(input)); // pass input to setgame, return to mygame

        if (strcmp(mygame, "QUIT") == 0) {  // if mygame is not "QUIT"...
            inuse = 0;
        } else if (strlen(mygame) > 0) {  // if mygame is not an empty string...
            pid = fork();               // clone the current process with fork
            if (pid == 0) {             // if we are the child process...
                char *args[] = {};      // initialize an empty character array
		execvp(mygame, args);   /* Run the game chosen by the user */
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
        } /* end if-else mygame != "QUIT" block*/
    } /* end while (inuse) */
    printf("Thanks for playing!\n");
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
            return "QUIT";
            break;
        default:
            printf("Sorry, I didn't catch that...\n");
            break;
    } /* end switch (input) */
} /* end setgame */

/** @brief sig_child(int signo) takes in a signal number as an argument and sends a 
 * kill signal to a child process based on that input.
 *
 * @param int signo, a signal number
 */
void sig_child(int signo) {
	switch(signo) {
		case SIGINT: /* Interrupt signal */
			printf("received SIGINT signal %d\n", signo);
			kill(getppid(), SIGINT);
			printf("this game has been interrupted.\n");
			break;
		case SIGTSTP: /* Suspension signal */
			printf("received SIGTSTP signal %d\n", signo);
			kill(getppid(), SIGTSTP);
			printf("this game has been suspended.\n");
			break;
	} /* end switch(signo) case */
} /* end sig_child() */
