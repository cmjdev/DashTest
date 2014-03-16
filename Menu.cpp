#include <EEPROM.h>
#include <SPI.h>
#include <GD2.h>
#include <Arduino.h>
#include "Dash.h"
#include "Menu.h"

#define options OPT_FLAT

// define tag constants
#define CREATE_BUTTON 100
#define ANALOG_CREATE 101
#define DIGITAL_CREATE 102
#define BARGRAPH_CREATE 103
#define INDICATOR_CREATE 104

#define EDIT_BUTTON 110
#define POSITION_EDIT 111
#define SIZE_EDIT 112
#define PARAMETER_EDIT 113
#define PARAM_SLIDER 114

#define EXIT_BUTTON 150
#define BACK_BUTTON 151
#define SELECT_BUTTON 152
#define LEFT_BUTTON 153
#define RIGHT_BUTTON 154

extern Dash Dashboard[8];
extern byte currentDash;

byte inMenu = false;

void buildMenu() {
  GD.Clear();
  GD.ColorA(50);
  Dashboard[currentDash].display();
  GD.ColorA(255);
  GD.get_inputs();
}

// function to display main menu
void menuMain() {

  inMenu = true;

  while(inMenu) {

    buildMenu();

    GD.Tag(CREATE_BUTTON);
    GD.cmd_button(5,5,80,30,28, options, "Create");

    GD.Tag(EDIT_BUTTON);
    GD.cmd_button(90,5,80,30,28, options, "Edit");

    GD.Tag(EXIT_BUTTON);
    GD.cmd_button(395, 235, 80, 30, 28, options, "Exit");

    GD.swap();

    switch(GD.inputs.tag) {
    case CREATE_BUTTON:
      menuCreate();
      break;
    case EDIT_BUTTON:
      menuEdit();
      break;
    case EXIT_BUTTON:
      inMenu = false;
      break;
    }
  }
}

void menuCreate() {

  byte inCreate = true;

  while(inMenu && inCreate) {

    buildMenu();

    GD.Tag(ANALOG_CREATE);
    GD.cmd_button(5, 5, 140, 30, 28, options,  "Analog");

    GD.Tag(DIGITAL_CREATE);
    GD.cmd_button(5, 40, 140, 30, 28, options,  "Digital");

    GD.Tag(BARGRAPH_CREATE);
    GD.cmd_button(5, 75, 140, 30, 28, options,  "Bargraph");

    GD.Tag(INDICATOR_CREATE);
    GD.cmd_button(5, 110, 140, 30, 28, options,  "Indicator");

    GD.Tag(BACK_BUTTON);
    GD.cmd_button(310, 235, 80, 30, 28, options,  "Back");

    GD.Tag(EXIT_BUTTON);
    GD.cmd_button(395, 235, 80, 30, 28, options,  "Exit");

    GD.swap();

    switch(GD.inputs.tag) {
    case ANALOG_CREATE:
      Dashboard[currentDash].addGauge(0);
      inCreate = false;
      break;
    case DIGITAL_CREATE:
    Dashboard[currentDash].addGauge(1);
      inCreate = false;
      break;
    case BARGRAPH_CREATE:
    Dashboard[currentDash].addGauge(2);
      inCreate = false;
      break;
    case INDICATOR_CREATE:
    //Dashboard[currentDash].addGauge(0);
      break;
    case BACK_BUTTON:
      inCreate = false;
      break;
    case EXIT_BUTTON:
      inMenu = false;
      break;
    }
  } 
}

void menuEdit() {

  byte inEdit = true;
  byte editGauge = false;
  byte selectedGauge = 1;

  while(inMenu && inEdit) {

    buildMenu();

    Dashboard[currentDash].g[selectedGauge-1].write();
    
    if(GD.inputs.tag > 0 && GD.inputs.tag < 9 && !editGauge)
      selectedGauge = GD.inputs.tag;

    GD.Tag(BACK_BUTTON);
    GD.cmd_button(310, 235, 80, 30, 28, options,  "Back");

    GD.Tag(EXIT_BUTTON);
    GD.cmd_button(395, 235, 80, 30, 28, options,  "Exit");

    if (editGauge) {
      GD.Tag(POSITION_EDIT);
      GD.cmd_button(5, 5, 140, 30, 28, options,  "Position");

      GD.Tag(SIZE_EDIT);
      GD.cmd_button(5, 40, 140, 30, 28, options,  "Size");

      GD.Tag(PARAMETER_EDIT);
      GD.cmd_button(5, 75, 140, 30, 28, options,  "Parameter");
    } 
    else {
      GD.Tag(SELECT_BUTTON);
      GD.cmd_button(205, 235, 100, 30, 28, options,  "Select");
    }

    GD.swap();

    switch(GD.inputs.tag) {
    case POSITION_EDIT:
      moveEdit(selectedGauge-1);
      break;
    case SIZE_EDIT:
      break;
    case PARAMETER_EDIT:
      parameterEdit(selectedGauge-1);
      break;
    case BACK_BUTTON:
      if(editGauge) {
        editGauge = false; 
        delay(200); 
        break;
      }
      inEdit = false;
      break;
    case SELECT_BUTTON:
      editGauge = true;
      break;
    case EXIT_BUTTON:
      inMenu = false;
      break;
    }
  } 
}

void moveEdit(byte g) {

  byte inMove = true;

  while(inMove) {

    buildMenu();
    Dashboard[currentDash].g[g].write();

    GD.Tag(BACK_BUTTON);
    GD.cmd_button(395, 235, 80, 30, 28, options,  "Back");


    GD.swap();

    switch(GD.inputs.tag) {
    case BACK_BUTTON:
      inMove = false; 
      delay(200);
      break;
    }

    while(GD.inputs.x < (Dashboard[currentDash].g[g].x + 20) && GD.inputs.x > (Dashboard[currentDash].g[g].x - 20) 
      && GD.inputs.y < (Dashboard[currentDash].g[g].y + 20) && GD.inputs.y > (Dashboard[currentDash].g[g].y - 20)
      && GD.inputs.x != -32768) {

      Dashboard[currentDash].g[g].move(GD.inputs.x, GD.inputs.y);
      buildMenu();
      Dashboard[currentDash].g[g].write();
      GD.swap();
    }

  } 

}

void parameterEdit(byte g) {

  byte inParameter = true;
  int value = 0;

  while (inParameter) {
    buildMenu();
    //Dashboard[currentDash].g[g].write();


    GD.Tag(BACK_BUTTON);
    GD.cmd_button(395, 235, 80, 30, 28, options,  "Back");

    // left arrow
    GD.Tag(LEFT_BUTTON);
    GD.cmd_button(150, 150, 80, 30, 28, options,  "<");
    // parameter name
    GD.cmd_text(200, 100, 31, options, Dashboard[currentDash].g[g].label);
    // right arrow
    GD.Tag(RIGHT_BUTTON);
    GD.cmd_button(250, 150, 80, 30, 28, options,  ">");

    GD.swap();

    switch(GD.inputs.tag) {
    case BACK_BUTTON:
      inParameter = false; 
      delay(200);
      break;
    case LEFT_BUTTON:
      Dashboard[currentDash].g[g].p--;
      delay(200);
      break;
    case RIGHT_BUTTON:
      Dashboard[currentDash].g[g].p++;
      delay(200);
      break;
    }

  }

}




