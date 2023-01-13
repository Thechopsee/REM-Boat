#pragma once
//
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

#include "DisplaySingleton.hh"
const char* ssid = "Na doma-2GHz";
const char* password = "slunicko";
//const char* ssid = "ds22";
//const char* password = "jaro9597";


WiFiServer server(80);
std::vector<Blok*> blocks;
std::vector<SmallBlok*> contBlocks;
Renderer *rd;
//DisplaySingleton * neco;

void setup() 
{

 //neco=DisplaySingleton::returnInstance();
 //neco->Add("init",2);
 //neco->Tick();
 rd=new Renderer();
 blocks.push_back(new Blok(0,controll));
 blocks.push_back(new Blok(2,controll));
 blocks.push_back((Blok*)new Nav_blok(1));
 
contBlocks.push_back(new Controll_blok(0,0,16,"Kabina"));
contBlocks.push_back(new Controll_blok(1,0,0,"Paluba"));
contBlocks.push_back(new Controll_blok(2,0,2,"ServisniSvetla"));

contBlocks.push_back(new Controll_blok(3,2,14,"Lano"));
contBlocks.push_back(new Controll_blok(4,2,12,"Otoceni"));
contBlocks.push_back(new Controll_blok(5,2,13,"Zvedani"));
contBlocks.push_back(new Controll_blok(6,2,15,"osvetleni"));

/*Hcsr04Module* vzdal=new Hcsr04Module(15,13);
contBlocks.push_back(new Status_blok(4,2,0,"Temp",vzdal));
contBlocks.push_back(new Status_blok(5,2,0,"vzdalenost",vzdal));*/
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
    WiFi.setAutoReconnect(true);
    WiFi.persistent(true);

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
    //neco->AddIp(WiFi.localIP());

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
    //ignoring favicon request not pernament solution
    if (request[5]=='f')
    {
        return;  
    }
    //neco->Tick();
    Serial.println(request);
    
    client.flush();

    for(int i=0;i<contBlocks.size();i++)
    {
       contBlocks[i]->resolveInput(request);
    }
    rd->drawNew(blocks,contBlocks,client);

    delay(1);
    Serial.println("Client disonnected");
    Serial.println("");
}
