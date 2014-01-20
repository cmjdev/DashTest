#include "Dash.h"

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
  

    g[0].write();
    Serial.println("dash write done");

  
}
