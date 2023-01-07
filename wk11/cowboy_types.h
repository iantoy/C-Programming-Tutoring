/* Here we define a PLAYER struct with typedef, allowing us to declare structs
of this type by simply writing PLAYER before the new variable name, as opposed
to "struct Player" like in previous weeks examples. */
typedef struct Players {
    int hp;
    int ammo;
    int shield;
    int action;
} PLAYER;