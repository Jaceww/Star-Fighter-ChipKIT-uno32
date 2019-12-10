// By Jacob wirgård wiklund & Anton Danker
// The Game Over screen

#include <stdint.h>
#include "gameHeader.h"

int timer = 0;

//Drawing the game over screen
void gameOverScreen(int val, int size) {
	/* Display strings */
	displayString(32, 1, "Game Over");
	displayString(36, 2, "Score: ");
	displayDigit(78, 2, SCORE);
}

//Update the game over screen
void updateGameOver() {
	timer++;
	//Draw the screen
    gameOverScreen(0,512);
    display_update();

	//Switch to the main menu
	if(timer > 1200){
		GAMESTATE = 1;
		SCORE = 0;
		timer = 0;
	}
}
