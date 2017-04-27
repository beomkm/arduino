int seg[][8] = {{1, 1, 1, 1, 1, 1, 0, 0}, //0
                {0, 1, 1, 0, 0, 0, 0, 0}, //1
                {1, 1, 0, 1, 1, 0, 1, 0}, //2
                {1, 1, 1, 1, 0, 0, 1, 0}, //3
                {0, 1, 1, 0, 0, 1, 1, 0}, //4
                {1, 0, 1, 1, 0, 1, 1, 0}, //5
                {1, 0, 1, 1, 1, 1, 1, 0}, //6
                {1, 1, 1, 0, 0, 0, 0, 0}, //7
                {1, 1, 1, 1, 1, 1, 1, 0}, //8
                {1, 1, 1, 1, 0, 1, 1, 0}}; //9
int segPins[] = {2, 3, 4, 5, 6, 7, 8, 9};
int selPins[] = {12, 13};
int count = 0;
int digit[2];

void setup() {
  int i;
  for(i=0; i<8; i++) pinMode(segPins[i], OUTPUT);
  for(i=0; i<2; i++) pinMode(selPins[i], OUTPUT);
  for(i=0; i<8; i++) digitalWrite(segPins[i], LOW);
  for(i=0; i<2; i++) digitalWrite(selPins[i], HIGH);
  attachInterrupt(2, h1, FALLING);

}

void loop() {
  int i, j;

  digit[0] = count%10;
  digit[1] = count/10;

  for(i=0; i<2; i++) {
    digitalWrite(selPins[i], LOW);
    for(j=0; j<8; j++) {
      digitalWrite(segPins[j], seg[digit[i]][j]);
    }
    delay(5);
    digitalWrite(selPins[i], HIGH);
  }
  
 
}

void h1() {
  count = (count+1)%100;
}

