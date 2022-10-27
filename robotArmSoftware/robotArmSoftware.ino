//Developed by Batuhan Huseyin KARA

#include <Servo.h>
Servo kepce;
Servo tabla;
Servo yukseklik;
Servo dogrultu;


int joy1x=A0;
int joy1y=A1;

int joy2x=A2;
int joy2y=A3;

int joy1xvalue;
int joy1yvalue;

int joy2xvalue;
int joy2yvalue;

int tablaServoposition=90;
int yukseklikServoposition=90;
int dogrultuServoposition=90;
int kepceServoposition=90;

void setup() {
  pinMode(joy1x,INPUT);
  pinMode(joy1y,INPUT);
  pinMode(joy2x,INPUT);
  pinMode(joy2y,INPUT);
  Serial.begin(9600);
  kepce.attach(3);
  tabla.attach(6);
  yukseklik.attach(5);
  dogrultu.attach(9);

}

void loop() {
  joy1xvalue=analogRead(joy1x);
  joy1yvalue=analogRead(joy1y);

  
  joy2xvalue=analogRead(joy2x);
  joy2yvalue=analogRead(joy2y);


  if(joy1xvalue<300){
    dogrultuServoposition=dogrultuServoposition+1;
    delay(25);
  }

  if(joy1xvalue>800){
    dogrultuServoposition=dogrultuServoposition-1;
    delay(25);
  }

  if(joy1yvalue<300){
    kepceServoposition=kepceServoposition-1;
    delay(25);
  }

  if(joy1yvalue>800){
    kepceServoposition=kepceServoposition+1;
    delay(25);
  }

  if(joy2xvalue<300){
    yukseklikServoposition=yukseklikServoposition-1;
    delay(25);
  }

  if(joy2xvalue>800){
    yukseklikServoposition=yukseklikServoposition+1;
    delay(25);
  }

  if(joy2yvalue<300){
    tablaServoposition=tablaServoposition-1;
    delay(25);
  }

  if(joy2yvalue>800){
    tablaServoposition=tablaServoposition+1;
    delay(25);
  }

  if(tablaServoposition<1){
    tablaServoposition=1;
  }
  if(tablaServoposition>179){
    tablaServoposition=179;
  }

  if(yukseklikServoposition<1){
    yukseklikServoposition=1;
  }
  if(yukseklikServoposition>179){
    yukseklikServoposition=179;
  }

  if(dogrultuServoposition<1){
    dogrultuServoposition=1;
  }
  if(dogrultuServoposition>179){
    dogrultuServoposition=179;
  }

  if(kepceServoposition<46){
    kepceServoposition=46;
  }
  if(kepceServoposition>179){
    kepceServoposition=179;
  }


  
  kepce.write(kepceServoposition);
  yukseklik.write(yukseklikServoposition);
  dogrultu.write(dogrultuServoposition);
  tabla.write(tablaServoposition);


}
