#include <stdio.h>
#include <stdlib.h> /* Gives us access to malloc() */

/* Struct declaration outside of main */
struct Card {
    char name;
    char suit;
    int value;
};

/* Prototype declaration of builddeck(), which returns a Card pointer */
struct Card* builddeck(); 

int main(int argc, char* argv[]) {

    struct Card *deck = builddeck(); /* Initialize a deck of playing cards */

    /* Print the contents of the deck of cards */
    int i;
    for (i = 0; i < 52; i++) {
        printf("The %c of %c is worth %d.\n", deck[i].name, deck[i].suit, deck[i].value);        
    }
    
    return 0;
} /* end main() */

struct Card* builddeck() {

    struct Card *deck; /* Here we declare an array of Card structs */

    /* malloc() is used to dynamically allocate a specified amount of memory 
    * from the heap. It returns a pointer of type void which can be cast to a 
    * pointer of any form */
    deck = malloc(52 * sizeof(struct Card));

    char* cnames = "23456789TJQKA"; /* A list of the 13 different card names */
    char* csuits = "SDCH"; /* Representing Spades, Diamonds, Clubs, and Hearts */

    /* Build an array of Card structs representing a deck of cards */
    int x, y, z; /* Initialize our counter variables */
    z = 0;
    for (x = 0; x < 4; x++) { /* For each card suit... */
        for (y = 0; y < 13; y++) { /* And for each card name... */
            int myVal; /* Initialize an int, myVal */
            if (cnames[y] == 'A') { /* If the card is an Ace... */
                myVal = 11; /* set myVal to 11 */
            } else if (cnames[y] == 'K') { /* If the card is a K... */
                myVal = 10; /* set myVal to 10 */
            } else if (cnames[y] == 'Q') { /* If the card is a Q... */
                myVal = 10; /* set myVal to 10 */
            } else if (cnames[y] == 'J') { /* If the card is a J... */
                myVal = 10; /* set myVal to 10 */
            } else if (cnames[y] == 'T') { /* If the card is a T(en)... */
                myVal = 10; /* set myVal to 10 */
            } else { /* Otherwise, convert the cards name to an int */
                myVal = cnames[y] - '0'; /* Unicode math, don't worry too much about this... */
            } /* end if-else block for assigning myVal*/

            /* Create a new Card with the given name, suit, and value */
            struct Card nextCard = {cnames[y], csuits[x], myVal};

            /* Add the nextCard to the next index of deck, then increment z */
            deck[z++] = nextCard;

        } /* end for loop thru cnames */
    } /* end for loop thru csuits */

    return deck; // return a pointer to an array of Card structs in the heap
} /* end builddeck() */
