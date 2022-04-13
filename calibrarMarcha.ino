// C++
//
#include <Servo.h>

Servo servo;

int GRAUS = 150;
int somaGraus = 8;
int menosGraus = 9;

void setup(){
  
  Serial.begin(115200);
  pinMode(somaGraus, INPUT);
  pinMode(menosGraus, INPUT);
  servo.attach(2);
  servo.write(GRAUS); 
}

void loop() {
 
  if(digitalRead(somaGraus) == LOW) {
    GRAUS++;
     Serial.print("Aumentando: ");
    Serial.println(GRAUS);
    if(GRAUS >= 170){
      GRAUS = 170;
    };
  };
  
  if (digitalRead(menosGraus) == LOW) {

    GRAUS--;
    Serial.print("Dimunuindo: ");
    Serial.println(GRAUS);
    if(GRAUS <= 0) {
      GRAUS = 0;
    };
  };
  
  servo.write(GRAUS);
  delay(500);  
}
