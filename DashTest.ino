#include <EEPROM.h>
#include <SPI.h>
#include <GD2.h>

#include "Dash.h"

char* parameterName[]={"SECL",  "SQRT",  "ENGN",   "BARO",  "MAP",   "MAT",     "CLT",   "TPS",    "BAT",  "EGO",   
                       "EGO1%", "AIR%",  "ENRCH%", "RPM",   "PW1",   "AENRICH", "BARO%", "GAMA%",  "VE1%", "PW2",   
                       "VE2%",  "IDLE%", "iTIME",  "iTime", "ADV",   "AFRTGT",  "FUEL",  "EGT",    "CLT<", "KNCK<", 
                       "EGO2%", "PORTA", "PORTB",  "PORTC", "PORTD", "STACK",   "TPSL",  "iTimeX", "BCDC"};
byte parameterValue[38];

Dash Dashboard;

void setup ()
  {
    GD.begin();
    GD.ClearColorRGB(0x000000);
    GD.cmd_bgcolor(0x000000);
    GD.cmd_fgcolor(0xFFFFFF);
    
    Dashboard.addGauge(0);
 /* Dashboard.addGauge(1);
    Dashboard.addGauge(2);
    Dashboard.addGauge(3);
    Dashboard.display();
  */

  }  // end of setup

void loop ()
  {
    GD.Clear();
    Dashboard.display();
    GD.swap();
    delay(1000);
  }  // end of loop
