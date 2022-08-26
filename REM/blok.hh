#pragma once
#include <string>
#include "typeEnum.hh"
class Blok {       
  public:            
    BlokTypeEnum type;
    int id;
    Blok(int id,BlokTypeEnum type);     
};
