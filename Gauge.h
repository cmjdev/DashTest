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
    
    void update(int, int, int, byte);
    void move(int, int);
    void resize(int, int);
    void write();

    int x;  // x start position
    int y;  // y start position
    int w;  // width of gauge
    int h;  // height of gauge
    int r;  // radius of analog gauge
    char label[8];
    byte p; // parameter number
    byte t;  // gauge type (0-Analog, 1-Digital, 2-Bargraph, 3-Indicator)
    byte active;  // gauge in use
};


#endif
