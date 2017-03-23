#include <math.h>

int led[][8] = {{1, 1, 1, 1, 1, 1, 1, 1}, 
                {1, 1, 1, 1, 1, 1, 1, 1}, 
                {1, 1, 1, 1, 1, 1, 1, 1}, 
                {1, 1, 1, 0, 0, 1, 1, 1}, 
                {1, 1, 0, 0, 0, 0, 1, 1}, 
                {1, 0, 0, 1, 1, 0, 0, 1}, 
                {0, 0, 1, 1, 1, 1, 0, 0}, 
                {0, 1, 1, 1, 1, 1, 1, 0}};
int rowPin[] = {2, 3, 4, 5, 6, 7, 8, 9};
int colPin[] = {14, 15, 16, 17, 18, 19, 20, 21};
int count = 0;
int dy = 0;
                    
void setup() {
  int i;
  for(i=0; i<8; i++) pinMode(rowPin[i], OUTPUT);
  for(i=0; i<8; i++) pinMode(colPin[i], OUTPUT);
  for(i=0; i<8; i++) digitalWrite(rowPin[i], LOW);
  for(i=0; i<8; i++) digitalWrite(colPin[i], HIGH);
}

void loop() {
    
  int i, j;
  for(i=0; i<8; i++) {
    digitalWrite(rowPin[i], HIGH);
    for(j=0; j<8; j++) {
      digitalWrite(colPin[j], led[(i+dy)%8][j]);
    }
    delayMicroseconds(1250);
    digitalWrite(rowPin[i], LOW);
  }

  count = (count+1) % 20;
  if(count == 0)
    dy = (dy+1) % 8;
}
