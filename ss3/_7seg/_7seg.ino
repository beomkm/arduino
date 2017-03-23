#include <math.h>

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
int selPins[] = {10, 11, 12, 13};
int count = 0;
                    
void setup() {
  int i;
  for(i=0; i<8; i++) pinMode(segPins[i], OUTPUT);
  for(i=0; i<4; i++) pinMode(selPins[i], OUTPUT);
  for(i=0; i<8; i++) digitalWrite(segPins[i], LOW);
  for(i=0; i<4; i++) digitalWrite(selPins[i], HIGH);
}

void loop() {
  
  int i, j;
  int digit;

  for(i=0; i<4; i++) {
    //set
    digitalWrite(selPins[i], LOW);

    digit = (int)(count/pow(10, i)) % 10;
    for(j=0; j<7; j++) {
      digitalWrite(segPins[j], seg[digit][j]);
    }

    //dot
    if(i==2) digitalWrite(segPins[7], HIGH);
    else digitalWrite(segPins[7], LOW);

    //delay 2.5ms
    delayMicroseconds(2500);
    
    //clear
    for(j=0; j<8; j++) digitalWrite(segPins[j], LOW);

    //release
    digitalWrite(selPins[i], HIGH);
  }
  
  count += 1;
  //00.00s ~ 59.99s
  if(count > 5999) {
    count = 0;
  }

}
