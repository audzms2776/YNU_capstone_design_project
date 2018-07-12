# YNU_capstone_design_project

## arduino cruise controll system 

* cruise1
``` C
if( distance > 20) {
    Foward(255);
} else {
    Backward(255);
}
```
* cruise2 
``` C
if(distance > 40) {
    Foward(255);
} else if(distance > 20) {
    Foward(50);
} else if(distance == 20) {
    Stop();
} else if(distance > 10) {
    Backward(50);
} else {
    Backward(255);
}
```
* cruise3
``` C
float dd = (distance - 20) * 80;

if (dd > 255) {
    dd = 255;
} else if (dd < -255) {
    dd = -255;
}

motor(dd, dd);
```
* cruise4
``` C 
float dis = ultrasonic();
float calc = 0;

if(dis == 0) {
    motor(0);
} else if(dis > 20) {
    calc = 30 * log(dis - 20) + 80;
} else {
    calc = -1 * 30 * log(20 - dis) - 80;
}

constrain(calc, -255, 255);
motor(calc);
```
* cruise5
``` C
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
``` 

* cruise6
``` C
if(vel > vel0 + 2) {
    vel = vel0 + 2;
}

if(vel < vel - 2) {
    vel = vel0 - 2;
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
```