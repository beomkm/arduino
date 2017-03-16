int cnt = 0;
int t = 0;
int level = 10;

void setup() {
  pinMode(3, INPUT);
  pinMode(7, OUTPUT);
}

void loop() {
  analogWrite(7, 255*t/level);
  delay(10);
  cnt = (cnt+1) % 10;
  if(cnt == 0) {
    if(digitalRead(3) == LOW) {
      if(t<10) t++;
    }
    else {
      if(t>0) t--;
    }
  }
}
