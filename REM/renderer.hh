#pragma once
#include "controll_blok.hh"
#include <vector>
#include <ESP8266WiFi.h>
#include "blok.hh"
class Renderer
{
  public:
    void drawBlok(Blok *bl,std::vector<Controll_blok*> cb,WiFiClient client);
  private:
    void drawControllBlok(Controll_blok* cb,WiFiClient client);
};
