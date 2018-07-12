void setup() {
  // put your setup code here, to run once:
  pinMode(7, INPUT_PULLUP);
  pinMode(6, OUTPUT);

  digitalWrite(6, 1);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  if(digitalRead(7) == 1) {
    digitalWrite(6, 0);
    //delay(500);
  } else {
    digitalWrite(6, 1);
    //delay(500);
  }

  //  digitalWrite(6, !digitalRead(7));
}
