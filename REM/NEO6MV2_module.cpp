#include "NEO6MV2_module.hh"
std::string NEO6MV2_module::getData()
{
    float lat = 28.5458,lon = 77.1703; 
    
    
    if(gps.encode(gpsSerial.read()))// encode gps data
    { 
        gps.f_get_position(&lat,&lon); // get latitude and longitude
    }
    
    std::string latitude = std::string(lat,6);
    std::string longitude = std::string(lon,6);
    latitude.append(";");
    latitude.append(longitude);
    Serial.println(latitude.c_str());

    return latitude;
  
}
NEO6MV2_module::NEO6MV2_module()
{
    gpsSerial.begin(9600); // connect gps sensor
}
