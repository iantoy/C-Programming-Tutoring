#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>

#define QUIT 0
#define TAMAGOTCHI 1
#define COWBOY 2
#define RPS 3

int promptuser();
char* setgame(int input);
void sig_child(int signo);


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
    printf("3. rock paper scissors\n");
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
        case RPS:
            return "./rps\0";
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