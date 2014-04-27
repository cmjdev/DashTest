#include "Dash.h"

Dash::Dash() {

  // allot space for 8 gauges per dashboard
  Gauge g[8];
}

Dash::~Dash() {
}

void Dash::addGauge(byte t) {

  // add new gauge at next available index based on gauge type
  switch (t) {
  case 0:
    for(byte i = 0; i < 8; i++) {
      if(!g[i].settings.active) {
        g[i].update(i, 240,115,100,t);
        break;
      }
    }
    break;
  case 1:
    for(byte i = 0; i < 8; i++) {
      if(!g[i].settings.active) {
        g[i].update(i, 60,50,100,80,t);
        break;
      }
    }
    break;
  case 2:
    for(byte i = 0; i < 8; i++) {
      if(!g[i].settings.active) {
        g[i].update(i, 80,225,260,40,t);
        break;
      }
    }
    break;
  case 3:
    break;
  }
}

void Dash::clear() {
  for(int i=0; i < 8; i++)
    g[i].settings.active = false;
  gaugeNumber = 0;
}
void Dash::display() {

  // display routine, iterate through all active gauges and write them to lcd
  for(int i = 0; i < 8; i++) {
    if(g[i].settings.active)
      g[i].write();
  }

}





