int cnt = 30;
int vel = 0;
int vel0 = 0;


void setup() {
    pinMode(7, INPUT_PULLUP);
    pinMode(6, OUTPUT);
    
    pinMode(10, OUTPUT);            //모터
    pinMode(9,OUTPUT);            //모터
    
    pinMode(4,OUTPUT);            //리셋핀
    digitalWrite(4, LOW);
    
    pinMode(2, INPUT);
    
    digitalWrite(6, LOW);
    digitalWrite(9, LOW); // 모터 앞으로 

    Serial.begin(9600);
}

//
//
//// 반대로 바꾸면 급정지 방지 
//if(vel0 > vel +4) {
//  vel0 = vel + 4;
//}


void loop() {
  float dis = pulseIn(2, HIGH);
  dis = dis / 10;

  Serial.print("distance: ");
  Serial.print(dis);
  Serial.print(" ---- ");

  if(dis < 30) {
    vel = 0;
    Serial.print("Stop mode  ");
  } else {
    if(digitalRead(7) == LOW) {
      Serial.print("Cruise mode ");
      
      if(dis > 100) {
        blinkLED();
        Serial.print("mmmanual  ");
        vel = readPoten();        
      } 
      else {
        digitalWrite(6, HIGH);
        vel = (dis - 30) * 2;
        
        if(vel > vel0 + 2) {
          vel = vel0 + 2;
        }

        if(vel < vel - 2) {
          vel = vel0 - 2;
        }

        vel = constrain(vel, -255, 255);
      }
    } 
    else {
      digitalWrite(6, LOW);
      Serial.print("Manual mode  ");
      vel = readPoten();
   }
  }

  Serial.println(vel);
  analogWrite(10, vel);
  delay(25);
  vel0 = vel;
}

int readPoten() {
  int value = analogRead(A0);
  value = constrain(value / 4, -255, 255);

  return value;
}

void blinkLED() {
  if(cnt == 0) {
    cnt = 30;
  } 

  cnt--;
  digitalWrite(6, cnt < 15);   
}

