#include <PWM.h>

int32_t freq = 30000;
unsigned long  dis;
int cnt=0;
int vel;
int vel0;

void setup() {
  // put your setup code here, to run once:
  pinMode(6, OUTPUT);       // led
  digitalWrite(6, LOW);     // led 소등

  pinMode(7, INPUT_PULLUP);
  pinMode(8, OUTPUT);     //급제동핀
  pinMode(9, OUTPUT);     //속도제어
  pinMode(10, OUTPUT);    //방향- 직진
  pinMode(4, OUTPUT);     //레이져 리셋핀
  pinMode(2, INPUT);      //레이져 에코핀

  InitTimersSafe();
  SetPinFrequencySafe(9, freq);

  digitalWrite(8, LOW);   //급제동x
  digitalWrite(10, LOW);   //직진

  // 레이저
  digitalWrite(4, LOW);
  Serial.begin(250000);
}

void loop() {
  // put your main code here, to run repeatedly:
  dis = pulseIn(2, HIGH);      //레이져
  dis = dis / 10;

  Serial.print("distance: ");
  Serial.print(dis);
  Serial.print(" ---- ");

  if( dis <= 2) {
    dis = 10000;
  }


  if (digitalRead(7) == LOW)//눌렀을때 
  {
      Serial.print("Cruise mode ");
      //digitalWrite(6, 1);            //led on
       
      if (dis > 200 )        //메뉴얼모드
      {                    
          cnt=cnt+1;
          if(cnt>30)
          {
             cnt=0;
             digitalWrite(6,!digitalRead(6));   //led 깜빡
          }

          Serial.print("mmmanual  ");
          vel = readAccel();
       } else {                            //크루즈 모드
        
        digitalWrite(6, 1);
        vel = (dis - 100) * 10;
        vel = constrain(vel, 0, 255);
    }
  }
  else {                            //메뉴얼 모드
    //digitalWrite(6, LOW);
    Serial.print("maunal mode  ");
    vel = readAccel();
    
   }
 
  if (vel > vel0 ) {
    vel = vel0 + 3;               // 속도 스무스하게 증가
  }

  Serial.println(vel);
  pwmWrite(9, vel);               //속도제어
  delay(10);                   // 딜레이 줄이면 루프 속도 빨라짐
  vel0 = vel;
}

int readAccel   () {
  int accelValue = analogRead(A0);
  int vvv = constrain((accelValue - 185) * 0.4, 0, 255);   
 
  return vvv;
}

