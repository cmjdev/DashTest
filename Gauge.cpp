#include <SD.h>
#include "Gauge.h"

#define options OPT_FLAT | OPT_CENTER
#define saveFile "dashboard.txt"

extern byte parameterValue[39];
extern String parameterName[];
extern File myFile;

Gauge::Gauge(){
}
Gauge::~Gauge(){
}

// activate and pass parameters to analog gauge object
void Gauge::update(byte _g, int _x, int _y, int _r, byte _t) {
  g = _g;
  x = _x;
  y = _y;
  r = _r;
  t = _t;
  active = true;
}

// activate and pass parameters to all other gauge objects
void Gauge::update(byte _g, int _x, int _y, int _w, int _h, byte _t) {
  g = _g;
  x = _x;
  y = _y;
  w = _w;
  h = _h;
  t = _t;
  active = true;

  parameterName[p].toCharArray(label, 8);
}

void Gauge::move(int _x, int _y) {
  x = _x;  // update x coordinate
  y = _y;  // update y coordinate
}

void Gauge::resize(int _w, int _h) {
  w = _w;
  h = _h;
}


void Gauge::write(){

  parameterName[p].toCharArray(label, 8);

  GD.Tag(g+1);
  switch(t) {
  case 0:
    GD.cmd_gauge(x, y, r, options, 10, 5, parameterValue[p], 255);
    GD.cmd_number(x, y+(r/2), 30, options, parameterValue[p]);
    GD.cmd_text(x, y-(r/3), 28, options, label);  
    break;
  case 1:
    GD.cmd_number(x, y+15, 30, options, parameterValue[p]);
    GD.cmd_text(x, y-15, 28, options, label);  
    break;
  case 2:
    GD.cmd_progress(x, y, w, h, options, parameterValue[p], 255);
    break;
  case 3:
    break;
  }

}

void Gauge::save(byte i){

  //SD.remove("test.txt");
  //myFile = SD.open("test.txt", FILE_WRITE);

  /*byte adr = i*22+300;
   
   EEPROM.write(, g);
   EEPROM.write(, p);
   EEPROM.write(, t);
   EEPROM.write(, active);
   
   EEPROM.write(, highByte(x));
   EEPROM.write(, lowByte(x));
   EEPROM.write(, highByte(y));
   EEPROM.write(, lowByte(y));
   EEPROM.write(, highByte(w));
   EEPROM.write(, lowByte(w));
   EEPROM.write(, highByte(h));
   EEPROM.write(, lowByte(h));
   EEPROM.write(, highByte(r));
   EEPROM.write(, lowByte(r));
   
   for(int i = 0; i < 8; i++)
   EEPROM.write(, label[i]);
   
   Serial.println(adr);
   */
  SD.remove("test.txt");
  myFile = SD.open("test.txt", FILE_WRITE);
  myFile.write(g);
  myFile.write(p);
  myFile.write(t);
  myFile.write(active);

  myFile.write(highByte(x));
  myFile.write(lowByte(x));
  myFile.write(highByte(y));
  myFile.write(lowByte(y));
  myFile.write(highByte(w));
  myFile.write(lowByte(w));
  myFile.write(highByte(h));
  myFile.write(lowByte(h));
  myFile.write(highByte(r));
  myFile.write(lowByte(r));

  for(int i = 0; i < 8; i++)
    myFile.write(label[i]);
  myFile.close();
}

void Gauge::recover(byte i){


  myFile = SD.open("test.txt", FILE_READ);

  g = myFile.read();
  p = myFile.read();
  t = myFile.read();
  active = myFile.read();

  x = word(myFile.read(),myFile.read());
  y = word(myFile.read(),myFile.read());
  w = word(myFile.read(),myFile.read());
  h = word(myFile.read(),myFile.read());
  r = word(myFile.read(),myFile.read());

  for(int i = 0; i < 8; i++)
    label[i] = myFile.read();

  myFile.close();

}

