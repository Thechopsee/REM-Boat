#include "controll_blok.hh"
#include "Arduino.h"
Controll_blok::Controll_blok(int id,int blok_id,int pin,char * namee) : SmallBlok(id,blok_id,pin,namee)
{
    this->actual_status="🔴";
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
        this->actual_status="🟢";
    }
    else
    {
        digitalWrite(this->pin, LOW);
        this->actual_status="🔴";
    }
}
void Controll_blok::resolveInput(String request)
{
        std::string nameoff="/";
        nameoff.append(this->name);
        nameoff.append("=OFF");
        Serial.println(nameoff.c_str());
        std::string nameon="/";
        nameon.append(this->name);
        nameon.append("=ON");
        Serial.println(nameon.c_str());
        
        if(request.indexOf(nameoff.c_str())!=-1)
        {
            this->setPin(false);
        }
        if(request.indexOf(nameon.c_str())!=-1)
        {
            this->setPin(true);
        }
}