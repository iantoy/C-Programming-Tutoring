#include<stdio.h>
#include<stdarg.h>  // for variatic function
#include<unistd.h>  // for sleep

#define TRUE 1
#define FALSE 0

static int readyForLaunch = FALSE;

/*
This function is a variadic (takes various numbers of arguments)
  helper function to print the countdown
arguments: int the number of arguments, and int(s) to print
return: nothing
ref: https://en.cppreference.com/w/c/variadic
*/
void countdown(int num_args, ... ){
    va_list args;
    va_start(args, num_args);

    int i;
    for(i = 0; i < num_args; i++){
        int value = va_arg(args, int);
        printf("\n\t\t\t%d", value);
        sleep(1);
    }
    printf("\n");
    
    va_end(args);

    return;
} // end countdown

/*
Determines whether the fuel is ready for launch
  Can only launch if there is > 40,000 pounds remaining
arguments:  int, the fuel remaining
returns: int, TRUE: fuel is ready for launch, FALSE: fuel too low to launch
*/
int fuelReady(int fuelRemaining){
    if(fuelRemaining % 2 == 0 && fuelRemaining > 40000){
        printf("......Fuel is a go!\n");
        return TRUE;
    } else {
        printf("\tout of gas boss\n");
        return FALSE;
    }
} // end fuelReady

/*
Determines whether the crew is ready for launch
  Can only launch if all three crewmembers are ready (TRUE)
arguments:  int, the size of the array, array of ints to represent each crewmembers status
returns: int, TRUE: all three crew are ready for launch, FALSE: otherwise
*/
int checkCrewReady(int size, int *arr){
    int everyoneIsReady = FALSE;
    int i = 0;
    for(i = 0; i <= size; i++){
        printf("...Crewmember #%d, press 1 if you ready:.....  %d\n", (i+1), *(arr + i));
        if( *(arr + i) == TRUE){
            everyoneIsReady = TRUE;
        } else {
            everyoneIsReady = FALSE;
            // Note to supervisor for code: I just cranked this out real quick on a Friday afternoon
            // so we could meet the deadline, but someone should really look at this
            // it might need something else here.
        }
    }

    return everyoneIsReady;

} // end checkCrewReady


/*
Determines whether the computer is ready for launch
  Can only launch if both mission computers agree.
arguments:  int, the size of the array, array of ints to represent each crewmembers status
returns: int, TRUE: if the computers are ready for launch, FALSE: otherwise
*/
int checkComputers(int firstComputer, int secondComputer){
    int computersReady = TRUE;
    // checks to see if first computer is ready
    //  since computersReady is TRUE, if firstComputer is FALSE, the && statement
    //  returns FALSE.  If firstComputer is TRUE, this sets computersReady to TRUE
    //  this is one way to set a flag with multiple inputs
    computersReady = computersReady && firstComputer;
    computersReady = computersReady && secondComputer;

    if(firstComputer == TRUE){
        printf("......1st Computer READY\n");
    }
    if(secondComputer == TRUE){
        printf("......2nd Computer READY\n");
    }
    if(computersReady == TRUE){
        printf("......Computers are a GO!\n");
    }

    return computersReady;
}


int main(int argc, char **argv){
    // some initial variables
    int fuelStillInTheTank = 50000;
    int numberOfCrewmembers = 3;
    int isEachCrewmemberReady[] = {TRUE, FALSE, FALSE};  // represents three crewmembers, each with their own status
    int allReadyForLaunch = FALSE;

    // start the countdown process
    countdown(3, 15, 14, 13);

    // check crew systems
    if( checkCrewReady(numberOfCrewmembers, isEachCrewmemberReady) == TRUE){
        printf("......copy, Crew are a GO!\n\n");
        fuelStillInTheTank = fuelStillInTheTank - 5000;
        allReadyForLaunch = TRUE;
    } else {
        printf("===> abort, not everyone is ready!\n\n");
        allReadyForLaunch = FALSE;
    }
    

    // check computer status
    countdown(2, 12, 11);
    if(checkComputers(TRUE, FALSE) == TRUE ){
        printf("......copy, Computers are a GO!\n\n");
        allReadyForLaunch = TRUE;
    } else {
        printf("===> abort, Computers not ready, call Bill Gates!\n\n");
        allReadyForLaunch = TRUE;
    }

    // check fuel status
     if( fuelReady(fuelStillInTheTank) == TRUE){
        printf("......copy, Fuel is a GO!\n\n");
        allReadyForLaunch = TRUE;
    } else {
        printf("===> abort, not enough FUEL!\n\n");
        allReadyForLaunch = FALSE;
    }
    

    // check range safety
    countdown(3, 10, 9, 8);
    printf("...Range Safety is a GO!\n\n");
    allReadyForLaunch = TRUE;

    // launch
    countdown(3, 7, 6);
    if(allReadyForLaunch){
        printf("Launching in 5");
        int i;
        for(i = 0; i < 5; i++){
            printf(".....%d", i);
        }
        printf("\nTAKEOFF  !!!\n\n\n");
        printf("The rocket has cleared the tower \n\n\n");
    } else {
        printf(" LAUNCH ABORTED !!\n\n");
    }
    

    return 0;
}
// very loosely based on the code here: https://education.launchcode.org/intro-to-professional-web-dev/chapters/errors-and-debugging/exercises.html