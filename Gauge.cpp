#include "GaugeClass.h"

Gauge::Gauge(){}

Analog::Analog(int r, byte p) {
  radius = r;
  parameter = p;
  type = 0;
}
