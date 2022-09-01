#pragma once
#include "nav_module.hh"
#include <string>
#include <SoftwareSerial.h>
#include <TinyGPS.h>
class NEO6MV2_module :public Nav_module
{
 private:
 const byte rxPin = 3;
 const byte txPin = 1;
 SoftwareSerial gpsSerial =SoftwareSerial(rxPin, txPin);
 TinyGPS gps; 
 public:
 NEO6MV2_module();
 std::string getData();
};
