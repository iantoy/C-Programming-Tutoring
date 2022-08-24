/**
 * @file arcade_crashlog.c
 * @author Ian Toy (iantoy@uab.edu)
 * @brief The purpose of this program is to demonstrate file stream redirection
 * with child processes using dup2(). This expands on our previous version of 
 * the arcade application by including a game-logging feature that records 
 * error messages and gameplay using the methods described above.
 * 
 * Crash logger? just pass stderr, write when a game crashes or is force closed
 * saves trouble of trying to write to terminal and file with dup2().
 * 
 * @version 0.1
 * @date 2022-03-21
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/* Preprocessor commands */
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

/* Global Definitions for Menu Options */
#define RPS 1
#define GUESS 2
#define COWBOY 3
#define QUIT 4

/* Function Prototypes */
int promptuser();
void sig_child(int signo);

int main(int argc, char* argv[]) {

    /* Variable Declarations */
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

    printf("Welcome to the Arcade!\n");

    /* Open standard error stream, error handling */
    if ((fderr = open("stderr.txt", O_CREAT | O_APPEND | O_WRONLY, 0755)) == -1) {
        printf("Error opening file stderr.txt for error\n");
    } /* end file open error handling*/

    /* Begin core game loop */
    int inuse = 1;
    while (inuse) {
        char mygame[8];
        int input = promptuser();

        switch(input) { /* Assign a .exe name to mygame based on user input */
            case RPS:
                strcpy(mygame,"./rps\0");
                break;
            case GUESS:
                strcpy(mygame,"./guess\0");
                break;
            case COWBOY:
                strcpy(mygame,"./cowboy\0");
                break;
            case QUIT:
                printf("Thanks for playing!\n");
                inuse = 0;
                exit(0);
        } /* end switch(input) */

        if (strlen(mygame) != 0) { /* If the user chose to play a game... */
            pid = fork(); /* Fork the current process */
            if (pid == 0) { /* Child Process */

                /* Replace the standard error stream with stderr.txt */
                dup2(fderr, 2);

                execvp(mygame, NULL);   /* Run the game chosen by the user */
                perror("exec");
                exit(-1);
            } else if (pid > 0) { /* Parent Process */
                wait(&status); /* wait for the child process to terminate */
                if (WIFEXITED(status)) { /* child process terminated normally */
                    printf("Child process exited with status = %d\n", WEXITSTATUS(status));
                } else { /* child process did not terminate normally */
                    printf("ERROR: Child process did not terminate normally!\n");
                    /* look at the man page for wait (man 2 wait) to 
                    * determine how the child process was terminated */
                }
            } else { /* we have an error in process creation */
                perror("fork");
                exit(EXIT_FAILURE);
            } /* end child process handling */
        } /* end if mygame != null */
    } /* end while(inuse) */

    return 0;
} /* end main */

/* Helper Functions */

/** @brief promptuser() displays the arcade's table of options. The user enters
 * an integer, which is handled using scanf and stored in input. input is then
 * returned.
 * 
 * @return int, the user's choice
 */
int promptuser() {
    printf("What game would you like to play?\n");
    printf("1. rock, paper, scissors\n");
    printf("2. guess a number\n");
    printf("3. cowboy\n");
    printf("4. view stats\n");
    printf("5. save progress\n");
    printf("6. QUIT\n");

    int input;
    scanf("%d", &input);
    return input;
} /* end promptuser() */

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