#include <ESP8266WiFi.h>
const char* ssid = "ds22";
const char* password = "jaro9597";
int ledStatuses[4] = {0, 0, 0, 0};
int ledPin = 2; // Arduino standard is GPIO13 but lolin nodeMCU is 2 http://www.esp8266.com/viewtopic.php?f=26&t=13410#p61332
WiFiServer server(80);

void setup() 
{
    Serial.begin(115200);
    delay(10);
    pinMode(ledPin, OUTPUT);
    pinMode(5, OUTPUT);
    pinMode(16, OUTPUT);
    pinMode(4, OUTPUT);
    pinMode(0, OUTPUT);
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

    //Low level turns on the led
    //while High level turns it off

    int value = HIGH; //initially off
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
        digitalWrite(4, LOW); //PREPSATPIN
        value = HIGH;
    }
    if (request.indexOf("/LED_CABIN=ON") != -1) {
        ledStatuses[1]=1;
        digitalWrite(4, HIGH); //PREPSATPIN
        value = LOW;
    }
    if (request.indexOf("/LED_POSITION=OFF") != -1) {
        ledStatuses[2]=0;
        digitalWrite(16, LOW); //PREPSATPIN
        digitalWrite(5, LOW); 
        value = HIGH;
    }
    if (request.indexOf("/LED_POSITION=ON") != -1) {
        ledStatuses[2]=1;
        digitalWrite(16, HIGH); //PREPSATPIN
        digitalWrite(5, HIGH); //PREPSATPIN
        value = LOW;
    }
    if (request.indexOf("/LED_SPECIAL=OFF") != -1) {
        ledStatuses[3]=0;
        digitalWrite(ledPin, HIGH); //PREPSATPIN
        value = HIGH;
    }
    if (request.indexOf("/LED_SPECIAL=ON") != -1) {
        ledStatuses[3]=1;
        digitalWrite(ledPin, LOW); //PREPSATPIN
        value = LOW;
    }
    // Set ledPin according to the request
    //digitalWrite(ledPin, value);

    // Return the response
    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: text/html");
    client.println(""); 
    client.println("<!DOCTYPE HTML>");
    client.println("<html>");
    client.println("<head>");
    client.println("<meta charset=\"UTF-8\">"); 
    client.println("<meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
    client.println("<link rel=\"stylesheet\" href=\"https://cdn.jsdelivr.net/gh/openlayers/openlayers.github.io@master/en/v6.15.1/css/ol.css\" type=\"text/css\">");
    client.println("<link rel=\"stylesheet\" href=\"https://raw.githack.com/Thechopsee/REM-Boat/main/style.css\" type=\"text/css\">");
    client.println("<script src=\"https://cdn.jsdelivr.net/gh/openlayers/openlayers.github.io@master/en/v6.15.1/build/ol.js\"></script>");
    client.println("<title>REM-Boat</title>");
    client.println("</head>");
    client.println("<body>");
    client.println("<h1>REM-Boat</h1>");
    client.println("<div class=\"container\">");
    client.println("<div class=\"Box\">");
    client.println("<div class=\"fake-border\">");
    client.println("<div class=\"controll-box\">");
    client.println("<div class=\"textC\">SearchLight");
    if(ledStatuses[0]== 1) 
    {
        client.println("<div class=\"status-dot\" id=\"searchlight-dot\">🟢</div></div>");
    }
    else
    {
        client.println("<div class=\"status-dot\" id=\"searchlight-dot\">🔴</div></div>");
    }
    client.println("<div class=\"button-line\"><a href=\"LED_SEARCH=ON\"><button class=\"on\">On</button></a><a href=\"LED_SEARCH=OFF\"><button class=\"off\">Off</button></a></div>");
    client.println("</div>");
    client.println("<div class=\"controll-box\">");
    client.println("<div class=\"textC\">Cabin");
    if(ledStatuses[1]== 1) 
    {
        client.println("<div class=\"status-dot\" id=\"searchlight-dot\">🟢</div></div>");
    }
    else
    {
        client.println("<div class=\"status-dot\" id=\"searchlight-dot\">🔴</div></div>");
    }
    client.println("<div class=\"button-line\"><a href=\"LED_CABIN=ON\"><button class=\"on\">On</button></a><a href=\"LED_CABIN=OFF\"><button class=\"off\">Off</button></a></div>");
    client.println("</div>");
    client.println("<div class=\"controll-box\">");
    client.println("<div class=\"textC\">Position");
    if(ledStatuses[2]== 1) 
    {
        client.println("<div class=\"status-dot\" id=\"searchlight-dot\">🟢</div></div>");
    }
    else
    {
        client.println("<div class=\"status-dot\" id=\"searchlight-dot\">🔴</div></div>");
    }
    client.println("<div class=\"button-line\"><a href=\"LED_POSITION=ON\"><button class=\"on\">On</button></a><a href=\"LED_POSITION=OFF\"><button class=\"off\">Off</button></a></div>");  
    client.println("</div>");
    client.println("<div class=\"controll-box\">");
    client.println("<div class=\"textC\">Special");
    if(ledStatuses[3]== 1) 
    {
        client.println("<div class=\"status-dot\" id=\"searchlight-dot\">🟢</div></div>");
    }
    else
    {
        client.println("<div class=\"status-dot\" id=\"searchlight-dot\">🔴</div></div>");
    }
    client.println("<div class=\"button-line\"><a href=\"LED_SPECIAL=ON\"><button class=\"on\">On</button></a><a href=\"LED_SPECIAL=OFF\"><button class=\"off\">Off</button></a></div>");
    client.println("</div>");
    client.println("</body>");
    //end

    delay(1);
    Serial.println("Client disonnected");
    Serial.println("");
}
