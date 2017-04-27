int pins[] = {2,3,4,5,6,7,8,9};

int current = 0;
int dir = 1;

void setup() {
  int i;
  for(i=0; i<8; i++) pinMode(pins[i], OUTPUT);
  for(i=0; i<8; i++) digitalWrite(pins[i], LOW);
  digitalWrite(pins[current], HIGH);
  attachInterrupt(2, h1, FALLING);

}

void loop() {
  digitalWrite(pins[current], LOW);
  current = (current+dir+8)%8;
  digitalWrite(pins[current], HIGH);
  delay(100);
}

void h1() {
  dir = -dir;
}

