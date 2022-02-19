
#include "buzz_stat.h"

const int BUZZ_PIN = 4;

void setup() {
  configureBuzzer(BUZZ_PIN);
}

void loop() {
  womp();
  delay(2000);
//  shortBeep(3);
//  delay(2000);
//  medBeep(3);
//  delay(2000);
//  longBeep(3);
//  delay(2000);
//  lowBeep(3);
//  delay(2000);
}
