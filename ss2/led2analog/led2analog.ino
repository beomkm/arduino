int t = 0;
int level = 10;
int sw0flag = 1;
int sw1flag = 1;

void setup() {
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(7, OUTPUT);
}

void loop() {
  analogWrite(7, 255*t/level);
  delay(10);
  
  if(digitalRead(3) == LOW) {
    if(sw0flag && t<10) t++;
    sw0flag = 0;
  }
  else {
    sw0flag = 1;
  }
  
  if(digitalRead(4) == LOW) {
    if(sw1flag && t>0) t--;
    sw1flag = 0;
  }
  else {
    sw1flag = 1;
  }
  
}
