#pragma once
#include "smallBlok.hh"
#include "Arduino.h"
#include "DisplaySingleton.hh"

class Controll_blok: public SmallBlok
{
  public:
    Controll_blok(int id,int blok_id,int pin,char * namee);
    void Initialization_pin();
    void setPin(bool dat);
    void resolveInput(String request);

};
