#include "Attributes.h"

#include "Gauge.h"
#include "EasyEEPROM.h"


#define options OPT_FLAT | OPT_CENTER

extern byte parameterValue[39];
  char label[8];
/*
FLASH_STRING_ARRAY(parameterName,
  PSTR("SECL"),  PSTR("SQRT"),  PSTR("ENGN"),   PSTR("BARO"),  PSTR("MAP"),   PSTR("MAT"),     PSTR("CLT"),   PSTR("TPS"),    PSTR("BAT"),  PSTR("EGO"),   
  PSTR("EGO1%"), PSTR("AIR%"),  PSTR("ENRCH%"), PSTR("RPM"),   PSTR("PW1"),   PSTR("AENRICH"), PSTR("BARO%"), PSTR("GAMA%"),  PSTR("VE1%"), PSTR("PW2"),   
  PSTR("VE2%"),  PSTR("IDLE%"), PSTR("iTIME"),  PSTR("iTime"), PSTR("ADV"),   PSTR("AFRTGT"),  PSTR("FUEL"),  PSTR("EGT"),    PSTR("CLT<"), PSTR("KNCK<"), 
  PSTR("EGO2%"), PSTR("PORTA"), PSTR("PORTB"),  PSTR("PORTC"), PSTR("PORTD"), PSTR("STACK"),   PSTR("TPSL"),  PSTR("iTimeX"), PSTR("BCDC"));
*/
Gauge::Gauge(){

}
Gauge::~Gauge(){
}

// activate and pass parameters to analog gauge object
void Gauge::update(byte _g, int _x, int _y, int _r, byte _t) {
  settings.g = _g;
  settings.x = _x;
  settings.y = _y;
  settings.r = _r;
  settings.t = _t;
  settings.p = 0;
  settings.active = true;
}

// activate and pass parameters to all other gauge objects
void Gauge::update(byte _g, int _x, int _y, int _w, int _h, byte _t) {
  settings.g = _g;
  settings.x = _x;
  settings.y = _y;
  settings.w = _w;
  settings.h = _h;
  settings.t = _t;
  settings.p = 0;
  settings.active = true;
  
  //parameterName[settings.p].toCharArray(settings.label, 8);
}

void Gauge::move(int _x, int _y) {
  settings.x = _x / 10 * 10;  // update x coordinate
  settings.y = _y / 10 * 10;  // update y coordinate
}

void Gauge::resize(int _w, int _h) {
  settings.w = _w;
  settings.h = _h;
}


void Gauge::write(){

  //parameterName[settings.p].toCharArray(settings.label, 10);
  //strcpy_P(label, (char*)pgm_read_word(&(parameterName[settings.p])));

  GD.Tag(settings.g+1);
  switch(settings.t) {
  case 0:
    GD.cmd_gauge(settings.x, settings.y, settings.r, options, 10, 5, parameterValue[settings.p], 255);
    GD.cmd_number(settings.x, settings.y+(settings.r/2), 30, options, parameterValue[settings.p]);
    GD.cmd_text(settings.x, settings.y-(settings.r/3), 28, options, getName());  
    break;
  case 1:
    GD.cmd_number(settings.x, settings.y+15, 30, options, parameterValue[settings.p]);
    GD.cmd_text(settings.x, settings.y-15, 28, options, parameterName[settings.p]);  
    break;
  case 2:
    GD.cmd_progress(settings.x, settings.y, settings.w, settings.h, options, parameterValue[settings.p], 255);
    break;
  case 3:
    break;
  }

}

char* Gauge::getName() {
   strcpy_P(label, (char*)pgm_read_word(&(parameterName[settings.p])));
   return label;
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
  /*SD.remove("test.txt");
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
  */
  
  EEPROM_writeAnything(i*25+100, settings);
  
}

void Gauge::recover(byte i){

     EEPROM_readAnything(i*25+100, settings);


 /* myFile = SD.open("test.txt", FILE_READ);

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
*/
}


