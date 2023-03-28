#include <Arduino.h>
//We always have to include the library
#include "LedControl.h"


/*
 Now we need a LedControl to work with.
 ***** These pin numbers will probably not work with your hardware *****
 pin 12 is connected to the DataIn 
 pin 11 is connected to the CLK 
 pin 10 is connected to LOAD 
 We have only a single MAX72XX.
 */


int DIN = 5 ;
int CLK = 4;
int LOAD = 3;

LedControl lc=LedControl(DIN,CLK,LOAD,1);

/* we always wait a bit between updates of the display */
unsigned long delaytime=1000;

void setup() {
  /*
   The MAX72XX is in power-saving mode on startup,
   we have to do a wakeup call
   */
  lc.shutdown(0,false);
  /* Set the brightness to a medium values */
  lc.setIntensity(0,5);
  /* and clear the display */
  lc.clearDisplay(0);
}


void test_all_the_segments(){
  for(int i=0; i<10 ; i++){
    char c = String(i).c_str()[0];
    for(int j=0 ; j<8; j++ )
    lc.setChar(0, j, c , false) ;

    delay(2000);
  }
}

void loop() { 
 test_all_the_segments();
}
