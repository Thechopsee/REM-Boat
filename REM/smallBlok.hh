#pragma once
#include <string>
#include "smallBlok.hh"

class SmallBlok 
{
  public:
    int id;
    int blok_id;
    int pin;
    char *name;
    std::string actual_status;
    SmallBlok(int id,int blok_id,int pin,char *name);
};
