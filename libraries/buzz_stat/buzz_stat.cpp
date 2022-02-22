const int buzzer = 8; //buzzer to arduino pin 8

// Buzzer frequencies in Hz
const int B_FREQ = 1000;

// Buzzer durations in ms
const int DELAY = 2000; // Loop delay in ms
const int DOT_DUR = 250;
const int DASH_DUR = 500;


void setup(){
 
  pinMode(buzzer, OUTPUT); // Set buzzer - pin 9 as an output

}

void loop(){

  sos();
  delay(DELAY);
  
}

void shortBeep() {
  tone(buzzer, B_FREQ);
  delay(100);
  noTone(buzzer);
}

void longBeep() {
  tone(buzzer, B_FREQ);
  delay(500);
  noTone(buzzer);
}

void warningBeep() {
  tone(buzzer, B_FREQ);
  delay(100);
  noTone(buzzer);
  delay(100);
  tone(buzzer, B_FREQ);
  delay(100);
  noTone(buzzer);
  delay(100);
  tone(buzzer, B_FREQ);
  delay(100);
  noTone(buzzer);
}

void dot() {
  tone(buzzer, B_FREQ);
  delay(DOT_DUR);
  noTone(buzzer);
  delay(DOT_DUR);
}

void dash() {
  tone(buzzer, B_FREQ);
  delay(DASH_DUR);
  noTone(buzzer);
  delay(DOT_DUR);
}

void sos() {
  dot(); dot(); dot();
  delay(DOT_DUR);
  dash(); dash(); dash();
  delay(DOT_DUR);
  dot(); dot(); dot();
}
