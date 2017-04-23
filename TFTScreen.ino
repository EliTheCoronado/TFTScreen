
#include <SPI.h>
#include "Adafruit_GFX.h"
#include "Adafruit_RA8875.h"

// Library only supports hardware SPI at this time
// Connect SCLK to UNO Digital #13 (Hardware SPI clock)
// Connect MISO to UNO Digital #12 (Hardware SPI MISO)
// Connect MOSI to UNO Digital #11 (Hardware SPI MOSI)
#define RA8875_INT 3
#define RA8875_CS 10
#define RA8875_RESET 9

Adafruit_RA8875 tft = Adafruit_RA8875(RA8875_CS, RA8875_RESET);
uint16_t tx, ty;
 int gas = 0;
  int sped = 0;
void setup() {
  Serial.begin(9600);
  Serial.println("RA8875 start");

  /* Initialise the display using 'RA8875_480x272' or 'RA8875_800x480' */
  if (!tft.begin(RA8875_480x272)) {
    Serial.println("RA8875 Not Found!");
    while (1);
  }
  tft.displayOn(true);
  tft.GPIOX(true);      // Enable TFT - display enable tied to GPIOX
  tft.PWM1config(true, RA8875_PWM_CLK_DIV1024); // PWM output for backlight
  tft.PWM1out(255);
  tft.fillScreen(RA8875_BLACK);

  /* Switch to text mode */  
  tft.textMode();
  tft.textTransparent(RA8875_WHITE);
  tft.textEnlarge(1);
  prntFuelLevel(7);
  prntSpeed(20);

//This is now testing code, doesn't need to remain.
 
}

void loop() {
  // put your main code here, to run repeatedly:
 /* tft.fillScreen(RA8875_BLACK);
  prntFuelLevel(gas);
  prntSpeed(sped);
  gas++;
  sped++;
  if(gas > 8){
    gas = 0;
  }
  if(sped > 35){
    sped = 0;
  }
*/
}
void prntFuelLevel(int fuelLevel){
  char fuelPrefix[8] = "Fuel: ";
  char fuelUnit[] = "# ";
  tft.textSetCursor(10,10);
  tft.textWrite(fuelPrefix);
  for(int i = 0; i < fuelLevel; i++){
    tft.textWrite(fuelUnit);
  }
}
void prntSpeed(int fast){
  tft.textSetCursor(250,150);
  tft.textEnlarge(10);
  char going = fast;
  tft.textWrite("35");
}

