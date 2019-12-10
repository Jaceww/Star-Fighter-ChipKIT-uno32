//By Jacob Wirgård Wiklund & Anton Danker
//Gets the input from the buttons

#include <stdint.h>
#include <pic32mx.h>
#include "gameHeader.h"

// Get input from switches
int getsw(void) {
    return (PORTD & 0xF00) >> 8;
}

// Get input from buttons
int getbtns(void) {
    return PORTD >> 5 & 0x7;
}

// Get input from first button
int getbtn1(void){
    return PORTF & 0x2;
}
