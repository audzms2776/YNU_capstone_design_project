#define trig 8 
#define echo 7
#include <math.h>

int AD = 12, BD = 13, AP=10, BP=11;
//  오른쪽    왼쪽     오른쪽  왼쪽

void setup() {
    pinMode(trig, OUTPUT);c
    pinMode(echo, INPUT);
    pinMode(AD, OUTPUT);
    pinMode(BD, OUTPUT);

    Serial.begin(9600);
}

void loop() {
  float dis = ultrasonic();
  float calc = 0;
  
  if(dis == 0) {
    motor(0);
  } else if(dis > 20) {
    calc = 30 * log(dis - 20) + 80;
  } else {
    calc = -1 * 30 * log(20 - dis) - 80;
  }

  constrain(calc, -255, 255);
  motor(calc);

  delay(15);
}

float ultrasonic(){
    digitalWrite(trig, HIGH); delay(2);
    digitalWrite(trig, LOW);

    float distance = pulseIn(echo, HIGH) / 59;

    return distance;
}

void motor(int vel) {
    if(vel < 0) {
        digitalWrite(12, LOW);
    } else {
        digitalWrite(12, HIGH);
    }

    if(vel < 0) {
        digitalWrite(13, LOW);
    } else {
        digitalWrite(13, HIGH);
    }

    analogWrite(10, abs(vel));
    analogWrite(11, abs(vel));
}
