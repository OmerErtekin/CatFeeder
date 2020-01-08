#define S0 8
#define S1 9
#define S2 10
#define S3 11
#define OUT 7
#include <Servo.h>

Servo motor;


void setup(){
  pinMode(S0,OUTPUT);
  pinMode(S1,OUTPUT);
  pinMode(S2,OUTPUT);
  pinMode(S3,OUTPUT);
  pinMode(OUT,INPUT);
  motor.attach(6);
  digitalWrite(S0,HIGH);
  digitalWrite(S1,LOW);
  Serial.begin(9600);
  
}

void loop(){
  int kirmizi,mavi,yesil=0;
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
  kirmizi=pulseIn(OUT,LOW);
  Serial.print("Kırmızı=");
  Serial.print(kirmizi);
  delay(1000);
  
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  yesil=pulseIn(OUT,LOW);
  Serial.print(" Yeşil=");
  Serial.print(yesil);
  delay(1000);

  digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);
  mavi=pulseIn(OUT,LOW);
  Serial.print(" Mavi=");
  Serial.println(mavi);
  delay(1000);

  if((yesil<mavi) && (yesil < kirmizi) && (mavi-yesil>30) && (kirmizi-yesil>30)){
    motor.write(0);
    delay(1000);
    motor.write(90);
  }
  
  
}
