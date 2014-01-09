#include "Arduino.h"

#ifndef Gauge_H
#define Gauge_H

class Gauge {
  public:
    Gauge();  // constructor
    ~Gauge();  // destructor
    
    void move(int, int);
    void resize(int, int);

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
    Analog(int, int, int, byte);  // constructor
    ~Analog();   // destructor
    
    void resize(int);  // resize gauge
};

class Digital : public Gauge {
  public:
    Digital(int, int, int, int, byte);  // constructor
    ~Digital();  // destructor
};

class Bargraph : public Gauge {
  public:
    Bargraph(int, int, int, int, byte);  // constructor
    ~Bargraph();  // destructor
};

class Indicator : public Gauge {
  public:
    Indicator(int, int, int, int, byte);  // constructor
    ~Indicator();  // destructor
};

#endif
