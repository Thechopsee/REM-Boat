#include "OLEDDisplayHandler.hh"
OLEDDisplayHandler::OLEDDisplayHandler():display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET)
{
    if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { 
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
    }
    
    return;
}
void OLEDDisplayHandler::setIP(IPAddress ip)
{
    
    this->ip=ip;
}
void OLEDDisplayHandler::showData()
{
    
    
    if(this->ip)
    {
        display.clearDisplay();
        display.display();
        display.setTextSize(1);
        display.setTextColor(WHITE);
        //display.drawPixel(60,52,WHITE);
        String ipconv=this->ip.toString();
        if(ipconv.length()<10)
        {
            display.setCursor(40,42);
            display.println(this->ip);
            display.display();
        }
        else
        {
            //std::string first=ipconv.c_str();
            std::stringstream test(ipconv.c_str());
            std::string segment;
            std::vector<std::string> seglist;

            while(std::getline(test, segment, '.'))
            {
            seglist.push_back(segment);
            }

            display.setCursor(40,32);
            std::string first="";
            first.append(seglist[0]);
            first.append(".");
            first.append(seglist[1]);
            first.append(".");
            display.println(first.c_str());
            display.display();

            display.setCursor(40,42);
            std::string second="";
            second.append(seglist[2]);
            second.append(".");
            second.append(seglist[3]);
            display.println(second.c_str());
            display.display();

            
            display.display();
        }
        
    }
    else
    {
        display.clearDisplay();
        display.display();
        display.setTextSize(1); 
        display.setTextColor(WHITE);
        display.setCursor(35,42);
        display.println("Connecting..");
        display.display();
    }
}