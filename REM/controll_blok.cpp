#include "controll_blok.hh"

Controll_blok::Controll_blok(int id,int blok_id,int pin,char * namee,BlokTypeEnum type) : SmallBlok(id,blok_id,pin,namee,type)
{
    this->actual_status="🔴";
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
void Controll_blok::update()
{
    int value=current_value;
    if(value!=0)
    {
        this->actual_status="🟢";
    }
    else
    {
        this->actual_status="🔴";
    }
    
    digitalWrite(this->pin,value);
}
void Controll_blok::resolveInput(String request)
{
        std::string nameoff="/";
        nameoff.append(this->name);
        nameoff.append("=OFF");
        
        std::string nameon="/";
        nameon.append(this->name);
        nameon.append("=ON");
        
        DisplaySingleton *neco=DisplaySingleton::returnInstance();
        if(request.indexOf(nameoff.c_str())!=-1)
        {
            this->setPin(false);
            neco->Add(nameoff,5);
        }
        if(request.indexOf(nameon.c_str())!=-1)
        {
            this->setPin(true);
            neco->Add(nameon,5);
            
        }/*
        if(request.indexOf(namerange.c_str())!=-1)
        {
            std::stringstream ss(request.c_str());
            std::string world;
            getline(ss,world,'=');
            getline(ss,world,'=');
            std::string hodnota=world;
            current_value=std::stoi(hodnota.c_str());
            this->update();
            Serial.println("rangezmena");
            Serial.println(hodnota.c_str());
            neco->Add(nameon,5);
            
        }*/
}
int Controll_blok::getValue()
{
  return this->current_value;
}
BlokTypeEnum Controll_blok::identify()
{
    return this->type;
}
