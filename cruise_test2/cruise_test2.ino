#include <PWM.h>

int32_t freq = 30000;
unsigned long  dis;

int vel;
int vel0;

void setup() {
  // put your setup code here, to run once:
  pinMode(6, OUTPUT);       // led
  digitalWrite(6, LOW);     // led 소등

  pinMode(8, OUTPUT);     //급제동핀
  pinMode(9, OUTPUT);     //속도제어
  pinMode(10, OUTPUT);    //방향- 직진
  pinMode(4, OUTPUT);     //레이져 리셋핀
  pinMode(2, INPUT);      //레이져 에코핀

  InitTimersSafe();
  SetPinFrequencySafe(9, freq);

  digitalWrite(8, LOW);   //급제동x
  digitalWrite(10, LOW);   //직진

  // 레이저
  digitalWrite(4, LOW);
  Serial.begin(250000);
}

void loop() {
  // put your main code here, to run repeatedly:
  dis = pulseIn(2, HIGH);      //레이져
  dis = dis / 10;

  if(dis < 2) {
    dis = 10000;
  }

  Serial.print("distance: ");
  Serial.print(dis);
  Serial.print(" ---- ");

  vel = (dis - 100) * 10 + 30;
  vel = constrain(vel, 0, 255);

  if (vel > vel0 ) {
    vel = vel0 + 3;               // 스무스 증가
  }

  if(vel < vel0) {   // 스무스 감속
    vel = vel0 - 5;
  }

  Serial.println(vel);
  pwmWrite(9, vel);
  delay(10);         
  vel0 = vel;
}

