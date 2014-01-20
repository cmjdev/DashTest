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
    
    void move(int, int);
    void resize(int, int);
    void write();

    int x;  // x start position
    int y;  // y start position
    int w;  // width of gauge
    int h;  // height of gauge
    char label[8];
    byte p; // parameter number
    byte t;  // gauge type (0-Analog, 1-Digital, 2-Bargraph, 3-Indicator)
};

class Analog : public Gauge {
  public:
    Analog(int, int, int, byte);  // constructor
    ~Analog();   // destructor
    
    void resize(int);  // resize gauge
    void write();
    
    int r;
};

class Digital : public Gauge {
  public:
    Digital(int, int, int, int, byte);  // constructor
    ~Digital();  // destructor
    
    void write();
};

class Bargraph : public Gauge {
  public:
    Bargraph(int, int, int, int, byte);  // constructor
    ~Bargraph();  // destructor
    
    void write();
};

class Indicator : public Gauge {
  public:
    Indicator(int, int, int, int, byte);  // constructor
    ~Indicator();  // destructor
    
    void write();
};

#endif
