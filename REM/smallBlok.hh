#pragma once
#include <string>
#include "smallBlok.hh"
#include "Arduino.h"
#include "typeEnum.hh"
class SmallBlok 
{
  public:
    int id;
    int blok_id;
    int pin;
    char *name;
    BlokTypeEnum type;
    std::string actual_status;
    SmallBlok(int id,int blok_id,int pin,char *name,BlokTypeEnum type);
    virtual void setPin(bool dat);
    virtual void update();
    virtual void resolveInput(String request);
    
};
