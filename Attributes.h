#include <avr/pgmspace.h>


//  The attributes file stores all static strings in EEPROM.

#ifndef Dash_H
#define Dash_H
prog_char string_0[] PROGMEM = "SECL";   
prog_char string_1[] PROGMEM = "SQRT";
prog_char string_2[] PROGMEM = "ENGN";
prog_char string_3[] PROGMEM = "BARO";
prog_char string_4[] PROGMEM = "MAP";
prog_char string_5[] PROGMEM = "MAT";
prog_char string_6[] PROGMEM = "CLT";   
prog_char string_7[] PROGMEM = "TPS";
prog_char string_8[] PROGMEM = "BAT";
prog_char string_9[] PROGMEM = "EGO";
prog_char string_10[] PROGMEM = "EGO1%";
prog_char string_11[] PROGMEM = "AIR%";
prog_char string_12[] PROGMEM = "ENRCH%";   
prog_char string_13[] PROGMEM = "RPM";
prog_char string_14[] PROGMEM = "PW1";
prog_char string_15[] PROGMEM = "AENRCH";
prog_char string_16[] PROGMEM = "BARO%";
prog_char string_17[] PROGMEM = "GAMA%";
prog_char string_18[] PROGMEM = "VE1%";   
prog_char string_19[] PROGMEM = "PW2";
prog_char string_20[] PROGMEM = "VE2%";
prog_char string_21[] PROGMEM = "IDLE%";
prog_char string_22[] PROGMEM = "iTIME";
prog_char string_23[] PROGMEM = "iTIME";
prog_char string_24[] PROGMEM = "ADV";   
prog_char string_25[] PROGMEM = "AFRTGT";
prog_char string_26[] PROGMEM = "FUEL";
prog_char string_27[] PROGMEM = "EGT";
prog_char string_28[] PROGMEM = "CLT<";
prog_char string_29[] PROGMEM = "KNCK<";
prog_char string_30[] PROGMEM = "EGO2%";   
prog_char string_31[] PROGMEM = "PORTA";
prog_char string_32[] PROGMEM = "PORTB";
prog_char string_33[] PROGMEM = "PORTC";
prog_char string_34[] PROGMEM = "PORTD";
prog_char string_35[] PROGMEM = "STACK";
prog_char string_36[] PROGMEM = "TPSL";   
prog_char string_37[] PROGMEM = "iTIMEX";
prog_char string_38[] PROGMEM = "BCDC";

// Struct for easy string reference

PROGMEM const char *parameterName[] = 
{   
  string_0,
  string_1,
  string_2,
  string_3,
  string_4,
  string_5,
  string_6,
  string_7,
  string_8,
  string_9,
  string_10,
  string_11,
  string_12,
  string_13,
  string_14,
  string_15,
  string_16,
  string_17,
  string_18,
  string_19,
  string_20,
  string_21,
  string_22,
  string_23,
  string_24,
  string_25,
  string_26,
  string_27,
  string_28,
  string_29,
  string_30,
  string_31,
  string_32,
  string_33,
  string_34,
  string_35,
  string_36,
  string_37,
  string_38
};
#endif

