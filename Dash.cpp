#include "Dash.h"

Dash::Dash() {
  gaugeNumber = 0;
  Gauge g[8];
}

Dash::~Dash() {
}

void Dash::addGauge(byte t) {
  switch (t) {
  case 0:
    g[gaugeNumber].update(gaugeNumber++, 240,115,100,t);
    break;
  case 1:
    g[gaugeNumber].update(gaugeNumber++, 60,50,100,80,t);
    break;
  case 2:
    g[gaugeNumber].update(gaugeNumber++, 80,225,260,40,t);
  case 3:
    break;
  }
}

void Dash::display() {

  for(int i = 0; i < 8; i++) {
    if(g[i].active)
      g[i].write();
  }

}

