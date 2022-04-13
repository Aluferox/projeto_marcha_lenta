#include <Adafruit_GFX.h>
#include <MCUFRIEND_kbv.h>
#include <TouchScreen.h>
#include <Servo.h>

#define BLACK 0x0000
#define NAVY 0x000F
#define DARKGREEN 0x03E0
#define DARKCYAN 0x03EF
#define MAROON 0x7800
#define PURPLE 0x780F
#define OLIVE 0x7BE0
#define LIGHTGREY 0xC618
#define DARKGREY 0x7BEF
#define BLUE 0x001F
#define GREEN 0x07E0
#define CYAN 0x07FF
#define RED 0xF800
#define MAGENTA 0xF81F
#define YELLOW 0xFFE0
#define WHITE 0xFFFF
#define ORANGE 0xFD20
#define GREENYELLOW 0xAFE5
#define PINK 0xF81F

# define LCD_CS A3 
# define LCD_CD A2 
# define LCD_WR A1 
# define LCD_RD A0 
# define LCD_RESET A4
MCUFRIEND_kbv tft(A3, A2, A1, A0, A4); 

//const int XP=8,XM=A2,YP=A3,YM=9; //240x320 ID=0x7789
#define XP 8
#define XM A2
#define YP A3  
#define YM 9   

//const int TS_LEFT=98,TS_RT=893,TS_TOP=897,TS_BOT=121;
// definições para LANDSCAPE
#define TS_LEFT 98
#define TS_RT   893
#define TS_TOP  897
#define TS_BOT  121

TouchScreen ts = TouchScreen(XP, YP, XM, YM, 300);
Servo myServo;

int width_buttons = 150;
int height_buttons = 50;
int pin_servo = 52;
int button;
int march = 180;

void setup() {

  Serial.begin(115200);
  myServo.attach(pin_servo);
  myServo.write(180);
  
  tft.reset();
  uint16_t ID = tft.readID(); 
  tft.begin(ID);

  tft.setRotation(1);

  description(true);
  draw_buttons();

}

void loop() {

  TSPoint p = ts.getPoint();
  if (p.z > ts.pressureThreshhold) {

    p.x = map(p.x, TS_LEFT, TS_RT, 0, tft.height()); // ALTURA
    p.y = map(p.y, TS_BOT, TS_TOP, 0, tft.width()); //  LARGURA

    pinMode(XM, OUTPUT);
    pinMode(YP, OUTPUT);
    tft.setTextSize(4);

      tft.setCursor(70, 15);
    if(p.x <= 230 &&p.x >= 190 && p.y >= 5 && p.y <= 135){ //BOTÃO 1
      tft.fillRect(5, 5, 150, 50, RED); //BOTÃO 1
      tft.println(1);
      button = 1;
      march = 59;
    };

    if(p.x <= 229 && p.x >= 195 && p.y >= 165 && p.y <= 306){ // BOTÃO 2
      tft.fillRect(165 ,5 ,width_buttons, height_buttons, RED); //BOTÃO 2
      tft.setCursor(230, 15);
      tft.println(2);
      button = 2;
      march = 78;
    }

    if(p.x >= 135 && p.x <= 175 && p.y >=5 && p.y <=135){ //BOTAO 3
      tft.fillRect(5 ,65 , width_buttons, height_buttons, RED); //BOTÃO 3
      tft.setCursor(70, 75);
      tft.println(3);
      button = 3;
      march = 92;

    }

    if (p.x >= 130 && p.x <= 175 && p.y >= 165 && p.y <= 305){ //BOTÃO 4
      tft.fillRect(165, 65, width_buttons, height_buttons, RED); //BOTÃO 4
      tft.setCursor(230, 75);
      tft.println(4);
      button = 4;
      march = 103;
    } 

    if (p.x >= 75 && p.x <= 115 && p.y >= 5 && p.y <= 135){ //BOTÃO 5
      tft.fillRect(5, 125, width_buttons, height_buttons, RED); //BOTÃO 5
      tft.setCursor(70, 135);
      tft.println(5);
      button = 5;
      march = 116;
    } 

    if (p.x >= 75 &&  p.x <= 115 && p.y >= 165 && p.y <= 305){ //BOTÃO 6
      tft.fillRect(165, 125, width_buttons, height_buttons, RED); //BOTÃO 6
      tft.setCursor(230, 135);
      tft.println(6);
      button = 6;
      march = 129;
    } 

    if (p.x >= 15 && p.x <= 55 && p.y >= 5 && p.y <= 135){ //BOTÃO 7
      tft.fillRect(5, 185, width_buttons, height_buttons, RED); //BOTÃO 7
      tft.setCursor(70, 195);

      tft.println(7);
      button = 7;
      march =   146;

    } 

    if (p.x >= 15 && p.x <= 55 && p.y >= 165 && p.y <= 305){ //BOTÃO 8
      tft.fillRect(165, 185, width_buttons, height_buttons, RED); //BOTÃO 8
      tft.setCursor(230, 195);
      tft.println(8);
      button = 8;
      march = 180;
    } 

    paint_buttons(button);
    myServo.write(march);

  }
}

void draw_buttons() {

  tft.fillScreen(CYAN);
  tft.setTextColor(WHITE);
  tft.setTextSize(4);

  tft.fillRect(5, 5, width_buttons, height_buttons, DARKGREEN); //BOTÃO 1
  tft.setCursor(70, 15);
  tft.println(1);

  tft.fillRect(165 ,5 ,width_buttons, height_buttons, DARKGREEN); //BOTÃO 2
  tft.setCursor(230, 15);
  tft.println(2);

  tft.fillRect(5 ,65 , width_buttons, height_buttons, DARKGREEN); //BOTÃO 3
  tft.setCursor(70, 75);
  tft.println(3);

  tft.fillRect(165, 65, width_buttons, height_buttons, DARKGREEN); //BOTÃO 4
  tft.setCursor(230, 75);
  tft.println(4);

  tft.fillRect(5, 125, width_buttons, height_buttons, DARKGREEN); //BOTÃO 5
  tft.setCursor(70, 135);
  tft.println(5);

  tft.fillRect(165, 125, width_buttons, height_buttons, DARKGREEN); //BOTÃO 6
  tft.setCursor(230, 135);
  tft.println(6);

  tft.fillRect(5, 185, width_buttons, height_buttons, DARKGREEN); //BOTÃO 7
  tft.setCursor(70, 195);
  tft.println(7);

  tft.fillRect(165, 185, width_buttons, height_buttons, RED); //BOTÃO 8
  tft.setCursor(230, 195);
  tft.println(8);
  
};

void paint_buttons(int button) {
 
    if(button != 1){ //BOTÃO 1
      tft.fillRect(5, 5, width_buttons, height_buttons, DARKGREEN); //BOTÃO 1
      tft.setCursor(70, 15);
      tft.println(1);
     } 
     
    if(button != 2) {
      tft.fillRect(165 ,5 ,width_buttons, height_buttons, DARKGREEN); //BOTÃO 2
      tft.setCursor(230, 15);
      tft.println(2);
     }
    
    if(button != 3) { //BOTÃO 3
      tft.fillRect(5 ,65 , width_buttons, height_buttons, DARKGREEN); //BOTÃO 3
      tft.setCursor(70, 75);
      tft.println(3);
     }

    if(button != 4) { //BOTÃO 4
      tft.fillRect(165, 65, width_buttons, height_buttons, DARKGREEN); //BOTÃO 4
      tft.setCursor(230, 75);
      tft.println(4);
     }

    if(button != 5) { //BOTÃO 5
      tft.fillRect(5, 125, width_buttons, height_buttons, DARKGREEN); //BOTÃO 5
      tft.setCursor(70, 135);
      tft.println(5);
     }

    if(button != 6) { //BOTÃO 6  
      tft.fillRect(165, 125, width_buttons, height_buttons, DARKGREEN); //BOTÃO 6
      tft.setCursor(230, 135);
      tft.println(6);
     }

    if(button != 7) { //BOTÃO 7
      tft.fillRect(5, 185, width_buttons, height_buttons, DARKGREEN); //BOTÃO 7
      tft.setCursor(70, 195);
      tft.println(7);
     }

    if(button != 8) { //BOTÃO 8
      tft.fillRect(165, 185, width_buttons, height_buttons, DARKGREEN); //BOTÃO 8
      tft.setCursor(230, 195);
      tft.println(8);
     }
  };

void description(bool boolean){

    tft.fillScreen(BLACK);

    tft.setCursor (40, 30);
    tft.setTextSize (2.5);
    tft.setTextColor(ORANGE);
    tft.println("Projeto Marcha Lenta");

    tft.setCursor (5, 80);
    tft.setTextSize (2);
    tft.setTextColor(BLUE);
    tft.print("Plataforma: ");
    tft.setTextColor(GREEN);
    tft.println("ARDUINO");
    tft.setCursor (30, 180);

    tft.setCursor(5, 130);
    tft.setTextSize (2);
    tft.setTextColor(BLUE);
    tft.print("Desenvolvedor:");
    tft.setTextColor(GREEN);
    tft.println("ENEIAS PAULO");

    tft.setCursor(5, 180);
    tft.setTextColor(BLUE);
    tft.print("Versao:");
    tft.setTextColor(GREEN);
    tft.println("BETA <<- ->> 1.0");
    
    while (boolean)
    {
      TSPoint p = ts.getPoint();
      if (p.z > ts.pressureThreshhold) {
        boolean = false;
        pinMode(XM, OUTPUT);
        pinMode(YP, OUTPUT);
    }
      
  }
}