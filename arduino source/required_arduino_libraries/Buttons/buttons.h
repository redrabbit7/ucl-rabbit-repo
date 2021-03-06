/*
 *  buttons.h
 *  One-shot and hold functions for buttons.
 *  Created by Franky on 29/01/09.
 *  Licensed under LGPL (free to modify and use as you wish)
 *  Modified by Patrick Oladimeji on 9/02/2012 for use with both analog and digital connections
 */

#include <inttypes.h>

#define OneShot 0
#define Memory 1
#define Timer 2
#define OneShotTimer 3
#define MemoryTimer 4

#define ON 1
#define OFF 0
#define Pressed 2
#define Released 3
#define Hold 4

#define ANALOG 1
#define DIGITAL 2

typedef uint8_t byte;


class Button {
public:
	Button();
	Button(byte type);
	void assign(byte pin, byte pin_mode);
	byte check();
	byte check(byte mode_v);
	// Setters
	void setMode(byte type_v);
	void setTimer(unsigned int t);
	void setRefresh(unsigned int r);
	void turnOnPullUp();
	void turnOffPullUp();
    /**
     sets the connection to digital or analog
     */
    void setPinMode(byte c);
	
	
private:	
	byte pin;
	byte mode;
	unsigned long hold_timer;
	unsigned long refresh_timer;
	unsigned int hold_level;
	unsigned int hold_refresh;
	bool previous;
    byte pin_mode;
};



/*
 
 Button modes:
 
 - OneShot: OneShot only, returns 2 values (ON/OFF)
 - Memory: Returns (Pressed/ON/Released/OFF)
 - Timer: Hold System (OFF/ON/Hold)
 - OneShotTimer: Combi OneShot & Timer (ON/Hold/OFF)
 - MemoryTimer: Combi Memory & Timer 
 (Pressed/ON/Hold/Released/OFF)
 
 */