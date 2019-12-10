// By Jacob Wirgård Wiklund & Anton danker
//The Main Menu screen

#include <stdint.h>
#include "gameHeader.h"
#include "units.h"

//Rendering the menu screen
void mainMenuScreen() {
    int X = 36;

    //Render upper and lower line
    int i;
    for (i = 0; i<512; i++) {
		if(i<128) {
			// Draw upper line
			dataArray[i] = 0x1;
		} else if(i>384) {
			// Draw lower line
			dataArray[i] = 0x80;
		} else {
			// Zero the array
			dataArray[i] = 0x0;
		}
    }
    // Printing title
    displayString(X + 7,1,"STAR");
    displayString(X + 7,2,"FIGHTER");
}

void animation() {
    // Duration counter
    int counter = 0;

    // Initilise a new player
    player.type = PLAYER;
    player.x = -2;
    player.y = 8;

    // Animation loop
    while (counter < 1500) {
        if(counter % 10 == 0) {
            player.x += 1;
            updatePlayer();
        }
        mainMenuScreen();
        
        //render the player
        render(player.type,player.x,player.y);
        display_update();
        counter++;
    }
    //Generate start position of the first enemy swarm
    randInt1 = getRandomInt(16);
    randInt2 = getRandomInt(16);
    randInt3 = getRandomInt(16);
    randInt4 = getRandomInt(16);
    randInt5 = getRandomInt(16);
    randInt6 = getRandomInt(16);
    randInt7 = getRandomInt(16);
    randInt8 = getRandomInt(16);

    //Generate start position of the secound enemy swarm
    rand2Int1 = getRandomInt(16);
    rand2Int2 = getRandomInt(16);
    rand2Int3 = getRandomInt(16);
    rand2Int4 = getRandomInt(16);
    rand2Int5 = getRandomInt(16);
    rand2Int6 = getRandomInt(16);
    rand2Int7 = getRandomInt(16);
    rand2Int8 = getRandomInt(16);
}


//Main menu update
void updateMainMenu() {
    // Draw main menu screen
    mainMenuScreen();
    // Update screen
    display_update();
    // Get buttons
    int buttons = getbtns();
    // The to the right is pressed to enter the high score screen
    if(getbtn1()) {
        clearDisplay();
        GAMESTATE = 4;
    //else if the other buttons is pressed then start the game
    } else if(buttons != 0){
        animation();
        GAMESTATE = 2;
    }
}
