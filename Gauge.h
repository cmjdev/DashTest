#include <EEPROM.h>
#include <SPI.h>
#include <GD2.h>

#ifndef GaugeClass_H
#define GaugeClass_H

#include "Arduino.h"

class Gauge {
  public:
    Gauge();  // constructor
    ~Gauge();  // destructor
    
    void move(int, int);
    void resize(int, int);
    void update();
    
  protected:
    int x;  // x start position
    int y;  // y start position
    int width;  // width of indicator
    int height;  // height of indicator
    int radius;
    char label[8];
    byte parameter; // parameter number
    byte type;  // gauge type (0-Analog, 1-Digital, 2-Bargraph, 3-Indicator)
};

class Analog : public Gauge {
  public:
    Analog(int, byte, String);  // constructor
    ~Analog();   // destructor
    
    void resize(int);  // resize gauge
    
  protected:
};

class Digital : public Gauge {
  public:
    Digital(int, int, byte);  // constructor
    ~Digital();  // destructor
    
  protected:
};

class Bargraph : public Gauge {
  public:
    Bargraph(int, int, byte);  // constructor
    ~Bargraph();  // destructor

    
  protected:
};

class Indicator : public Gauge {
  public:
    Indicator(int, int, byte);  // constructor
    ~Indicator();  // destructor
    
  protected:
};

#endif
