#include "Gauge.h"

Gauge::Gauge(){}

void Gauge::move(int newX, int newY) {
  x = newX;  // update x coordinate
  y = newY;  // update y coordinate
}

void Gauge::resize(int w, int h) {
  width = w;
  height = h;
}

Analog::Analog(int newX, int newY, int r, byte p) {
  x = newX;
  y = newY;
  radius = r;
  parameter = p;
  type = 0;

}

void Analog::resize(int r) {
  radius = r;
}

Digital::Digital(int newX, int newY, int w, int h, byte p) {
  x = newX;
  y = newY;
  width = w;
  height = h;
  parameter = p;
  type = 1;
}

Bargraph::Bargraph(int newX, int newY, int w, int h, byte p) {
  x = newX;
  y = newY;
  width = w;
  height = h;
  parameter = p;
  type = 2;
}

Indicator::Indicator(int newX, int newY, int w, int h, byte p) {
  x = newX;
  y = newY;
  width = w;
  height = h;
  parameter = p;
  type = 3;
}


