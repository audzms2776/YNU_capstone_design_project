int AD = 12, BD = 13, AP=10, BP=11;
//  오른쪽    왼쪽     오른쪽  왼쪽

void setup() {
  pinMode(AD, OUTPUT);
  pinMode(BD, OUTPUT);

  delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:

// 큰 반경으로 우회전 
  digitalWrite(AD, HIGH);
  digitalWrite(BD, HIGH);

  int cnt = 20;
  
  while(1) {
    analogWrite(AP, 255);
    analogWrite(BP, 120 - cnt);

    if(cnt < 355) {
      cnt += 20;
    }
    
    delay(100);
  }
}
