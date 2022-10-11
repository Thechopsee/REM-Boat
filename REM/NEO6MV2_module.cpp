#include "NEO6MV2_module.hh"
#include "SoftwareSerial.h"
std::string NEO6MV2_module::getData()
{
    
    float lat = 28.5458,lon = 77.1703; 
    
    if(gpsSerial.available() > 0)
    {
      Serial.println("avaible");
      Serial.println(gps.encode(gpsSerial.read()));// encode gps data
       
        Serial.println("read");
        gps.location.isValid();
        
          Serial.println("valid");
          lat=gps.location.lat();
          lon=gps.location.lng();
        
      
    }
    
    
    std::string latitude = std::to_string(lat);
    std::string longitude = std::to_string(lon);
    latitude.append(";");
    latitude.append(longitude);
    Serial.println(latitude.c_str());

    return latitude;
  
}
NEO6MV2_module::NEO6MV2_module()
{
  
     gpsSerial.begin(4800);
    
     // connect gps sensor
}
