//  LIBRARIES
//---------------------------------------------------------------
#include <SPI.h>
#include <MFRC522.h>
#include <TouchScreen.h>
#include <Elegoo_TFTLCD.h>
#include <pin_magic.h>
#include <registers.h>
#include <Elegoo_GFX.h>
//---------------------------------------------------------------

//  RFID
//---------------------------------------------------------------
#define RST_PIN 9
#define SS_PIN 10
MFRC522 mfrc522(SS_PIN, RST_PIN);
//---------------------------------------------------------------

//  TOUCH
//---------------------------------------------------------------
#define YP A3 //analog pin required
#define XM A2 //analog pin required
#define YM 9  //digital pin
#define XP 8  //digital pin

#define TS_min_x 120
#define TS_max_x 900 
#define TS_min_y 70
#define TS_max_y 920

TouchScreen TS = TouchScreen(XP, YP, XM, YM, 300);
//---------------------------------------------------------------

//  LCD
//---------------------------------------------------------------
#define LCD_CS A3
#define LCD_CD A2
#define LCD_WR A1
#define LCD_RD A0
#define LCD_RESET A4

Elegoo_TFTLCD tft(LCD_CS, LCD_CD, LCD_WR, LCD_RD, LCD_RESET);
//---------------------------------------------------------------

//  COLORS
//---------------------------------------------------------------
#define BLACK     0x0000
#define BRIGHTRED 0xF800
#define WHITE     0xFFFF
#define PETROL    0xD73C
//---------------------------------------------------------------

//  TOUCH POSITION CALCULATION
//---------------------------------------------------------------
#define x_calc    map(pos.x, TS_min_x, TS_max_x, tft.width(), 0);
#define y_calc    (tft.height()-map(pos.y, TS_min_y, TS_max_y, tft.height(), 0));
//---------------------------------------------------------------

//  TOUCH POSITION
//---------------------------------------------------------------
#define posH      digitalWrite(13, HIGH)
#define posL      digitalWrite(13, LOW)
#define getP      TSPoint pos = TS.getPoint()
#define rstXM     pinMode(XM, OUTPUT)
#define rstYP     pinMode(YP, OUTPUT)
#define EasyGetPoint  posH; getP; posL; rstXM; rstYP
//---------------------------------------------------------------

//  GLOBAL VARIABLES
//---------------------------------------------------------------
boolean eingabeActive  = false;
boolean started        = false;
long    code_toWrite   = 0;
int     blurayCount    = 0;
int     index          = -1;
int     ArrMaxLen      = 20;
//---------------------------------------------------------------


//############################################
void setup() {
  Serial.begin(9600);
//-----------Display----------
  uint16_t identifier = tft.readID();
  pinMode(13, OUTPUT); tft.begin(identifier);
  tft.setRotation(2);
  
//------------RFID------------
  SPI.begin(); mfrc522.PCD_Init();
}
//############################################

//############################################
void loop() {
  EasyGetPoint;
  if (!started){started = true; buildStartScreen();}
  if (pos.z > 0){
    pos.x = x_calc; pos.y = y_calc;
    if(pos.x >= 1 && pos.x <= 238 && pos.y >= 1 && pos.y <= 158){
      ScanButtonAnim(); buildRFIDScreen(); runRFIDRead();
    } 
    if(pos.x >= 1 && pos.x <= 238 && pos.y >= 160 && pos.y <= 320){
      BibButtonAnim(); BibInitScreen(); BibRunScreen();
    } 
  }
  delay(10);
}
//############################################

//############################################
void reset(){
  eingabeActive = false;
  started       = false;
  code_toWrite  =  0;
  index         = -1;
}
//############################################
