//By Jacob Wirgård Wiklund & Anton Danker
//Highscore screen that shows top 3 score

#include <stdint.h>
#include <pic32mx.h>
#include "gameHeader.h"

int HIGH_SCORE_1 = 0;
int HIGH_SCORE_2 = 0;
int HIGH_SCORE_3 = 0;

// Evaluate whether score is new top 3 high score
void evalueteScore(void){ 
    if(SCORE > HIGH_SCORE_1 && SCORE > HIGH_SCORE_2 && SCORE > HIGH_SCORE_3){ 
        HIGH_SCORE_3 = HIGH_SCORE_2;
        HIGH_SCORE_2 = HIGH_SCORE_1;
        HIGH_SCORE_1 = SCORE;
        } else if(SCORE > HIGH_SCORE_2 && SCORE > HIGH_SCORE_3){
        HIGH_SCORE_3 = HIGH_SCORE_2;
        HIGH_SCORE_2 = SCORE;
        } else if(SCORE > HIGH_SCORE_3) HIGH_SCORE_3 = SCORE;    
}

// Display content of the high score screen
void highScoresScreen(){
    // Display high scores
    displayString(30, 0, "High Scores");
	displayString(40, 1, "1: ");
    displayDigit(55, 1, HIGH_SCORE_1);
    displayString(40, 2, "2: ");
    displayDigit(55, 2, HIGH_SCORE_2);
    displayString(40, 3, "3: ");
    displayDigit(55, 3, HIGH_SCORE_3);
}

// Update the high score screen
void updateHighScores(){
    highScoresScreen();
    display_update();
    if(getbtn1() == 0){
        GAMESTATE = 1;
    }
}
