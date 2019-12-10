// By Jacob Wirgård Wiklund och Anton Danker
//Game control file that handles game logic

#include <stdint.h>
#include "units.h"
#include "gameHeader.h"
#define PLAYER_X 10

//Random Numbers, used for the position of the enemies
int random2 = 0;
int randInt1 = 0;
int randInt2 = 0;
int randInt3 = 0;
int randInt4 = 0;
int randInt5 = 0;
int randInt6 = 0;
int randInt7 = 0;
int randInt8 = 0;

int rand2Int1 = 0;
int rand2Int2 = 0;
int rand2Int3 = 0;
int rand2Int4 = 0;
int rand2Int5 = 0;
int rand2Int6 = 0;
int rand2Int7 = 0;
int rand2Int8 = 0;

//Create two enemie objects
Object enemies;
Object enemies2;

// Added one counter
int timeCounter = 0;

//Created a player object
Player player;


// Initialise enemies struct
void enemies_init(){
    Object ob = { .type = ENEMIE, .x = 129, .y = FLOOR_Y_UP, .hitbox = { .width = 2, .height = 1}};
    enemies = ob;
    Object ob2 = { .type = ENEMIE, .x = 129, .y = FLOOR_Y_UP, .hitbox = { .width = 2, .height = 1}};
    enemies2 = ob2;
}

// Initialise units
void unit_init() {
    // Player variables
    player.type = PLAYER;
    player.y = FLOOR_Y_UP;
    player.playerScore = 0;
    player.hitbox.width = 5;
    player.hitbox.height = 1;

    // initialise enemies
    enemies_init();
}

// Render The player (the ship) and the enemies
void render(EntityType_t type, int x, int y) {
    switch(type) {
        case PLAYER:
            renderShip(x, y);
            break;
        case ENEMIE:
            renderEnemie(x, y);
            break;
    }
}

//Reset the game and change to game over screen
void reset() {
    evalueteScore();
    enemies.x = 129;
    enemies2.x = 129;
    GAMESTATE = 3;
}


/* Assign the switch collision different random values 
to generate all the hit boxes for the two swarms of enemies*/
void checkCollisions(){
    switchCollision(randInt1);
    switchCollision(randInt2);
    switchCollision(randInt3);
    switchCollision(randInt4);
    switchCollision(randInt5);
    switchCollision(randInt6);
    switchCollision(randInt7);
    switchCollision(randInt8);

    switchCollision2(rand2Int1);
    switchCollision2(rand2Int2);
    switchCollision2(rand2Int3);
    switchCollision2(rand2Int4);
    switchCollision2(rand2Int5);
    switchCollision2(rand2Int6);
    switchCollision2(rand2Int7);
    switchCollision2(rand2Int8);
}

/* Switch statement for the first swarm of enemies. It matches 
the render switch statemnt for the first swarm enemies*/
void switchCollision(int randInt){
    switch (randInt){
         case 0:
            typOfCollision(100, -30);
            break;
        case 1:
            typOfCollision(0, 0);
            break;
        case 2:    
            typOfCollision(40, -25);
            break;
        case 3:    
            typOfCollision(15, -60);
            break;
        case 4:
            typOfCollision(30, -5);
            break;
        case 5:
            typOfCollision(50, -13);
            break;
        case 6:
           typOfCollision(35, -20);
            break;
        case 7:
            typOfCollision(60, -35);
            break;
        case 8:
            typOfCollision(20, -13);
            break;
        case 9:
            typOfCollision(12, -10);
            break;
        case 10:
            typOfCollision(60, -60);
            break;
        case 11:
            typOfCollision(70, -40);
            break;
        case 12:
            typOfCollision(80, 0);
            break;
        case 13:
            typOfCollision(90, -50);
            break;
        case 14:
            typOfCollision(75, -13);
            break;
        case 15:
            typOfCollision(95, -10);
            break;
        case 16:
            typOfCollision(110, -60);
            break;
        } 
}

/* Switch statement for the second swarm of enemies.It matches 
the render switch statemnt for the second swarm of enemies*/
void switchCollision2(int randInt){
    switch (randInt){
         case 0:
            typOfCollision2(200, -30);
            break;
        case 1:
            typOfCollision2(100, 0);
            break;
        case 2:    
            typOfCollision2(140, -25);
            break;
        case 3:    
            typOfCollision2(115, -60);
            break;
        case 4:
            typOfCollision2(130, -5);
            break;
        case 5:
            typOfCollision2(150, -13);
            break;
        case 6:
           typOfCollision2(135, -20);
            break;
        case 7:
            typOfCollision2(160, -35);
            break;
        case 8:
            typOfCollision2(120, -13);
            break;
        case 9:
            typOfCollision2(112, -10);
            break;
        case 10:
            typOfCollision2(160, -60);
            break;
        case 11:
            typOfCollision2(170, -40);
            break;
        case 12:
            typOfCollision2(180, 0);
            break;
        case 13:
            typOfCollision2(190, -50);
            break;
        case 14:
            typOfCollision2(175, -13);
            break;
        case 15:
            typOfCollision2(195, -10);
            break;
        case 16:
            typOfCollision2(210, -60);
            break;
        } 
}

//expands the hit-box for the first swarm of enemies
void typOfCollision(int x, int y){
    collision(x-1,y-1);
    collision(x-2,y-2);
    collision(x,y);
    collision(x+1,y+1);
    collision(x+2,y+2);
}

//expands the hit-box for the second swarm of enemies
void typOfCollision2(int x, int y){
    collision2(x-1,y-1);
    collision2(x-2,y-2);
    collision2(x,y);
    collision2(x+1,y+1);
    collision2(x+2,y+2);
}


// checks collisions on the first swarm of enmies
void collision(int xDiff, int yDiff){
    if(PLAYER_X >= enemies.x + xDiff &&
    PLAYER_X <= enemies.x + xDiff + enemies.hitbox.width ||
    PLAYER_X  + player.hitbox.width >= (int)enemies.x + xDiff &&
    PLAYER_X + player.hitbox.width <= (int)enemies.x + xDiff + enemies.hitbox.width) {
        if(player.y >= enemies.y + yDiff && 
        player.y <= enemies.y + yDiff + (int)enemies.hitbox.height || 
        player.y >= enemies.y + yDiff && 
        player.y <= enemies.y + yDiff + (int)enemies.hitbox.height) {
            reset();
        }
    }
} 


// checks collisions on the second swarm of enmies
void collision2(int xDiff, int yDiff){
    if(PLAYER_X >= enemies2.x + xDiff &&
    PLAYER_X <= enemies2.x + xDiff + enemies2.hitbox.width ||
    PLAYER_X  + player.hitbox.width >= (int)enemies2.x + xDiff &&
    PLAYER_X + player.hitbox.width <= (int)enemies2.x + xDiff + enemies2.hitbox.width) {
        if(player.y >= enemies2.y + yDiff && 
        player.y <= enemies2.y + yDiff + (int)enemies2.hitbox.height || 
        player.y >= enemies2.y + yDiff && 
        player.y <= enemies2.y + yDiff + (int)enemies2.hitbox.height) {
            reset();
        }
    }
} 

//Updates all the player variables and controlls movement
void updatePlayer() {
    //Increment time counter
    timeCounter++;

    //If the left most button is pressed move player up
    if(getbtns() == 4 && getbtns() != 2 && player.y > 3){
        player.y -= 1;
    }

    //If the middle button is pressed move player down
    if(getbtns() == 2 && getbtns() != 4 &&  player.y < 31){
        player.y += 1;
    }
}

// Update enemie values and highscore
void updateEnemieControl() {
    // Add to the highscore if an enemie passes by
    if(enemies.x < -2 || enemies2.x < -2){    
        SCORE ++;
    }
    /*Generates new random values for the first 
    swarm and reset the position*/
    if(enemies.x < -110){
        enemies.x = 129;
        randInt1 = getRandomInt(16);
        randInt2 = getRandomInt(16);
        randInt3 = getRandomInt(16);
        randInt4 = getRandomInt(16);
        randInt5 = getRandomInt(16);
        randInt6 = getRandomInt(16);
        randInt7 = getRandomInt(16);
        randInt8 = getRandomInt(16);
    }
    /*Generates new random values for the second 
    swarm and reset the position*/
    if(enemies2.x < -220){
        enemies2.x = 129;
        rand2Int1 = getRandomInt(16);
        rand2Int2 = getRandomInt(16);
        rand2Int3 = getRandomInt(16);
        rand2Int4 = getRandomInt(16);
        rand2Int5 = getRandomInt(16);
        rand2Int6 = getRandomInt(16);
        rand2Int7 = getRandomInt(16);
        rand2Int8 = getRandomInt(16);

    }

    // Increase the speed of the enemies based on score
    enemies.x -= 1.3 + 0.005*SCORE;
    enemies2.x -= 1.3 + 0.005*SCORE;
}
   
// Render enemies and highscore
void unit_render() {
    //Render the first enemie swarm based on random values
    generateRandomObst(randInt1);
    generateRandomObst(randInt2);
    generateRandomObst(randInt3);
    generateRandomObst(randInt4);
    generateRandomObst(randInt5);
    generateRandomObst(randInt6);
    generateRandomObst(randInt7);
    generateRandomObst(randInt8);
    
    //Render the second enemie swarm based on random values
    generateRandomObst2(rand2Int1);
    generateRandomObst2(rand2Int2);
    generateRandomObst2(rand2Int3);
    generateRandomObst2(rand2Int4);
    generateRandomObst2(rand2Int5);
    generateRandomObst2(rand2Int6);
    generateRandomObst2(rand2Int7);
    generateRandomObst2(rand2Int8);

    //Render the player and displays the highscore
    render(PLAYER,PLAYER_X,player.y);
    displayDigit(97,0, SCORE);
    
}

//Render the first enemie swarm with a switch statement based on random values
void generateRandomObst(int randInt){
    switch (randInt){
         case 0:
            render(enemies.type, enemies.x + 100, enemies.y - 30);
            break;
        case 1:
            render(enemies.type, enemies.x, enemies.y);
            break;
        case 2:    
            render(enemies.type, enemies.x+40, enemies.y-25);
            break;
        case 3:    
            render(enemies.type, enemies.x+15, enemies.y-60);
            break;
        case 4:
            render(enemies.type, enemies.x+30, enemies.y-5);
            break;
        case 5:
            render(enemies.type, enemies.x+50, enemies.y-13);
            break;
        case 6:
            render(enemies.type, enemies.x+35, enemies.y-20);
            break;
        case 7:
            render(enemies.type, enemies.x+60, enemies.y+35);
            break;
        case 8:
            render(enemies.type, enemies.x+20, enemies.y-13);
            break;
        case 9:
            render(enemies.type, enemies.x+12, enemies.y-10);
            break;
        case 10:
            render(enemies.type, enemies.x+60, enemies.y-60);
            break;
        case 11:
            render(enemies.type, enemies.x+70, enemies.y-40);
            break;
        case 12:
            render(enemies.type, enemies.x+80, enemies.y);
            break;
        case 13:
            render(enemies.type, enemies.x+90, enemies.y-50);
            break;
        case 14:
            render(enemies.type, enemies.x+75, enemies.y-13);
            break;
        case 15:
            render(enemies.type, enemies.x+95, enemies.y-10);
            break;
        case 16:
            render(enemies.type, enemies.x+110, enemies.y-60);
            break;
        }
}

//Render the second enemie swarm with a switch statement based on random values
void generateRandomObst2(int randInt){
    switch (randInt){
         case 0:
            render(enemies.type, enemies2.x + 200, enemies2.y - 30);
            break;
        case 1:
            render(enemies.type, enemies2.x+100, enemies2.y);
            break;
        case 2:    
            render(enemies.type, enemies2.x+140, enemies2.y-25);
            break;
        case 3:    
            render(enemies.type, enemies2.x+115, enemies2.y-60);
            break;
        case 4:
            render(enemies.type, enemies2.x+130, enemies2.y-5);
            break;
        case 5:
            render(enemies.type, enemies2.x+150, enemies2.y-13);
            break;
        case 6:
            render(enemies.type, enemies2.x+135, enemies2.y-20);
            break;
        case 7:
            render(enemies.type, enemies2.x+160, enemies2.y-35);
            break;
        case 8:
            render(enemies.type, enemies2.x+120, enemies2.y-13);
            break;
        case 9:
            render(enemies.type, enemies2.x+112, enemies2.y-10);
            break;
        case 10:
            render(enemies.type, enemies2.x+160, enemies2.y-60);
            break;
        case 11:
            render(enemies.type, enemies2.x+170, enemies2.y-40);
            break;
        case 12:
            render(enemies.type, enemies2.x+180, enemies2.y);
            break;
        case 13:
            render(enemies.type, enemies2.x+190, enemies2.y-50);
            break;
        case 14:
            render(enemies.type, enemies2.x+175, enemies2.y-13);
            break;
        case 15:
            render(enemies.type, enemies2.x+195, enemies2.y-10);
            break;
        case 16:
            render(enemies.type, enemies2.x+210, enemies2.y-60);
            break;
        }
}

// Update all units on the screen
void unit_update() {
    // Reset timeout counter so it wont overflow
    if(timeCounter > 130) timeCounter = 0;
    // Updates the screen
    updatePlayer();
    updateEnemieControl();
    // Check collisions
    checkCollisions();
}
