// BY Jacob Wirgård Wiklund & Anton Danker
// The screen when the game is running

#include <stdint.h>
#include "gameHeader.h"
#include "units.h"

//Game speed
int gameSpeed = 0;
// variable used to generate a random number
int random = 0;

// Init the random values used for the first enemie swarm positions
int randInt1;
int randInt2;
int randInt3;
int randInt4;
int randInt5;
int randInt6;
int randInt7;
int randInt8;

// Init the random values used for the second enemie swarm positions
int rand2Int1;
int rand2Int2;
int rand2Int3;
int rand2Int4;
int rand2Int5;
int rand2Int6;
int rand2Int7;
int rand2Int8;

//Generates a random number
int getRandomInt(int i) {
    random = (random*53 + 5) % 7283;
    return random%i;
}

//Uppdates the game when it is running
void updatePlaying() {
    //Determens the game speed
    gameSpeed++;

    //Instant game over if button 4 is pressed
    if(getbtn1()){
    evalueteScore();
    enemies.x = 129;
    enemies2.x = 129;
    GAMESTATE = 3;
    }

    //Updates the 14th time when rendering
    if(gameSpeed > 14) {
        unit_update();
        gameSpeed = 0;
    }
    
    // Render every cycle
    unit_render();
    display_update();
}
