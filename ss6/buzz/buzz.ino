#include "pitches.h"

void setup() {
  Serial.begin(9600);
  pinMode(A0, INPUT);
}

void loop() {

  int data = analogRead(A0);
  if(data < 10) {
    tone(8, NOTE_C4);
    delay(200);
    noTone(8);
  }
 
}
