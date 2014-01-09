#include "Dash.h"

char* parameterName[]={"SECL",  "SQRT",  "ENGN",   "BARO",  "MAP",   "MAT",     "CLT",   "TPS",    "BAT",  "EGO",   
                       "EGO1%", "AIR%",  "ENRCH%", "RPM",   "PW1",   "AENRICH", "BARO%", "GAMA%",  "VE1%", "PW2",   
                       "VE2%",  "IDLE%", "iTIME",  "iTime", "ADV",   "AFRTGT",  "FUEL",  "EGT",    "CLT<", "KNCK<", 
                       "EGO2%", "PORTA", "PORTB",  "PORTC", "PORTD", "STACK",   "TPSL",  "iTimeX", "BCDC"};
byte parameterValue[38];

Dash Dashboard = Dash();

void setup ()
  {
    Serial.begin(9600);
    Dashboard.addGauge(0);
    Dashboard.addGauge(1);
    Dashboard.addGauge(2);
    Dashboard.addGauge(3);

  }  // end of setup

void loop ()
  {
    Serial.print(Dashboard.gaugeNumber);
    delay(1000);
  }  // end of loop
