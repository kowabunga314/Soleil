#include "buzz_stat.h"

const int BUZZ_PIN = 8;

void setup(){
  configureBuzzer(BUZZ_PIN);
}

void loop(){

  warningBeep();
  delay(2000);
  
}
