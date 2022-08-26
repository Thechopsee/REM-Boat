#pragma once
#include "controll_blok.hh"
#include <vector>
#include <ESP8266WiFi.h>
#include "blok.hh"
#include "typeEnum.hh"
class Renderer
{
  public:
    void drawBlok(Blok *bl,std::vector<Controll_blok*> cb,WiFiClient client);
    void drawHeader(WiFiClient client);
    void drawOLMJS(WiFiClient client);
  private:
    void drawSmallBlok(SmallBlok* cb,WiFiClient client);
};
