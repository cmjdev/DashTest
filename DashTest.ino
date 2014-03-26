#include <EEPROM.h>
#include <SPI.h>
#include <GD2.h>

#include "Dash.h"
#include "Menu.h"

byte parameterValue[39];
byte currentDash = 0;

Dash Dashboard[3];

void setup ()
{
  Serial.begin(9600);
    for(byte i = 0; i < 8; i++)
      Dashboard[currentDash].g[i].recover();
  
  GD.begin(~GD_STORAGE);
}  // end of setup

void loop ()
{
  int lastY = GD.inputs.y;
  int lastX = GD.inputs.x;

  GD.get_inputs();

  if (lastY > 0 && lastY < 40 && GD.inputs.y > 40)
    menuMain();

  if (lastX > 460 && GD.inputs.x < 460)
    currentDash = (currentDash == 2) ? 0 : currentDash + 1;


  GD.Clear();
  Dashboard[currentDash].display();
  delay(20);
  GD.swap();
  delay(60);

  Serial.write('R');
}  // end of loop

void serialEvent() {
  byte i = 0;
  while (Serial.available()) {
    // get the new byte:
    parameterValue[i++] = (byte)Serial.read(); 
  }
}


