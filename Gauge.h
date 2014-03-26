#include <EEPROM.h>
#include <SPI.h>
#include <GD2.h>

#include "Arduino.h"

#ifndef Gauge_H
#define Gauge_H

class Gauge {
public:
  Gauge();  // constructor
  ~Gauge();  // destructor

  struct settings_t {
    byte g;  // gauge number for tagging
    word x;  // x start position
    word y;  // y start position
    word w;  // width of gauge
    word h;  // height of gauge
    word r;  // radius of analog gauge
    byte p; // parameter number
    byte t;  // gauge type (0-Analog, 1-Digital, 2-Bargraph, 3-Indicator)
    byte active;  // gauge in use
  } 
  settings;

  void update(byte, int, int, int, byte); // analog update
  void update(byte, int, int, int, int, byte); // all others update
  void move(int, int);
  void resize(int, int);
  void write();
  char* getName();
  void save();
  void recover();
};


#endif


