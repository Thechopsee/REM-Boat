/*#pragma once
#include "nav_module.hh"
#include <string>
#include <SoftwareSerial.h>
#include <TinyGPS++.h>

class NEO6MV2_module :public Nav_module
{
 private:
 const byte rxPin = 4;
 const byte txPin = 5;
 float last_lon = 77.1703; 
 float last_lat = 28.5458; 
  
 public:
 SoftwareSerial gpsSerial;
 NEO6MV2_module();
 std::string getData();
};*/
