#include "NEO6MV2_module.hh"
std::string NEO6MV2_module::getData()
{
    float lat = 28.5458,lon = 77.1703; 
    
    /*if(gpsSerial.available() > 0)
    {
      if(gps.encode(gpsSerial.read()))// encode gps data
      { 
        if (gps.location.isValid())
        {
          lat=gps.location.lat();
          lon=gps.location.lng();
        }
      }
    }
    */
    
    std::string latitude = std::to_string(lat);
    std::string longitude = std::to_string(lon);
    latitude.append(";");
    latitude.append(longitude);
    Serial.println(latitude.c_str());

    return latitude;
  
}
NEO6MV2_module::NEO6MV2_module()
{
    //gpsSerial.begin(9600); // connect gps sensor
}
