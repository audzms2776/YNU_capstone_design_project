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

    if( distance > 20) {
      Foward(255);
    } else {
      Backward(255);
    }
}

void Stop() {
    digitalWrite(AD, HIGH);
    digitalWrite(BD, HIGH);

    analogWrite(AP, 0);
    analogWrite(BP, 0);
}

void Foward(int vel) {
    digitalWrite(AD, HIGH);
    digitalWrite(BD, HIGH);

    analogWrite(AP, vel);
    analogWrite(BP, vel);
}

void Backward(int vel) {
    digitalWrite(AD, LOW);
    digitalWrite(BD, LOW);

    analogWrite(AP, vel);
    analogWrite(BP, vel);
}
