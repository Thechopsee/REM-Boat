#pragma once
#include "nav_module.hh"
#include <string>
#include <SoftwareSerial.h>
#include <TinyGPSPlus.h>
class NEO6MV2_module :public Nav_module
{
 private:
 const byte rxPin = 14;
 const byte txPin = 12;
 SoftwareSerial gpsSerial;
 TinyGPSPlus gps; 
 public:
 NEO6MV2_module();
 std::string getData();
};
