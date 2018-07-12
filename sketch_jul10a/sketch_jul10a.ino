int AD = 12, BD = 13, AP=10, BP=11;
//  오른쪽    왼쪽     오른쪽  왼쪽

void setup() {
  pinMode(AD, OUTPUT);
  pinMode(BD, OUTPUT);

  delay(1000);
}

void loop() {
  // 제자리 우회전 
  digitalWrite(AD, HIGH);
  digitalWrite(BD, LOW);

  analogWrite(AP, 255);
  analogWrite(BP, 255);

  delay(2000);

  // 큰 반경으로 우회전 
  digitalWrite(AD, HIGH);
  digitalWrite(BD, HIGH);

  analogWrite(AP, 255);
  analogWrite(BP, 20);

  delay(3000);

  digitalWrite(AD, HIGH);
  digitalWrite(BD, HIGH);

  analogWrite(AP, 20);
  analogWrite(BP, 255);

  delay(3000);

  digitalWrite(AD, LOW);
  digitalWrite(BD, HIGH);

  analogWrite(AP, 255);
  analogWrite(BP, 255);

  delay(2000);
}

void Forward(int vel){
  digitalWrite(AD, HIGH);
  digitalWrite(BD, HIGH);

  analogWrite(AP, vel);
  analogWrite(BP, vel);
}

void Backward(int vel){
  digitalWrite(BD, LOW);
  digitalWrite(AD, LOW);

  analogWrite(AP, vel);
  analogWrite(BP, vel);
}
