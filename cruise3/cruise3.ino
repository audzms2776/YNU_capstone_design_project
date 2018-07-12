#define trig 8 
#define echo 7

int AD = 12, BD = 13, AP=10, BP=11;
//  오른쪽    왼쪽     오른쪽  왼쪽

void setup() {
    pinMode(trig, OUTPUT);
    pinMode(echo, INPUT);
    pinMode(AD, OUTPUT);
    pinMode(BD, OUTPUT);

    delay(1000);

    Serial.begin(9600);
}

void loop() {

    digitalWrite(trig, HIGH); delay(2);
    digitalWrite(trig, LOW);

    float distance = pulseIn(echo, HIGH) / 59;
    Serial.println(distance);

      float dd = (distance - 20) * 80;
      
      if (dd > 255) {
        dd = 255;
      } else if (dd < -255) {
        dd = -255;
      }

      motor(dd, dd);

      delay(10);
}


void motor(int vel1, int vel2) {
    if(vel1 < 0) {
        digitalWrite(12, LOW);
    } else {
        digitalWrite(12, HIGH);
    }

    if(vel2 < 0) {
        digitalWrite(13, LOW);
    } else {
        digitalWrite(13, HIGH);
    }

    analogWrite(10, abs(vel1));
    analogWrite(11, abs(vel2));
}

