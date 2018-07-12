void setup() {
    pinMode(7, INPUT_PULLUP);
    pinMode(6, OUTPUT);
    
    pinMode(10, OUTPUT);            //모터
    pinMode(9,OUTPUT);            //모터
    
    pinMode(4,OUTPUT);            //리셋핀
    digitalWrite(4, LOW);
    
    pinMode(2, INPUT);
    
    digitalWrite(6, HIGH);
    digitalWrite(9, LOW); // 모터 앞으로 

    Serial.begin(9600);
}

void loop() {
    if(digitalRead(7) == LOW) {
        digitalWrite(6, HIGH);
        float dis = pulseIn(2, HIGH);
        dis = dis / 10;

        float calc = 0;

        if(dis < 10) {
          motor(0);
        } else if(dis == 0) {
            motor(0);
        } else if(dis > 150) {
            manualMode();
        } else if(dis > 20) {
            calc = 30 * log(dis - 20) + 80;
            constrain(calc, 0, 255);
            motor(calc);
        } else {
            calc = -1 * 30 * log(20 - dis) - 80;
            constrain(calc, 0, 255);
            motor(calc);
        }

        Serial.print(dis);
        Serial.print("   ");
        Serial.println(calc);
    } else {
      manualMode();
    }
}

void manualMode() {
    int value = analogRead(A0);
    int cc = constrain(value / 4, -255, 255);
    
    Serial.println(cc);
    motor(cc);
}

void motor(int vel) {
  if(vel > 0){
    digitalWrite(9,0);
    analogWrite(10, vel);
  } else {
    digitalWrite(9,0);
    analogWrite(10, 0);
  }
}
