#include "Dash.h"

Dash::Dash() {
  gaugeNumber = 0;
  Gauge g[8];
}

Dash::~Dash() {}

void Dash::addGauge(byte t) {
  switch (t) {
    case 0:
      g[gaugeNumber++].update(240,136,100,t);
      break;
    case 1:
    case 2:
    case 3:
      //g[gaugeNumber++] = new Indicator(280,136,40,20,0);
      break;
  }
}

void Dash::display() {
  
  for(int i = 0; i < 8; i++) {
    if(g[i].active)
      g[i].write();
  }
  
}
