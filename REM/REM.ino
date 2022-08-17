#include <ESP8266WiFi.h>
#include <Ethernet.h>
#include <vector>
#include <string>
#include "blok.hh"
#include "controll_blok.hh"
#include "renderer.hh"

const char* ssid = "Na doma-2GHz";
const char* password = "slunicko";

WiFiServer server(80);
std::vector<Blok*> blocks;
std::vector<Controll_blok*> contBlocks;
Renderer *rd;
void setup() 
{
  rd=new Renderer();
  blocks.push_back(new Blok(0));
  contBlocks.push_back(new Controll_blok(0,0,0,"Searchlight"));
  contBlocks.push_back(new Controll_blok(1,0,5,"Cabin"));
  contBlocks.push_back(new Controll_blok(2,0,4,"Position"));
  contBlocks.push_back(new Controll_blok(3,0,2,"Special"));

  Serial.begin(115200);
    delay(10);
    digitalWrite(ledPin, HIGH);

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
        name.append(contBlocks[i]->name);
        name.append("=OFF");
        std::string nameon="/";
        name.append(contBlocks[i]->name);
        name.append("=ON");
        if(request.indexOf(nameoff.c_str())!=-1)
        {
            contBlocks[i]->setPin(false);
        }
        if(request.indexOf(nameon.c_str())!=-1)
        {
            contBlocks[i]->setPin(true);
        }
    }

    /*
    if (request.indexOf("/LED_SEARCH=OFF") != -1) {
        ledStatuses[0]=0;
        digitalWrite(0, LOW);
        value = HIGH;
    }
    if (request.indexOf("/LED_SEARCH=ON") != -1) {
        ledStatuses[0]=1;
        digitalWrite(0, HIGH);
        value = LOW;
    }
    if (request.indexOf("/LED_CABIN=OFF") != -1) {
        ledStatuses[1]=0;
        digitalWrite(5, LOW); 
        value = HIGH;
    }
    if (request.indexOf("/LED_CABIN=ON") != -1) {
        ledStatuses[1]=1;
        digitalWrite(5, HIGH); 
        value = LOW;
    }
    if (request.indexOf("/LED_POSITION=OFF") != -1) {
        ledStatuses[2]=0;
        digitalWrite(4, LOW); 
        digitalWrite(16, LOW); 
        value = HIGH;
    }
    if (request.indexOf("/LED_POSITION=ON") != -1) {
        ledStatuses[2]=1;
        digitalWrite(4, HIGH); 
        digitalWrite(16, HIGH); 
        value = LOW;
    }
    if (request.indexOf("/LED_SPECIAL=OFF") != -1) {
        ledStatuses[3]=0;
        digitalWrite(ledPin, HIGH); 
        value = HIGH;
    }
    if (request.indexOf("/LED_SPECIAL=ON") != -1) {
        ledStatuses[3]=1;
        digitalWrite(ledPin, LOW); 
        value = LOW;
    }
    */

    // Render page
    rd->drawHeader()
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
