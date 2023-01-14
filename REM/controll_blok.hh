#pragma once
#include "smallBlok.hh"
#include "Arduino.h"
#include "DisplaySingleton.hh"
#include "typeEnum.hh"
#include <string>

class Controll_blok: public SmallBlok
{
  public:
    ControllBlokTypeEnum type; 
    Controll_blok(int id,int blok_id,int pin,char * namee,ControllBlokTypeEnum type);
    void Initialization_pin();
    void setPin(bool dat);
    void resolveInput(String request);
    void updatePin(int value);
    ControllBlokTypeEnum identify();
};
