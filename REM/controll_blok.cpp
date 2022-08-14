#include "controll_blok.hh"
#include "Arduino.h"
Controll_blok::Controll_blok(int id,int blok_id,int pin,char * name)
{
    this->id;
    this->blok_id;
    this->pin;
    this->name=name;
    this->Initialization_pin();
}
void Controll_blok::Initialization_pin()
{
    pinMode(this->pin, OUTPUT);
}
