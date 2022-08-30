#include <ESP8266WiFi.h>
#include <Ethernet.h>
#include <vector>
#include <string>
#include "blok.hh"
#include "controll_blok.hh"
#include "status_blok.hh"
#include "nav_blok.hh"
#include "renderer.hh"
#include "typeEnum.hh"

const char* ssid = "ds22";
const char* password = "jaro9597";

WiFiServer server(80);
std::vector<Blok*> blocks;
std::vector<SmallBlok*> contBlocks;
Nav_blok* navBlock;
Renderer *rd;
void setup() 
{
  rd=new Renderer();
  blocks.push_back(new Blok(0,controll));
  blocks.push_back(new Blok(2,status));
  blocks.push_back((Blok*)new Nav_blok(1));
  contBlocks.push_back(new Controll_blok(0,0,0,"WTF"));
  contBlocks.push_back(new Controll_blok(1,0,5,"Cabin"));
  contBlocks.push_back(new Controll_blok(2,0,4,"Position"));
  contBlocks.push_back(new Controll_blok(3,0,2,"Special"));
  contBlocks.push_back(new Status_blok(4,2,0,"Temp"));
  contBlocks.push_back(new Status_blok(5,2,0,"Voltage"));

  Serial.begin(115200);
    delay(10);
    

    Serial.println();
    Serial.print("Connecting to ");
    Serial.println(ssid);

    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED) 
    {
        delay(500);
        Serial.print(".");
    }
    Serial.println("");
    Serial.println("WiFi connected");

    // Start the server
    server.begin();
    Serial.println("Server started");

    // Print the IP address
    Serial.print("URL to connect: ");
    Serial.print("http://");
    Serial.print(WiFi.localIP());
    Serial.println("/");

}

void loop() 
{
    WiFiClient client = server.available();
    if (!client) 
    {
        return;
    }

    Serial.println("new data in");
    while(!client.available())
    {
        delay(1);
    }

    // Read the first line of the request
    String request = client.readStringUntil('r');
    Serial.println(request);
    client.flush();

    for(int i=0;i<contBlocks.size();i++)
    {
        std::string nameoff="/";
        nameoff.append(contBlocks[i]->name);
        
        nameoff.append("=OFF");
        Serial.println(nameoff.c_str());
        std::string nameon="/";
        nameon.append(contBlocks[i]->name);
        nameon.append("=ON");
        Serial.println(nameon.c_str());
        
        if(request.indexOf(nameoff.c_str())!=-1)
        {
            contBlocks[i]->setPin(false);
        }
        if(request.indexOf(nameon.c_str())!=-1)
        {
            contBlocks[i]->setPin(true);
        }
    }

    // Render page
    rd->drawHeader(client);
    for(int i=0;i<blocks.size();i++)
    {
      rd->drawBlok(blocks[i],contBlocks,client);
    }
    
    client.println("</body>");
      
    //end

    delay(1);
    Serial.println("Client disonnected");
    Serial.println("");
}
