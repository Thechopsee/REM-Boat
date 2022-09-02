#include "NEO6MV2_module.hh"
std::string NEO6MV2_module::getData()
{
    float lat = 28.5458,lon = 77.1703; 
    
    
    if(gps.encode(gpsSerial.read()))// encode gps data
    { 
        lat=gps.location.lat();
        lon=gps.location.lng();
    }

    int year = gps.date.year();
        int month = gps.date.month();
        int day = gps.date.day();

        int hour = gps.time.hour();
        int minute = gps.time.minute();
        int second = gps.time.second();
    
    std::string latitude = std::to_string(hour);
    std::string longitude = std::to_string(minute);
    latitude.append(";");
    latitude.append(longitude);
    Serial.println(latitude.c_str());

    return latitude;
  
}
NEO6MV2_module::NEO6MV2_module()
{
    gpsSerial.begin(9600); // connect gps sensor
}
