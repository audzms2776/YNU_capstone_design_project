#define AD 9      //후진
#define BD 10      //전진
#define AP 10
#define BP 11

int v;
int limt=30;
float distance;

void setup() {
  // put your setup code here, to run once:
  pinMode(7, INPUT_PULLUP);       //스위치
  pinMode(6, OUTPUT);            // led

  digitalWrite(6, 1);
  pinMode(4,OUTPUT);            //리셋핀
  digitalWrite(4,0);
  pinMode(2,INPUT);               //에코핀
  
  pinMode(AD,OUTPUT);            //모터
  pinMode(BD,OUTPUT);            //모터
  delay(10);
  
  Serial.begin(9600);
}

//9번핀, 10번핀

//스위치 눌리면 led on, 크루즈 모드

void loop() {
  // put your main code here, to run repeatedly:
  
  distance=pulseIn(2,HIGH);
  distance=distance/10;
  Serial.println(distance);
  
  if(digitalRead(7) == 0) {         
    digitalWrite(6, 1);            
   
   if(distance>limt) {motor(constrain((distance-limt)*20+60,-255,255));}      //거리 30이상 일 때
   else if(distance<limt){motor( constrain((distance-limt)*20-60,-255,255));}
   else {motor(constrain(0,-255,255));}
   
   delay(10);
     
  } else {                     
    digitalWrite(6, 0);
   digitalWrite(6, 0);            
   
   int value = analogRead(A0);
    float ledValue = value / 4.0;
   Serial.println(ledValue);
    analogWrite(6, ledValue);
  }

  
}

void motor(int vel)
{
  if (vel<0){digitalWrite(AD,0);analogWrite(AP,abs(vel));}
  else  { digitalWrite(AD,1);analogWrite(AP,abs(vel));}
 
  if (vel<0){digitalWrite(BD,0);analogWrite(BP,abs(vel));} 
  else  { digitalWrite(BD,1);analogWrite(BP,abs(vel));}
  
}
