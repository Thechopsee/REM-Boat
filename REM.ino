#include <ESP8266WiFi.h>
const char* ssid = "testing";
const char* password = "slunicko";
int ledStatuses[4] = {0, 0, 0, 0};
int ledPin = 2; // Arduino standard is GPIO13 but lolin nodeMCU is 2 http://www.esp8266.com/viewtopic.php?f=26&t=13410#p61332
WiFiServer server(80);

void setup() 
{
    Serial.begin(115200);
    delay(10);
    pinMode(ledPin, OUTPUT);
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
    if (request.indexOf("/LED_SEARCH==OFF") != -1) {
        ledStatuses[0]=0;
        digitalWrite(ledPin, HIGH);
        value = HIGH;
    }
    if (request.indexOf("/LED_SEARCH=ON") != -1) {
        ledStatuses[0]=1;
        digitalWrite(ledPin, LOW);
        value = LOW;
    }
    if (request.indexOf("/LED_CABIN=OFF") != -1) {
        ledStatuses[1]=0;
        digitalWrite(ledPin, HIGH); //PREPSATPIN
        value = HIGH;
    }
    if (request.indexOf("/LED_CABIN=ON") != -1) {
        ledStatuses[1]=1;
        digitalWrite(ledPin, LOW); //PREPSATPIN
        value = LOW;
    }
    if (request.indexOf("/LED_POSITION=OFF") != -1) {
        ledStatuses[2]=0;
        digitalWrite(ledPin, HIGH); //PREPSATPIN
        value = HIGH;
    }
    if (request.indexOf("/LED_POSITION=ON") != -1) {
        ledStatuses[2]=1;
        digitalWrite(ledPin, LOW); //PREPSATPIN
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
    client.println("<meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
    client.println("<link rel=\"stylesheet\" href=\"https://cdn.jsdelivr.net/gh/openlayers/openlayers.github.io@master/en/v6.15.1/css/ol.css\" type=\"text/css\">");
    //end
    client.println("<style>p.padding{padding-left: 0.4cm;}p{color: black;}cred{color: red}cgreen{color: green}</style>");

    client.print("<br><p class=\"padding\">On-Board Led is now : ");
    //High=off
    //Low=on

    if(value == HIGH) 
    {
        client.print("<cred>Off</cred>");
    } 
    else 
    {
        client.print("<cgreen>On<cgreen></p>");
    }
    client.println("<div class=\"w3-container\">");
    client.println("<br>");
    client.println("<a href=\"/LED=ON\"\"><button class=\"w3-btn w3-ripple w3-green\">Turn On </button></a>");
    client.println("<a href=\"/LED=OFF\"\"><button class=\"w3-btn w3-ripple w3-red\">Turn Off </button></a><br />");
    client.println("</div>");
    client.println("</html>");

    delay(1);
    Serial.println("Client disonnected");
    Serial.println("");
}