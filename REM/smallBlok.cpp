#include "smallBlok.hh"

SmallBlok::SmallBlok(int id,int blok_id,int pin,char *name,BlokTypeEnum type)
{
    this->id=id;
    this->blok_id=blok_id;
    this->pin=pin;
    this->name=name;
}

void SmallBlok::setPin(bool dat)
{
  return;
}

void SmallBlok::update()
{
  return;
}

void SmallBlok::resolveInput(String request)
{
  return;
}
