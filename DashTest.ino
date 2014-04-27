#include <EEPROM.h>
#include <SPI.h>
#include <GD2.h>

#include "Dash.h"
#include "Menu.h"

byte parameterValue[39];  // array to hold incoming ECU data
byte currentDash = 0;     // current dash for display purpose

Dash Dashboard[4];        // instantiate desired number of dashboards

void setup ()
{
  Serial.begin(9600);

  // recover saved dashboard settings from eeprom
  for(byte j = 0; j < 4; j++) {
    for(byte i = 0; i < 8; i++)
      Dashboard[j].g[i].recover(i, j);
  }
  GD.begin(~GD_STORAGE);
}  // end of setup

void loop ()
{
  // get last user input for navigation
  int lastY = GD.inputs.y;
  int lastX = GD.inputs.x;

  GD.get_inputs();

  // algorithm that recognizes the swiping gestures for navigation 
  // swipe down from top of screen for main menu
  if (lastY > 0 && lastY < 40 && GD.inputs.y > 40)
    menuMain();

  // swipe to the left from right edge of screen to go to next dashboard
  if (lastX > 460 && GD.inputs.x < 460) {
    currentDash = (currentDash == 3) ? 0 : currentDash + 1;
  }

  // routine that draws needed gauges to display
  GD.Clear();
  Dashboard[currentDash].display();
  delay(20);
  GD.swap();
  delay(60);

  // request data over serial from the ECU
  Serial.write('R');
}  // end of loop

void serialEvent() {
  byte i = 0;

  // read all data from the ECU into the paramterValue array
  while (Serial.available()) {
    // get the new byte:
    parameterValue[i++] = (byte)Serial.read(); 
  }
}





