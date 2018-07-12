unsigned long dis;

void setup() {
    pinMode(7, INPUT_PULLUP);
    pinMode(6, OUTPUT);

    pinMode(4, OUTPUT);
    digitalWrite(4, LOW);

    digitalWrite(6, 1);

    Serial.begin(9600);
    
    pinMode(2, INPUT);
}

void loop() {
    if(digitalRead(7) == 0) {
        digitalWrite(6, 1);

        constrain(calc, -255, 255);
        motor(calc);
    } else {
        digitalWrite(6, 0);

        int value = analogRead(A0);
        float ledValue = value / 4.0;

        motor(ledValue);
    }
}

