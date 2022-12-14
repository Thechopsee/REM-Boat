#pragma once
#include <string>
#include "smallBlok.hh"
#include "Arduino.h"
class SmallBlok 
{
  public:
    int id;
    int blok_id;
    int pin;
    char *name;
    std::string actual_status;
    SmallBlok(int id,int blok_id,int pin,char *name);
    virtual void setPin(bool dat);
    virtual void update();
    virtual void resolveInput(String request);
};
