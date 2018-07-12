void setup() {
    pinMode(6, OUTPUT);
    
    Serial.begin(9600);
}

void loop() {
    // 가변 저항 0 ~ 1024
    // led 0 ~ 255

    int value = analogRead(A0);
    
    float ledValue = value / 4.0;

    Serial.println(ledValue);

    analogWrite(6, ledValue);
}


