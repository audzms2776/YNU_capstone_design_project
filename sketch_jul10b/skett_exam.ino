int AD = 12, BD = 13, AP=10, BP=11;

void setup() {
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);

  delay(1000);
}

void loop() {
    for(int i = -60; i > -255; --i) {
        motor(255, i);
        delay(5);
    }

    delay(2000);
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
