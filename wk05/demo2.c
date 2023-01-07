#include <stdio.h>

/** Like any other variable, we can create arrays of structs of the same type
 * in C. This example will illustrate one way of creating an array of structs 
 * by building a deck of playing cards.
 */

int main(int argc, char* argv[]) {

    /** Like in the earlier example, we define our struct Card within main().
     * Here, we are using single char values to represent the name and suit 
     * for the sake of brevity.
     * 
     * Abbreviations:
     *  suits: S = Spade, D = Diamonds, C = Clubs, H = Hearts
     *  names: T = 10, J = Jack, Q = Queen, K = King, A = Ace
     */
    struct Card {
        char name; 
        char suit;
        int value;
    };

    /** Below, we declare each Card variable to be included in our deck of 
     * cards. Each member value in the new struct variable must line up with 
     * the sequence that the member variables are declared in the struct 
     * definition.
     */

    struct Card S2 = {'2', 'S', 2};
    struct Card S3 = {'3', 'S', 3};
    struct Card S4 = {'4', 'S', 4};
    struct Card S5 = {'5', 'S', 5};
    struct Card S6 = {'6', 'S', 6};
    struct Card S7 = {'7', 'S', 7};
    struct Card S8 = {'8', 'S', 8};
    struct Card S9 = {'9', 'S', 9};
    struct Card ST = {'T', 'S', 10};
    struct Card SJ = {'J', 'S', 10};
    struct Card SQ = {'Q', 'S', 10};
    struct Card SK = {'K', 'S', 10};
    struct Card SA = {'A', 'S', 11};
    struct Card D2 = {'2', 'D', 2};
    struct Card D3 = {'3', 'D', 3};
    struct Card D4 = {'4', 'D', 4};
    struct Card D5 = {'5', 'D', 5};
    struct Card D6 = {'6', 'D', 6};
    struct Card D7 = {'7', 'D', 7};
    struct Card D8 = {'8', 'D', 8};
    struct Card D9 = {'9', 'D', 9};
    struct Card DT = {'T', 'D', 10};
    struct Card DJ = {'J', 'D', 10};
    struct Card DQ = {'Q', 'D', 10};
    struct Card DK = {'K', 'D', 10};
    struct Card DA = {'A', 'D', 11};
    struct Card C2 = {'2', 'C', 2};
    struct Card C3 = {'3', 'C', 3};
    struct Card C4 = {'4', 'C', 4};
    struct Card C5 = {'5', 'C', 5};
    struct Card C6 = {'6', 'C', 6};
    struct Card C7 = {'7', 'C', 7};
    struct Card C8 = {'8', 'C', 8};
    struct Card C9 = {'9', 'C', 9};
    struct Card CT = {'T', 'C', 10};
    struct Card CJ = {'J', 'C', 10};
    struct Card CQ = {'Q', 'C', 10};
    struct Card CK = {'K', 'C', 10};
    struct Card CA = {'A', 'C', 11};
    struct Card H2 = {'2', 'H', 2};
    struct Card H3 = {'3', 'H', 3};
    struct Card H4 = {'4', 'H', 4};
    struct Card H5 = {'5', 'H', 5};
    struct Card H6 = {'6', 'H', 6};
    struct Card H7 = {'7', 'H', 7};
    struct Card H8 = {'8', 'H', 8};
    struct Card H9 = {'9', 'H', 9};
    struct Card HT = {'T', 'H', 10};
    struct Card HJ = {'J', 'H', 10};
    struct Card HQ = {'Q', 'H', 10};
    struct Card HK = {'K', 'H', 10};
    struct Card HA = {'A', 'H', 11};

    /** Here, we "build our deck of cards" by declaring an array of Card
     * structs called deck and set its size to 52 elements, the standard number
     * of cards in a deck of playing cards. We initialize this array directly 
     * by declaring deck with each of the Card variables we defined above. */
    struct Card deck[52] = {S2, S3, S4, S5, S6, S7, S8, S9, ST, SJ, SQ, SK, SA,
        D2, D3, D4, D5, D6, D7, D8, D9, DT, DJ, DQ, DK, DA, C2, C3, C4, C5, C6,
        C7, C8, C9, CT, CJ, CQ, CK, CA, H2, H3, H4, H5, H6, H7, H8, H9, HT, HJ,
        HQ, HK, HA};


    /** Like in playingcards0, we use the dot (.) operator to access member 
     * values, but this time in a for loop over an array of Cards, deck. Since
     * each element of deck is a Card, we can use the dot operator to access 
     * members of each element in this array.
     */
    int i;
    for (i = 0; i < 52; i++) {
        printf("The %c of %c is worth %d\n",
            deck[i].name, deck[i].suit, deck[i].value);
    } /* end for loop */

} /* end main() */