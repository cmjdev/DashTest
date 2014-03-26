#include "Attributes.h"

#include "Gauge.h"
#include "EasyEEPROM.h"


#define options OPT_FLAT | OPT_CENTER

extern byte parameterValue[39];
char label[8];

Gauge::Gauge(){

}
Gauge::~Gauge(){
}

// activate and pass parameters to analog gauge object
void Gauge::update(byte _g, int _x, int _y, int _r, byte _t) {
  settings.g = _g;
  settings.x = _x;
  settings.y = _y;
  settings.r = _r;
  settings.t = _t;
  settings.p = 0;
  settings.active = true;
}

// activate and pass parameters to all other gauge objects
void Gauge::update(byte _g, int _x, int _y, int _w, int _h, byte _t) {
  settings.g = _g;
  settings.x = _x;
  settings.y = _y;
  settings.w = _w;
  settings.h = _h;
  settings.t = _t;
  settings.p = 0;
  settings.active = true;
}

void Gauge::move(int _x, int _y) {
  settings.x = _x / 10 * 10;  // update x coordinate
  settings.y = _y / 10 * 10;  // update y coordinate
}

void Gauge::resize(int _w, int _h) {
  settings.w = _w;
  settings.h = _h;
}


void Gauge::write(){

  GD.Tag(settings.g+1);
  switch(settings.t) {
  case 0:
    GD.cmd_gauge(settings.x, settings.y, settings.r, options, 10, 5, parameterValue[settings.p], 255);
    GD.cmd_number(settings.x, settings.y+(settings.r/2), 30, options, parameterValue[settings.p]);
    GD.cmd_text(settings.x, settings.y-(settings.r/3), 28, options, getName());  
    break;
  case 1:
    GD.cmd_number(settings.x, settings.y+15, 30, options, parameterValue[settings.p]);
    GD.cmd_text(settings.x, settings.y-15, 28, options, getName());  
    break;
  case 2:
    GD.cmd_progress(settings.x, settings.y, settings.w, settings.h, options, parameterValue[settings.p], 255);
    break;
  case 3:
    break;
  }

}

char* Gauge::getName() {
  strcpy_P(label, (char*)pgm_read_word(&(parameterName[settings.p])));
  return label;
}


void Gauge::save(){

  EEPROM_writeAnything(settings.g*15+100, settings);

}

void Gauge::recover(){

  EEPROM_readAnything(settings.g*15+100, settings);

}



