//By Jacob Wirgård Wiklund & Anton Danker
//Header file for game functions

#include <stdint.h>

// Display-related functions from displaySetup.c
void displayPixel(int, int);
void displayHex(int,int,int);
void display_init(void);
void display_update(void);
void displayString(int,int,char*);
void displayDigit(int,int,int);
void clearDisplay(void);
void sleep(int);
uint8_t dataArray[512];

// Functions from utils.c 
int getbtns(void);
int getbtn1(void);
int getsw(void);

// Functions from Main.c
void updatePlaying(void);
void updateMainMenu(void);
void updateGameOver(void);
extern int GAMESTATE;
extern int SCORE;

// Used for enemie positions
extern int randInt1;
extern int randInt2;
extern int randInt3;
extern int randInt4;
extern int randInt5;
extern int randInt6;
extern int randInt7;
extern int randInt8;

extern int rand2Int1;
extern int rand2Int2;
extern int rand2Int3;
extern int rand2Int4;
extern int rand2Int5;
extern int rand2Int6;
extern int rand2Int7;
extern int rand2Int8;


// Functions from gamePlaying.c
int getRandomInt(int);

// Functions from entityHandler.c
void unit_update(void);
void unit_render(void);
extern int timeCounter;
#define FLOOR_Y_UP 29
#define FLOOR_Y_DOWN 8

// Functions from gameHighScores.c
void evalueteScore(void);
extern int HIGH_SCORE_1;
extern int HIGH_SCORE_2;
extern int HIGH_SCORE_3;
