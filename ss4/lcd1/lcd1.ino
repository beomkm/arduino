#include <LiquidCrystal.h>

LiquidCrystal lcd(8,9,4,5,6,7);
int len;

void setup() {
  lcd.begin(16, 2);
  lcd.clear();
  pinMode(10, OUTPUT);
  digitalWrite(10, HIGH);
  len = 1;
}

void loop() {
  int i;
  
  lcd.clear();
  lcd.setCursor(0, 0);
  for(i=0; i<len; i++) lcd.print("*");
  lcd.setCursor(0, 1);
  for(i=0; i<len%16+1; i++) lcd.print("*");

  ++len;
  if(len > 16) len = 1;
  
  delay(200);
}
