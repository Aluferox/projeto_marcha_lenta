#include <Servo.h>

// Objeto da classe Servo.h
Servo myServo;

//pino de Attach servo motor
int pinServo = 7;

// pino marcha down e up
int down = 2;
int up = 3;

//graus que de movimentação do servo motor
int march_one = 33;
int march_two = 50;
int march_three = 65;
int march_four = 80;
int march_five = 95;
int march_six = 107;
int march_seven = 125;
int march_eight = 155;

// quantidade de marchas
int march = 8;

void setup()
{
  Serial.begin(9600);
  pinMode(down, OUTPUT);
  pinMode(up, OUTPUT);

  myServo.attach(pinServo);
  myServo.write(march_eight);

}

void loop()
{
  if (digitalRead(up) == HIGH)
  {
    marchUP();
  };

  if (digitalRead(down) == HIGH)
  {
    marchDOWN();
  };

  Serial.print("March: ");
  Serial.println(march);
}

//Função para passar marcha para cima
void marchUP()
{
  march -= 1;
  if (digitalRead(up) == HIGH && march == 1)
  {
    myServo.write(march_one);
  };

  if (digitalRead(up) == HIGH && march == 2)
  {
    myServo.write(march_two);
  };

  if (digitalRead(up) == HIGH && march == 3)
  {
    myServo.write(march_three);
  };

  if (digitalRead(up) == HIGH && march == 4)
  {
    myServo.write(march_four);
  };

  if (digitalRead(up) == HIGH && march == 5)
  {
    myServo.write(march_five);
  };

  if (digitalRead(up) == HIGH && march == 6)
  {
    myServo.write(march_six);
  };

  if (digitalRead(up) == HIGH && march == 7)
  {
    myServo.write(march_seven);
  };

  if (march <= 1)
  {
    march = 1;
  };

  delay(300);
}

//Função para passar marcha para baixo
void marchDOWN()
{
  march += 1;
  if (digitalRead(down) == HIGH && march == 1)
  {
    myServo.write(march_seven);
  };

  if (digitalRead(down) == HIGH && march == 2)
  {
    myServo.write(march_two);
  };

  if (digitalRead(down) == HIGH && march == 3)
  {
    myServo.write(march_three);
  };

  if (digitalRead(down) == HIGH && march == 4)
  {
    myServo.write(march_four);
  };

  if (digitalRead(down) == HIGH && march == 5)
  {
    myServo.write(march_five);
  };

  if (digitalRead(down) == HIGH && march == 6)
  {
    myServo.write(march_six);
  };

  if (digitalRead(down) == HIGH && march == 7)
  {
    myServo.write(march_seven);
  };

  if (digitalRead(down) == HIGH && march == 8)
  {
    myServo.write(march_eight);
  };

  if (march >= 8)
  {
    march = 8;
  }
  delay(300);
}
