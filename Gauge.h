#ifndef GaugeClass_H
#define GaugeClass_H

#include "Arduino.h"

class Gauge {
  public:
    Gauge();  // constructor
    ~Gauge();  // destructor
    
    void move(int, int);
    
  //private:
    int x;  // x start position
    int y;  // y start position
    char label[8];
    byte parameter; // parameter number
    byte type;  // gauge type (0-Analog, 1-Digital, 2-Bargraph, 3-Indicator)
};

class Analog : public Gauge {
  public:
    Analog(int, byte);  // constructor
    ~Analog();   // destructor
    
    void resize(int);  // resize gauge
    void update(); // update gauge display
    
  private:
    int radius;  // radius of analog gauge
};

class Digital : public Gauge {
  public:
    Digital();  // constructor
    ~Digital();  // destructor
    
    void resize(int, int); // resize gauge
    void update(); // update gauge display
    
  private:
    int width;  // width of gauge
    int height;  // height of gauge
};

class Bargraph : public Gauge {
  public:
    Bargraph();  // constructor
    ~Bargraph();  // destructor
    
    void resize(int, int);  // resize gauge
    void update();  // update gauge display
    
  private:
    int width;  // width of gauge
    int height;  // height of gauge
};

class Indicator : public Gauge {
  public:
    Indicator();  // constructor
    ~Indicator();  // destructor
    
    void resize(int, int); // resize gauge
    void update(); // update gauge display
    
  private:
    int width;  // width of indicator
    int height;  // height of indicator
};

#endif
