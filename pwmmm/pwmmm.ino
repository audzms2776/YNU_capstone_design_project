#include <PWM.h>

int32_t freq = 30000;

void setup() {
  // put your setup code here, to run once:

  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  
  InitTimersSafe();
  SetPinFrequencySafe(10, freq);

  digitalWrite(9, LOW);
  pwmWrite(10, 200); // analogWrite 대신에 사용 

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  
}
