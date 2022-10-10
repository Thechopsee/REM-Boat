#pragma once
#include "nav_module.hh"
#include <string>
#include <SoftwareSerial.h>
#include <TinyGPSPlus.h>
class NEO6MV2_module :public Nav_module
{
 private:
 const byte rxPin = 5;
 const byte txPin = 4;
 SoftwareSerial gpsSerial =SoftwareSerial(rxPin, txPin);
 TinyGPSPlus gps; 
 public:
 NEO6MV2_module();
 std::string getData();
};
