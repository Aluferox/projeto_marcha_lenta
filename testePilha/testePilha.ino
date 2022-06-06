#include <Servo.h>

Servo myServo;
int cont = 0;

void setup()
{
  myServo.attach(7);
  Serial.begin(9600);
}

void loop()
{
  myServo.write(0);
  delay(500);
  cont += 1;
  myServo.write(45);
  delay(500);
  cont += 1;
  myServo.write(90);
  delay(500);
  cont += 1;
  myServo.write(135);
  delay(500);
  cont += 1;
  myServo.write(180);
  delay(500);
  cont += 1;
  Serial.println(cont);
}