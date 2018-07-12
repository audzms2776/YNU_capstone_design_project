#include <PWM.h>

int32_t freq = 30000;
unsigned long  distance;

void setup() {
  // put your setup code here, to run once:
  pinMode(8, OUTPUT);     //급제동핀
  pinMode(9, OUTPUT);     //direction
  pinMode(10, OUTPUT);    //속도제어

  
  InitTimersSafe();
  SetPinFrequencySafe(9, freq);

  digitalWrite(8, LOW);   //급제동x
  digitalWrite(10, LOW);   //직진

  Serial.begin(250000);
}

void loop() {
  // put your main code here, to run repeatedly:

  int value = analogRead(A0);

  Serial.print(value);
  Serial.print("    ");
  
  int vel = constrain((value - 185) * 0.4, 0, 255);   

  pwmWrite(9, vel);               //속도제어

  Serial.print("vel: ");
  Serial.println(vel);
}

//180 ~ 867 -185 
//-5  ~ 682 * 0.4
//-20 ~ 272.8
//  0 ~ 255
