#include "Servo.h"

Servo myServo;

int um;
int dois;
int tres;
int quatro;
int cinco;
int seis;
int sete;
int oito;

void setup()
{
  Serial.begin(9600);
  myServo.attach(2);
}

void loop()
{
  int angle = analogRead(0);
  angle = map(angle, 0, 1023, 0, 180);
  myServo.write(angle);
  Serial.println(angle, DEC);
  delay(15);

  // myServo.write(oito); //MARCHA 8
  // delay(2000);
  // myServo.write(sete); //MARCHA 7
  // delay(2000);
  // myServo.write(seis); //MARCHA 6
  // delay(2000);
  // myServo.write(cinco); //MARCHA 5
  // delay(2000);
  // myServo.write(quatro); //MARCHA 4
  // delay(2000);
  // myServo.write(tres); //MARCHA 3
  // delay(2000);
  // myServo.write(dois); //MARCHA 2
  // delay(2000);
  // myServo.write(um); //MARCHA 1
  // delay(2000);

  // myServo.write(dois); //MARCHA 2
  // delay(2000);
  // myServo.write(tres); //MARCHA 3
  // delay(2000);
  // myServo.write(quatro); //MARCHA 4
  // delay(2000);
  // myServo.write(cinco); //MARCHA 5
  // delay(2000);
  // myServo.write(seis); //MARCHA 6
  // delay(2000);
  // myServo.write(sete); //MARCHA 7
  // delay(2000);
  // myServo.write(oito); //MARCHA 8
  // delay(2000);
}