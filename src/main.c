//BY Jacob Wirgård Wiklund & Anton Danker
//Main file that controls the game loop and init all the base values

#include <stdint.h>
#include <pic32mx.h>
#include <stdlib.h>
#include "gameHeader.h"

// Game state when the games start
int GAMESTATE = 1;
//init score
int SCORE = 0;

// The start of the game
int main(void) {
    // Code from lab -->
	/* Output pins for display signals */
    SYSKEY = 0xAA996655;  /* Unlock OSCCON, step 1 */
    SYSKEY = 0x556699AA;  /* Unlock OSCCON, step 2 */
    while(OSCCON & (1 << 21)); /* Wait until PBDIV ready */
    OSCCONCLR = 0x180000; /* clear PBDIV bit <0,1> */
    while(OSCCON & (1 << 21));  /* Wait until PBDIV ready */
    SYSKEY = 0x0;  /* Lock OSCCON */

    /* Set up output pins */
    AD1PCFG = 0xFFFF;
    ODCE = 0x0;
    TRISECLR = 0xFF;
    PORTE = 0x0;

	PORTF = 0xFFFF;
	PORTG = (1 << 9);
	ODCF = 0x0;
	ODCG = 0x0;
	TRISFCLR = 0x70;
	TRISGCLR = 0x200;

    /* Set up input pins */
	TRISDSET = (1 << 8);
	TRISFSET = (1 << 1);

	/* Set up SPI as master */
	SPI2CON = 0;
	SPI2BRG = 4;
	/* SPI2STAT bit SPIROV = 0; */
	SPI2STATCLR = 0x40;
	/* SPI2CON bit CKP = 1; */
    SPI2CONSET = 0x40;
	/* SPI2CON bit MSTEN = 1; */
	SPI2CONSET = 0x20;
	/* SPI2CON bit ON = 1; */
	SPI2CONSET = 0x8000;
    // <-- code from lab

    //Setup display
	display_init();
    // Init all units
    unit_init();
    // Main game loop
	while(1) {
        clearDisplay();
        if(GAMESTATE == 1) {
            updateMainMenu();
        } else if(GAMESTATE == 2) {
            updatePlaying();
        } else if(GAMESTATE == 3) {
            updateGameOver();
        } else if(GAMESTATE == 4) {
            updateHighScores();
        }
	}
	return 0;
}
