#include "Gauge.h"

#define options OPT_FLAT | OPT_CENTER

extern byte parameterValue[39];
extern String parameterName[];


Gauge::Gauge(){}
Gauge::~Gauge(){}

// activate and pass parameters to analog gauge object
void Gauge::update(byte _g, int _x, int _y, int _r, byte _t) {
  g = _g;
  x = _x;
  y = _y;
  r = _r;
  t = _t;
  active = true;
}

// activate and pass parameters to all other gauge objects
void Gauge::update(byte _g, int _x, int _y, int _w, int _h, byte _t) {
  g = _g;
  x = _x;
  y = _y;
  w = _w;
  h = _h;
  t = _t;
  active = true;
  
  parameterName[p].toCharArray(label, 8);
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
  
  parameterName[p].toCharArray(label, 8);
  
  GD.Tag(g+1);
  switch(t) {
    case 0:
      GD.cmd_gauge(x, y, r, options, 10, 5, parameterValue[p], 255);
      GD.cmd_number(x, y+(r/2), 30, options, parameterValue[p]);
      GD.cmd_text(x, y-(r/3), 28, options, label);  
      break;
    case 1:
      GD.cmd_number(x, y+15, 30, options, parameterValue[p]);
      GD.cmd_text(x, y-15, 28, options, label);  
      break;
    case 2:
      GD.cmd_progress(x, y, w, h, options, parameterValue[p], 255);
      break;
    case 3:
      break;
  }

}

void Gauge::save(){
  
byte adr = g*22;

EEPROM.write(adr++, g);
EEPROM.write(adr++, p);
EEPROM.write(adr++, t);
EEPROM.write(adr++, active);

EEPROM.write(adr++, highByte(x));
EEPROM.write(adr++, lowByte(x));
EEPROM.write(adr++, highByte(y));
EEPROM.write(adr++, lowByte(y));
EEPROM.write(adr++, highByte(w));
EEPROM.write(adr++, lowByte(w));
EEPROM.write(adr++, highByte(h));
EEPROM.write(adr++, lowByte(h));
EEPROM.write(adr++, highByte(r));
EEPROM.write(adr++, lowByte(r));

for(int i = 0; i < 8; i++)
  EEPROM.write(adr++, label[i]);
}
