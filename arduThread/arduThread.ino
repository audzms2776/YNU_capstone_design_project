int cnt = 100;

void setup() {
  // put your setup code here, to run once:
    pinMode(10, OUTPUT);
    Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  blinkLED();

}


void blinkLED() {
  if(cnt == 0) {
    cnt = 100;
  } 

  cnt--;
  digitalWrite(10, cnt < 50);   
}
