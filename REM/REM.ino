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
#include "hc-sr04_module.hh"

#include "NEO6MV2_module.hh"



const char* ssid = "Na doma-2GHz";
const char* password = "slunicko";

WiFiServer server(80);
std::vector<Blok*> blocks;
std::vector<SmallBlok*> contBlocks;
Renderer *rd;


void setup() 
{
  

 rd=new Renderer();
 blocks.push_back(new Blok(0,controll));
 blocks.push_back(new Blok(2,status));
 blocks.push_back((Blok*)new Nav_blok(1));
 //contBlocks.push_back(new Controll_blok(0,0,0,"WTF"));
 //contBlocks.push_back(new Controll_blok(1,0,5,"Cabin"));
 //contBlocks.push_back(new Controll_blok(2,0,4,"Position"));
 //contBlocks.push_back(new Controll_blok(3,0,2,"Special"));

//Hcsr04Module* vzdal=new Hcsr04Module(15,13);
//contBlocks.push_back(new Status_blok(4,2,0,"Temp",vzdal));
//contBlocks.push_back(new Status_blok(5,2,0,"vzdalenost",vzdal));


  Serial.begin(9600);
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
    Serial.println("NEW request");
    
    String request = client.readStringUntil('r');
    Serial.println(request);
    client.flush();

    for(int i=0;i<contBlocks.size();i++)
    {
       contBlocks[i]->resolveInput(request);
    }

    rd->drawHeader(client);
    for(int i=0;i<blocks.size();i++)
    {
      rd->drawBlok(blocks[i],contBlocks,client);
    }
    
    client.println("</body>");
      

    delay(1);
    Serial.println("Client disonnected");
    Serial.println("");
}
