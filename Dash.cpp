#include "Dash.h"

#define options OPT_FLAT | OPT_CENTER

Dash::Dash() {
  gaugeNumber = 0;
}

Dash::~Dash() {}

void Dash::addGauge(byte t) {
  switch (t) {
    case 0:
      g[gaugeNumber++] = new Analog(280,136,60,0);
      break;
    case 1:
      g[gaugeNumber++] = new Digital(280,136,60,60,0);
      break;
    case 2:
      g[gaugeNumber++] = new Bargraph(280,136,100,60,0);
      break;
    case 3:
      g[gaugeNumber++] = new Indicator(280,136,40,20,0);
      break;
  }
}

void Dash::display() {
  
  for(byte i = 0; i < gaugeNumber; i++) {
   switch (g[i].type) {
     case 0:
      Serial.println("display analog"); 
      break;
     case 1:
       Serial.println("display digital");
       break;
     case 2:
       Serial.println("display bargraph");
       break;
     case 3:
       Serial.println("display indicator");
       break;
   }
  }
  
}
