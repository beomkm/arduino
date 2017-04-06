int flag = 1;
int value = 0;

void setup() {
  Serial.begin(9600);
  Serial1.begin(9600);
  pinMode(2, INPUT);
}

void loop() {
  int i;
  if(digitalRead(2) == LOW) {
    if(flag) {
      for(i=0; i<5; i++) {
        Serial1.write(value+i);
      }
      value += 5;
      if(value > 254) {
        value = 0;
      }
    }
    flag = 0;
  }
  else {
    flag = 1;
  }
}
