#include "Arduino.h"
#include "Gauge.h"

#ifndef Dash_H
#define Dash_H

class Dash {
private:

public:
  Dash();
  ~Dash();
  Gauge g[8];
  byte gaugeNumber;  

  void addGauge(byte);
  void clear();

  void display();
};

#endif

