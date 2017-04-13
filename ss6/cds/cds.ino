int flag = 1;

void setup() {
  Serial.begin(9600);
  pinMode(2, INPUT);
  pinMode(A0, INPUT);
}

void loop() {
  int i;
  int data;
  int sum;
  float voltage;
  if(digitalRead(2) == LOW) {
    if(flag) {
      flag = 0;
      sum = 0;
      for(i=0; i<5; i++) {
        data = analogRead(A0);
        sum += data;
        delay(100);
      }
      if(sum == 0)
        voltage = 0;
      else
        voltage = (float)sum/5/1024*3.3;
      Serial.print(voltage, 2);
      Serial.println("V");
    }
  }
  else {
    flag = 1;
  }
  

 
}
