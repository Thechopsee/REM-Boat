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

//#include <U8g2lib.h>
//#include <SPI.h>
//#include <Wire.h>

//U8G2_SSD1306_72X40_ER_1_HW_I2C u8g2(U8G2_R0,4,5);
//U8GLIB_SSD1306_70X40 mujOled(U8G_I2C_OPT_NONE);
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels


#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

const char* ssid = "Na doma-2GHz";
const char* password = "slunicko";

WiFiServer server(80);
std::vector<Blok*> blocks;
std::vector<SmallBlok*> contBlocks;
Renderer *rd;
void testdrawline() {
  int16_t i;

  display.clearDisplay(); // Clear display buffer

  for(i=0; i<display.width(); i+=4) {
    display.drawLine(0, 0, i, display.height()-1, WHITE);
    display.display(); // Update screen with each newly-drawn line
    delay(1);
  }
  for(i=0; i<display.height(); i+=4) {
    display.drawLine(0, 0, display.width()-1, i, WHITE);
    display.display();
    delay(1);
  }
  delay(250);

  display.clearDisplay();

  for(i=0; i<display.width(); i+=4) {
    display.drawLine(0, display.height()-1, i, 0, WHITE);
    display.display();
    delay(1);
  }
  for(i=display.height()-1; i>=0; i-=4) {
    display.drawLine(0, display.height()-1, display.width()-1, i, WHITE);
    display.display();
    delay(1);
  }
  delay(250);

  display.clearDisplay();

  for(i=display.width()-1; i>=0; i-=4) {
    display.drawLine(display.width()-1, display.height()-1, i, 0, WHITE);
    display.display();
    delay(1);
  }
  for(i=display.height()-1; i>=0; i-=4) {
    display.drawLine(display.width()-1, display.height()-1, 0, i, WHITE);
    display.display();
    delay(1);
  }
  delay(250);

  display.clearDisplay();

  for(i=0; i<display.height(); i+=4) {
    display.drawLine(display.width()-1, 0, 0, i, WHITE);
    display.display();
    delay(1);
  }
  for(i=0; i<display.width(); i+=4) {
    display.drawLine(display.width()-1, 0, i, display.height()-1, WHITE);
    display.display();
    delay(1);
  }

  delay(2000); // Pause for 2 seconds
}


void setup() 
{
 if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { 
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }

  display.display();
  delay(2000); // Pause for 2 seconds

  //testdrawline();
  display.display();
  // Draw a single pixel in white
  display.clearDisplay();
  display.display();
  display.setTextSize(8); // set the font size, supports sizes from 1 to 8
  display.setCursor(60,0);
  display.print("a");
  display.display();
  
 rd=new Renderer();
 blocks.push_back(new Blok(0,controll));
 blocks.push_back(new Blok(2,status));
 blocks.push_back((Blok*)new Nav_blok(1));
 
contBlocks.push_back(new Controll_blok(0,0,0,"WTF"));
contBlocks.push_back(new Controll_blok(1,0,5,"Cabin"));
contBlocks.push_back(new Controll_blok(2,0,4,"Position"));
contBlocks.push_back(new Controll_blok(3,0,2,"Special"));

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
    rd->drawNew(blocks,contBlocks,client);
    /*
    rd->drawHeader(client);
    for(int i=0;i<blocks.size();i++)
    {
      rd->drawBlok(blocks[i],contBlocks,client);
    }
    */
    //
    

    delay(1);
    Serial.println("Client disonnected");
    Serial.println("");
}
