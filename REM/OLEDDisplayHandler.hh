#pragma once
#include <iostream>
#include <string>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "Ethernet.h"
#include <vector>
#include <sstream>


#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels


#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)

class OLEDDisplayHandler{
    private:
    IPAddress ip;
    Adafruit_SSD1306 display;
    public:
    OLEDDisplayHandler();
    void setIP(IPAddress ip);
    void showData();
    void showText(std::string text);
};