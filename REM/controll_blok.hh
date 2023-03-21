#pragma once
#include "smallBlok.hh"
#include "Arduino.h"
#include "DisplaySingleton.hh"

class Controll_blok: public SmallBlok
{
  public:
<<<<<<< Updated upstream
    Controll_blok(int id,int blok_id,int pin,char * namee);
    void Initialization_pin();
    void setPin(bool dat);
    void resolveInput(String request);

=======
    Controll_blok(int id,int blok_id,int pin,char * namee,ControllBlokTypeEnum type);
    void setPin(bool dat);
    void resolveInput(String request);
    void update();
    int getValue();
    ControllBlokTypeEnum identify();
    
>>>>>>> Stashed changes
};
