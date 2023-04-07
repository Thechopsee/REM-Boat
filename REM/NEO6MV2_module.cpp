/*#include "NEO6MV2_module.hh"
TinyGPSPlus gps;
std::string NEO6MV2_module::getData()
{
    
    float lon = last_lon; 
    float lat = last_lat; 
    
    
    while(gpsSerial.available() > 0)
    {
      
      
      //Serial.println(gpsSerial->overflow());
      //Serial.println(gpsSerial->read());
      if(gps.encode(gpsSerial.read()))
      {
        
       Serial.println("encoded");
         
       if(gps.location.isValid())
       {
            Serial.println("valid");
            lat=gps.location.lat();
            lon=gps.location.lng();
            

            last_lon=lon;
            last_lat=lat;
       }
       if (gps.date.isValid())
       {
        Serial.println("date");
        }
      
      }
    }
    
    
    std::string latitude = std::to_string(lat);
    std::string longitude = std::to_string(lon);
    latitude.append(";");
    latitude.append(longitude);
    Serial.println(latitude.c_str());

    return latitude;
  
}
NEO6MV2_module::NEO6MV2_module():gpsSerial(2,0)
{
     
     gpsSerial.begin(9600);
     return;

}*/
