// By Jacob Wirgård Wiklund & Anton Danker

#include "gameHeader.h"

// Init all the units
void unit_init(void);

// enum for units 
typedef enum EntityType {
    PLAYER, ENEMIE
} EntityType_t;

// Hitbox
typedef struct Hitbox{
    int width;
    int height;
} Hitbox;

// Player struct
typedef struct Player {
    enum EntityType type;
    int x;
    int y;
    int playerScore;
    Hitbox hitbox;
} Player;

// Object struct
typedef struct Object {
    enum EntityType type;
    double x;
    int y;
    Hitbox hitbox;
} Object;

// Player and the different update & rendering methods
extern Player player;
extern Object enemies;
extern Object enemies2;
void renderShip(int,int);
void updatePlayer();
void renderEnemie(int,int);
