#include <LiquidCrystal.h>

LiquidCrystal lcd(8,9,4,5,6,7);
void setup() {
  lcd.begin(16,2);
  lcd.clear();
  pinMode(10,OUTPUT);
  digitalWrite(10,HIGH);
  Serial1.begin(9600);
}

void loop() {
  int i;
  int data;
  
  if(Serial1.available()>=5){
    lcd.setCursor(0,0);
    for(i=0; i<5; i++) {
      data = Serial1.read();
      lcd.print(data);
    }
  }
}
