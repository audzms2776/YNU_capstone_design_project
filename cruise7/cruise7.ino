int velo=0;
int vel=0;         //초기값
int cnt=0;


void setup() {
  // put your setup code here, to run once:
  pinMode(7, INPUT_PULLUP);       //스위치
  pinMode(6, OUTPUT);            // led
  digitalWrite(6, 0);
  
  pinMode(4,OUTPUT);            //리셋핀
  digitalWrite(4,0);
  pinMode(2,INPUT);               //에코핀
  
  pinMode(9,OUTPUT);            //모터
  pinMode(10,OUTPUT);            //모터
  delay(10);
  
  Serial.begin(250000);
}


//스위치 눌리면 led on, 크루즈 모드

void loop() {
  
  
   float distance=pulseIn(2,HIGH);
   bool sw=digitalRead(7);   
   distance=distance/10;         
   Serial.print(distance);      //distance=초음파
   Serial.print(" - ");
  
   if(distance<100){ velo=0; Serial.println("stop");}           //거리가 100이하 정지
  
   else
   {
      if(sw == 0)                //스위치가 눌리면
      {   
         Serial.println("switch on");     //알림
         digitalWrite(6, 1);            //led on
        
         if(distance>=500)            //500이상이면
         {
            Serial.println("maual mode ");
            cnt=cnt+1;
            if(cnt>20)
            {
               cnt=0;
               digitalWrite(6,!digitalRead(6));   //led 깜빡
               velo=constrain ( analogRead(A0)/4,-255,255);   //메뉴얼모드
            }
         }
         else
         { 
           Serial.println("cruze ");
          velo=constrain( (distance-300)*2,-255,255);}
        
         if(velo>vel+4)velo=vel+4;      //직진   
        // if(velo<vel-4)velo=vel-4;      //후진
      }
    
   } 

   vel=velo;
   analogWrite(10,velo);
   delay(10);


}
