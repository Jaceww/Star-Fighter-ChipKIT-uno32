//By Jacob Wirgård Wiklund & Anton Danker
// This is the unit data file that stores all the figures used in the game

#include "units.h"
#include <stdint.h>

//Render the player
void renderShip(int x, int y){
        displayPixel(x,y-3);
        displayPixel(x+1,y-1);
        displayPixel(x+1,y-1);
        displayPixel(x+1,y-2);
        displayPixel(x+2,y-1);
        displayPixel(x+2,y-2);
        displayPixel(x+2,y-3);
        displayPixel(x+2,y);
        displayPixel(x+3,y);
        displayPixel(x+3,y-1);
        displayPixel(x+3,y-2);
        displayPixel(x+4,y-1);
        displayPixel(x+4,y-2);
        displayPixel(x+5,y-1);
        displayPixel(x+5,y-2);
        displayPixel(x+6,y-1);
}

//Render the enemie
void renderEnemie(int x, int y){
        displayPixel(x,y-1);
        displayPixel(x,y-3);
        displayPixel(x+1,y);
        displayPixel(x+1,y-4);
        displayPixel(x+2,y);
        displayPixel(x+2,y-1);
        displayPixel(x+2,y-3);
        displayPixel(x+2,y-4);
        displayPixel(x+3,y);
        displayPixel(x+3,y-1);
        displayPixel(x+3,y-2);
        displayPixel(x+3,y-3);
        displayPixel(x+3,y-4);
        displayPixel(x+4,y-1);
        displayPixel(x+4,y-2);
        displayPixel(x+4,y-3);
        displayPixel(x+5,y-2);
}
