#include <EEPROM.h>
#include <SPI.h>
#include <GD2.h>

#include "Dash.h"
#include "Menu.h"

String parameterName[]={"SECL",  "SQRT",  "ENGN",   "BARO",  "MAP",   "MAT",     "CLT",   "TPS",    "BAT",  "EGO",   
                       "EGO1%", "AIR%",  "ENRCH%", "RPM",   "PW1",   "AENRICH", "BARO%", "GAMA%",  "VE1%", "PW2",   
                       "VE2%",  "IDLE%", "iTIME",  "iTime", "ADV",   "AFRTGT",  "FUEL",  "EGT",    "CLT<", "KNCK<", 
                       "EGO2%", "PORTA", "PORTB",  "PORTC", "PORTD", "STACK",   "TPSL",  "iTimeX", "BCDC"};
byte parameterValue[38];
byte currentDash = 0;

Dash Dashboard;//[8];

void setup ()
  {
    GD.begin();

    Dashboard.addGauge(0);
    Dashboard.addGauge(1);
    Dashboard.addGauge(2);
//    Dashboard.addGauge(3);
//    Dashboard.display();


  }  // end of setup

void loop ()
  {
  int lastY = GD.inputs.y;
  //sint lastX = GD.inputs.x;
  
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
