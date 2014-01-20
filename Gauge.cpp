#include "Gauge.h"

#define options OPT_FLAT | OPT_CENTER

extern byte parameterValue[39];
extern char* parameterName[];


Gauge::Gauge(){}

void Gauge::move(int _x, int _y) {
  x = _x;  // update x coordinate
  y = _y;  // update y coordinate
}

void Gauge::resize(int _w, int _h) {
  w = _w;
  h = _h;
}

void Gauge::write(){}  // overloaded by sub functions

Analog::Analog(int _x, int _y, int _r, byte _p) {
  x = _x;
  y = _y;
  r = _r;
  p = _p;
  t= 0;

}

void Analog::resize(int _r) {
  r = _r;
}

void Analog::write() {
  GD.cmd_gauge(x, y, w, options, 10, 5, parameterValue[p], 255);
  GD.cmd_number(x, y+(w/2), 30, options, parameterValue[p]);
  GD.cmd_text(x, y-(w/3), 24, options, label);
  Serial.println("gauge write done");
}

Digital::Digital(int _x, int _y, int _w, int _h, byte _p) {
  x = _x;
  y = _y;
  w = _w;
  h = _h;
  p = _p;
  t = 1;
}

void Digital::write() {
  // function to display gauge
}

Bargraph::Bargraph(int _x, int _y, int _w, int _h, byte _p) {
  x = _x;
  y = _y;
  w = _w;
  h = _h;
  p = _p;
  t = 2;
}

void Bargraph::write() {
  // function to display gauge
}

Indicator::Indicator(int _x, int _y, int _w, int _h, byte _p) {
  x = _x;
  y = _y;
  w = _w;
  h = _h;
  p = _p;
  t = 3;
}

void Indicator::write() {
  // function to display gauge
}


