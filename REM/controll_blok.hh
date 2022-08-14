#pragma once
class Controll_blok
{
  public:
    int id;
    int blok_id;
    int pin;
    char *name;
    Controll_blok(int id,int blok_id,int pin,char * name);
    void Initialization_pin();

};
