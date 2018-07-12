# YNU_capstone_design_project

## arduino cruise controll system 

* cruise1: 
``` C
    if( distance > 20) {
      Foward(255);
    } else {
      Backward(255);
    }
```
* cruise2: 
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
* 
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
* cruise6: 