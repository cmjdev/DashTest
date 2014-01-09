#include <EEPROM.h>
#include <SPI.h>
#include <GD2.h>

#include "Arduino.h"
#include "Gauge.h"

#ifndef Dash_H
#define Dash_H

class Dash {
  private:
  
  public:
  Dash();
  ~Dash();
    byte gaugeNumber;  

  void addGauge(byte);

  Gauge * g[8];
  
  void display();
};

#endif
