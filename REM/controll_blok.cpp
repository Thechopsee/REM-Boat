#include "controll_blok.hh"
#include "Arduino.h"
Controll_blok::Controll_blok(int id,int blok_id,int pin,char * namee)
{
    this->id=id;
    this->blok_id=blok_id;
    this->pin=pin;
    this->name=namee;
    this->actual_status=false;
    this->Initialization_pin();
}
void Controll_blok::Initialization_pin()
{
    pinMode(this->pin, OUTPUT);
}
void Controll_blok::setPin(bool dat)
{
    if(dat)
    {
        digitalWrite(this->pin, HIGH);
        this->actual_status=true;
    }
    else
    {
        digitalWrite(this->pin, LOW);
        this->actual_status=false;
    }
}
