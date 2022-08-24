#include <stdio.h>

/** In C, a struct is a user defined data type. A struct allows us to combine 
 * variables of different data types as members of a struct. This is how C can
 * implement Object-Oriented Programing, even though C is not an Object-
 * Oriented language.
 */

int main(int argc, char* argv[]) {

    /** For this example, we are representing traditional playing cards with 
     * the struct data type. Here, we give our struct a name, Card, and define
     * it as having the member variables, name, suit, and value. Declaring 
     * member variables works the same as declaring variables normally.
     */

    struct Card {
        char* name;
        char* suit;
        int value;
    };

    /** Lets start with defining just a few cards before building an entire
     * deck. When defining a variable that is of some struct data type, we must
     * start each declaration with "struct <MyStructName> <variablename>" 
     * (generically). Below we define 4 Card struct variables.
     */

    /* The Ace of Spades */
    struct Card SA = {"Ace", "Spades", 11};
    /* The Two of Diamonds*/
    struct Card D2 = {"2", "Diamonds", 2};
    /* The 7 of Clubs */
    struct Card C7 = {"7", "Clubs", 7};
    /* The Queen of Hearts */
    struct Card HQ = {"Queen", "Hearts", 10};

    /** To access members of a struct, we can use the dot (.), or member access
     * operator. Generically, this would look like "variableName.memberName". We
     * leverage this dot operator to generate the print statements below.
     */

    printf("The %s of %s is worth %d points.\n", SA.name, SA.suit, SA.value);
    printf("The %s of %s is worth %d points.\n", D2.name, D2.suit, D2.value);
    printf("The %s of %s is worth %d points.\n", C7.name, C7.suit, C7.value);
    printf("The %s of %s is worth %d points.\n", HQ.name, HQ.suit, HQ.value);

} /* end main() */