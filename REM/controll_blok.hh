#pragma once
#include "smallBlok.hh"
class Controll_blok: public SmallBlok
{
  public:
    Controll_blok(int id,int blok_id,int pin,char * name);
    void Initialization_pin();
    void setPin(bool dat);

};
