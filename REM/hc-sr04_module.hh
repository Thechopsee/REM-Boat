#pragma once
#include "rxtxmodule.hh"
#include <Arduino.h>
#include <string>
class Hcsr04Module : public RxTxModule
{
    long duration;
    int distance; 
    public:
    std::string GetStatus();
    Hcsr04Module(int rxpin,int txpin);
    void initPin();

};
