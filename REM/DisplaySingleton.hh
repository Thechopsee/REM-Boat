#pragma once
#include "DisplayToken.hh"
#include "CircularBuffer.hh"
#include "OLEDDisplayHandler.hh"
#include <vector>


class DisplaySingleton{
  private:
    OLEDDisplayHandler * handler;
    CircularBuffer * buffer;
    static DisplaySingleton* singleton;
    DisplaySingleton();
    public:
    static  DisplaySingleton* returnInstance();
    void Add(std::string textt,int lifetime);   
    void AddIp(IPAddress ip);
    void Tick();
    
   

};

