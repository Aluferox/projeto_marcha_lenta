#include <Servo.h>
#include <LedControl.h>

int down = 2;
int up = 3;
int alert = 4;
int right = 5;
int left = 6;
int pinServo = 7;
int march = 8;

const int DIN_PIN = 11;
const int CS_PIN = 10;
const int CLK_PIN = 13;

Servo myServo;
LedControl display = LedControl(DIN_PIN, CLK_PIN, CS_PIN);

void setup()
{
  Serial.begin(9600);
  pinMode(down, OUTPUT);
  pinMode(up, OUTPUT);
  pinMode(alert, OUTPUT);
  pinMode(right, OUTPUT);
  pinMode(left, OUTPUT);

  myServo.attach(pinServo);
  myServo.write(155);

  display.clearDisplay(0);
  display.shutdown(0, false);
  display.setIntensity(0, 15);
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

  if (digitalRead(alert) == HIGH)
  {
    attention();
  };

  if (digitalRead(right) == HIGH)
  {
    rightArrow();
  };

  if (digitalRead(left) == HIGH)
  {
    leftArrow();
  }

  Serial.print("March: ");
  Serial.println(march);
}

void marchUP()
{
  march -= 1;
  if (digitalRead(up) == HIGH && march == 1)
  {
    myServo.write(45);
  };

  if (digitalRead(up) == HIGH && march == 2)
  {
    myServo.write(61);
  };

  if (digitalRead(up) == HIGH && march == 3)
  {
    myServo.write(75);
  };

  if (digitalRead(up) == HIGH && march == 4)
  {
    myServo.write(88);
  };

  if (digitalRead(up) == HIGH && march == 5)
  {
    myServo.write(103);
  };

  if (digitalRead(up) == HIGH && march == 6)
  {
    myServo.write(117);
  };

  if (digitalRead(up) == HIGH && march == 7)
  {
    myServo.write(135);
  };

  if (march <= 1)
  {
    march = 1;
  };

  delay(300);
}

void marchDOWN()
{
  march += 1;
  if (digitalRead(down) == HIGH && march == 1)
  {
    myServo.write(45);
  };

  if (digitalRead(down) == HIGH && march == 2)
  {
    myServo.write(61);
  };

  if (digitalRead(down) == HIGH && march == 3)
  {
    myServo.write(75);
  };

  if (digitalRead(down) == HIGH && march == 4)
  {
    myServo.write(88);
  };

  if (digitalRead(down) == HIGH && march == 5)
  {
    myServo.write(103);
  };

  if (digitalRead(down) == HIGH && march == 6)
  {
    myServo.write(117);
  };

  if (digitalRead(down) == HIGH && march == 7)
  {
    myServo.write(135);
  };

  if (digitalRead(down) == HIGH && march == 8)
  {
    myServo.write(155);
  };

  if (march >= 8)
  {
    march = 8;
  }
  delay(300);
}

void attention(){
   int lenLedsAlert = 0;

  const uint64_t ALERT[] = {
  0xffffffffffffffff,
  0x0000000000000000
};
  const int IMAGES_LEN = sizeof(ALERT)/8;
 
  while (digitalRead(alert) == HIGH)
  {
    displayImage(ALERT[lenLedsAlert]);

    if (++lenLedsAlert >= IMAGES_LEN ) {
      lenLedsAlert = 0;
    }
    delay(100);
  }
  display.clearDisplay(0);
  
};

void rightArrow(){
  int lenLedsRigh = 0;
  const uint64_t  RIGHT[] = {
  0x3c3c3c3cff7e3c18,
  0x0000000000000000
};
const int IMAGES_LEN = sizeof(RIGHT)/8;
  while (digitalRead(right) == HIGH)
  {
     displayImage(RIGHT[lenLedsRigh]);
    if (++lenLedsRigh >= IMAGES_LEN ) {
      lenLedsRigh = 0;
    }
    delay(100);
  }
  display.clearDisplay(0);
};

void leftArrow(){
  int lenLedsLeft = 0;

  const uint64_t LEFT[] = {
    0x183c7eff3c3c3c3c,
    0x0000000000000000
    
  };
  const int IMAGES_LEN = sizeof(LEFT)/8;
  while (digitalRead(left) == HIGH)
  {
     displayImage(LEFT[lenLedsLeft]);
    if (++lenLedsLeft >= IMAGES_LEN ) {
      lenLedsLeft = 0;
    }
    delay(100);
  }
  display.clearDisplay(0);
};

void displayImage(uint64_t image) {
  for (int i = 0; i < 8; i++) {
    byte row = (image >> i * 8) & 0xFF;
    for (int j = 0; j < 8; j++) {
      display.setLed(0, i, j, bitRead(row, j));
    }
  }
}