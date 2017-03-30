int arr[] = {8, 9, 10, 11};

void setup() {
  int i;
  for(i=0; i<4; i++) pinMode(arr[i], OUTPUT);
  for(i=0; i<4; i++) digitalWrite(arr[i], LOW); 
  digitalWrite(arr[0], HIGH);
}

void loop() {
  int i;
  for(i=0; i<4; i++) {
    digitalWrite(arr[(i+3)%4], LOW);
    delay(5);
    digitalWrite(arr[(i+1)%4], HIGH);
    delay(5);
  }

}
