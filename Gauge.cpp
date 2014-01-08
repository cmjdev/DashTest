#include "Gauge.h"

#define options OPT_FLAT | OPT_CENTER

Gauge::Gauge(){}

void Gauge::move(int newX, int newY) {
  x = newX;  // update x coordinate
  y = newY;  // update y coordinate
}

void Gauge::resize(int w, int h) {
  width = w;
  height = h;
}

void Gauge::update() {
  switch(type) {
    case 0:  // analog gauge
      // analog display code
      break;
    case 1:  // digital gauge
      // digital display code
      break;
    case 2:  // bargraph
      // bargraph display code
      break;
    case 3:  // indicator
      // indicator display code
      break;
  }
}
Analog::Analog(int r, byte p, String s) {
  radius = r;
  parameter = p;
  type = 0;
  s.toCharArray(label,8);
}

void Analog::resize(int r) {
  radius = r;
}

Digital::Digital(int w, int h, byte p) {
  width = w;
  height = h;
  parameter = p;
  type = 1;
  s.toCharArray(label,8);
}

Bargraph::Bargraph(int w, int h, byte p) {
  width = w;
  height = h;
  parameter = p;
  type = 2;
  s.toCharArray(label,8);
}

Indicator::Indicator(int w, int h, byte p) {
  width = w;
  height = h;
  parameter = p;
  type = 3;
  s.toCharArray(label,8);
}


