#include <EEPROM.h>
#include <SPI.h>
#include <GD2.h>

#include "Dash.h"
#include "Menu.h"

byte parameterValue[39];
byte currentDash = 0;

Dash Dashboard;

void setup ()
{
  Serial.begin(9600);
  
  for(byte i = 0; i < 8; i++)
    Dashboard.g[i].recover(i);

  GD.begin(~GD_STORAGE);
}  // end of setup

void loop ()
{
  int lastY = GD.inputs.y;

  GD.get_inputs();

  if (lastY > 0 && lastY < 20 && GD.inputs.y > 20)
    menuMain();

  //if (lastX > 200 && lastX && GD.inputs.x < 200)
  //currentDash = (currentDash == 7) ? 0 : currentDash++;

  GD.Clear();
  Dashboard.display();
  delay(20);
  GD.swap();
  delay(60);
}  // end of loop


