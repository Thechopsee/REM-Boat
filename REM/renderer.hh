#pragma once
#include "smallBlok.hh"
#include <vector>
#include <ESP8266WiFi.h>
#include "blok.hh"
#include "typeEnum.hh"
#include "nav_blok.hh"
#include "RenderStrategy.hh"
class Renderer
{
  public:
    void drawBlok(Blok *bl,std::vector<SmallBlok*> cb,WiFiClient client);
    void drawHeader(WiFiClient client);
    void drawOLMJS(WiFiClient client);
    RenderStrategy* strategy=nullptr;
    void drawNew(std::vector<Blok *>bl,std::vector<SmallBlok*> cb,WiFiClient client);
  private:
    
    void drawSmallBlok(SmallBlok* cb,WiFiClient client,BlokTypeEnum type);
};
