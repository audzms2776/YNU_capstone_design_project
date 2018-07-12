#define trig 8 
#define echo 7

void setup() {
    pinMode(trig, OUTPUT);
    pinMode(echo, OUTPUT);
    pinMode(10, OUTPUT);

    Serial.begin(9600);
}

void loop() {

    digitalWrite(trig, HIGH); delay(2);
    digitalWrite(trig, LOW);

    float distance = pulseIn(echo, HIGH) / 59;
    Serial.println(distance);
    bool flag;

//    if(distance < 10) {
//        Serial.println("Warring");
//        flag = LOW;
//    } else if(distance <= 50) {
//        Serial.println("Middle");
//        flag = LOW;
//    } else if(distance <= 100) {
//        Serial.println("Long");
//        flag = LOW;
//    } else {
//        Serial.println("Very Long");
//        flag = HIGH;
//    }

//    digitalWrite(10, flag);
}

