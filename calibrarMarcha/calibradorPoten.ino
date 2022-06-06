#include <Servo.h>

Servo myServo;

int um=47;
int dois=57;
int tres=68;
int quatro=84;
int cinco=97;
int seis=110;
int sete=130;
int oito=153;

void setup()
{
  Serial.begin(9600);
  myServo.attach(2);
}

void loop()
{
  // int angle = analogRead(0);
  // angle = map(angle, 0, 1023, 0, 180);
  // myServo.write(angle);
  // Serial.println(angle, DEC);
  // delay(15);

  myServo.write(oito); //MARCHA 8
  delay(2000);
  myServo.write(sete); //MARCHA 7
  delay(2000);
  myServo.write(seis); //MARCHA 6
  delay(2000);
  myServo.write(cinco); //MARCHA 5
  delay(2000);
  myServo.write(quatro); //MARCHA 4
  delay(2000);
  myServo.write(tres); //MARCHA 3
  delay(2000);
  myServo.write(dois); //MARCHA 2
  delay(2000);
  myServo.write(um); //MARCHA 1
  delay(2000);

  myServo.write(dois); //MARCHA 2
  delay(2000);
  myServo.write(tres); //MARCHA 3
  delay(2000);
  myServo.write(quatro); //MARCHA 4
  delay(2000);
  myServo.write(cinco); //MARCHA 5
  delay(2000);
  myServo.write(seis); //MARCHA 6
  delay(2000);
  myServo.write(sete); //MARCHA 7
  delay(2000);
  myServo.write(oito); //MARCHA 8
  delay(2000);
}