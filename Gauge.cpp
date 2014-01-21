#include "Gauge.h"

#define options OPT_FLAT | OPT_CENTER

extern byte parameterValue[39];
extern char* parameterName[];


Gauge::Gauge(){}
Gauge::~Gauge(){}

void Gauge::update(int _x, int _y, int _r, byte _t) {
  x = _x;
  y = _y;
  r = _r;
  t = _t;
  active = true;
}

void Gauge::move(int _x, int _y) {
  x = _x;  // update x coordinate
  y = _y;  // update y coordinate
}

void Gauge::resize(int _w, int _h) {
  w = _w;
  h = _h;
}

void Gauge::write(){
  switch(t) {
    case 0:
      GD.cmd_gauge(x, y, r, options, 10, 5, parameterValue[p], 255);
      GD.cmd_number(x, y+(r/2), 30, options, parameterValue[p]);
      GD.cmd_text(x, y-(r/3), 24, options, label);  
      break;
    case 1:
      break;
    case 2:
      break;
    case 3:
      break;
  }

}
