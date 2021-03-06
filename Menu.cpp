#include <EEPROM.h>
#include <SPI.h>
#include <GD2.h>
#include <Arduino.h>
#include "Dash.h"
#include "Menu.h"
#include "Attributes.h"

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
#define CLEAR_BUTTON 153
#define DELETE_BUTTON 154
#define SELECT_BUTTON 155
#define LEFT_BUTTON 156
#define RIGHT_BUTTON 157

extern Dash Dashboard[4];
extern byte currentDash;

byte inMenu = false;

// dims the current dashboard to give the effect of a transparent
// overlay in order to display menu items
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
      delay(500);

      break;
    }
  }

  // save all gauge information when exiting the main menu
  for(byte i = 0; i < 8; i++)
    Dashboard[currentDash].g[i].save(i);
}

// menu for creating a new gauge
void menuCreate() {

  delay(200);

  byte inCreate = true;

  while(inMenu && inCreate) {

    buildMenu();

    GD.Tag(ANALOG_CREATE);
    GD.cmd_button(5, 5, 140, 30, 28, options,  "Analog");

    GD.Tag(DIGITAL_CREATE);
    GD.cmd_button(5, 40, 140, 30, 28, options,  "Digital");

    GD.Tag(BARGRAPH_CREATE);
    GD.cmd_button(5, 75, 140, 30, 28, options,  "Bargraph");

    // GD.Tag(INDICATOR_CREATE);
    // GD.cmd_button(5, 110, 140, 30, 28, options,  "Indicator");

    GD.Tag(BACK_BUTTON);
    GD.cmd_button(310, 235, 80, 30, 28, options,  "Back");

    GD.Tag(EXIT_BUTTON);
    GD.cmd_button(395, 235, 80, 30, 28, options,  "Eit");

    GD.swap();

    switch(GD.inputs.tag) {
    case ANALOG_CREATE:
      Dashboard[currentDash].addGauge(0);
      inCreate = false;
      delay(200);
      break;
    case DIGITAL_CREATE:
      Dashboard[currentDash].addGauge(1);
      inCreate = false;
      delay(200);
      break;
    case BARGRAPH_CREATE:
      Dashboard[currentDash].addGauge(2);
      inCreate = false;
      delay(200);
      break;
    case INDICATOR_CREATE:
      //Dashboard[currentDash].addGauge(0);
      break;
    case BACK_BUTTON:
      inCreate = false;
      break;
    case EXIT_BUTTON:
      inMenu = false;
      delay(500);

      break;
    }
  } 
}

// allows user to change the parameter, size, and location of each gauge
// user taps the desired gauge and can modify the settings accordingly
void menuEdit() {

  delay(200);

  byte inEdit = true;
  byte editGauge = false;
  byte selectedGauge = 1;

  while(inMenu && inEdit) {

    // highlight the selected gauge
    buildMenu();
    if (Dashboard[currentDash].g[selectedGauge-1].settings.active)
      Dashboard[currentDash].g[selectedGauge-1].write();

    if(GD.inputs.tag > 0 && GD.inputs.tag < 9 && !editGauge)
      selectedGauge = GD.inputs.tag;

    GD.Tag(BACK_BUTTON);
    GD.cmd_button(310, 235, 80, 30, 28, options,  "Back");

    GD.Tag(EXIT_BUTTON);
    GD.cmd_button(395, 235, 80, 30, 28, options,  "Exit");

    GD.Tag(CLEAR_BUTTON);
    GD.cmd_button(10,235,80,30,28,options, "Clear");

    if (editGauge) {
      GD.Tag(POSITION_EDIT);
      GD.cmd_button(5, 5, 140, 30, 28, options,  "Position");

      GD.Tag(SIZE_EDIT);
      GD.cmd_button(5, 40, 140, 30, 28, options,  "Size");

      GD.Tag(PARAMETER_EDIT);
      GD.cmd_button(5, 75, 140, 30, 28, options,  "Parameter");

      GD.Tag(DELETE_BUTTON);
      GD.cmd_button(5, 110, 140, 30, 28, options,  "Delete");
    } 
    else {
      GD.Tag(SELECT_BUTTON);
      GD.cmd_button(205, 235, 100, 30, 28, options,  "Select");
    }

    GD.swap();

    // choose the correct setting to change based on user touch input
    switch(GD.inputs.tag) {
    case POSITION_EDIT:
      moveEdit(selectedGauge-1);
      break;
    case SIZE_EDIT:
      break;
    case PARAMETER_EDIT:
      parameterEdit(selectedGauge-1);
      break;
    case DELETE_BUTTON:
      Dashboard[currentDash].g[selectedGauge-1].settings.active = false;
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
    case CLEAR_BUTTON:
      Dashboard[currentDash].clear();
      break;
    case EXIT_BUTTON:
      inMenu = false;
      delay(500);

      break;
    }
  } 
}

// function that allows the user to drag the selected gauge on screen
// and automatically update the position data of the gauge
void moveEdit(byte g) {

  delay(200);

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

    while(GD.inputs.x < (Dashboard[currentDash].g[g].settings.x + 20) && GD.inputs.x > (Dashboard[currentDash].g[g].settings.x - 20) 
      && GD.inputs.y < (Dashboard[currentDash].g[g].settings.y + 20) && GD.inputs.y > (Dashboard[currentDash].g[g].settings.y - 20)
      && GD.inputs.x != -32768) {

      Dashboard[currentDash].g[g].move(GD.inputs.x, GD.inputs.y);
      buildMenu();
      Dashboard[currentDash].g[g].write();
      GD.swap();
    }

  } 

}

// allows the user to change which parameter the gauge displays using
// directional arrows.
void parameterEdit(byte g) {

  delay(200);

  byte inParameter = true;

  while (inParameter) {
    buildMenu();

    GD.Tag(BACK_BUTTON);
    GD.cmd_button(395, 235, 80, 30, 28, options,  "Back");

    // left arrow
    GD.Tag(LEFT_BUTTON);
    GD.cmd_button(150, 150, 80, 30, 28, options,  "<");
    // parameter name
    GD.cmd_text(200, 100, 31, options, Dashboard[currentDash].g[g].getName());
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
      Dashboard[currentDash].g[g].settings.p = (Dashboard[currentDash].g[g].settings.p == 0) ? 0 : Dashboard[currentDash].g[g].settings.p - 1;

      delay(200);
      break;
    case RIGHT_BUTTON:
      Dashboard[currentDash].g[g].settings.p = (Dashboard[currentDash].g[g].settings.p > 38) ? 0 : Dashboard[currentDash].g[g].settings.p + 1;

      delay(200);
      break;
    }

  }

}









