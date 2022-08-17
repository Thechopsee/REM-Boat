#include "renderer.hh"
#include <string>
void Renderer::drawBlok(Blok *bl,std::vector<Controll_blok*> cb,WiFiClient client)
{
  client.println("<div class=\"Box\">");
  client.println("<div class=\"fake-border\">");
  for(int i=0;i<cb.size();i++)
  {
    this->drawControllBlok(cb[i],client);
  }
  client.println("</div>");
  client.println("</div>");
}

void Renderer::drawControllBlok(Controll_blok* cb,WiFiClient client)
{
    client.println("<div class=\"controll-box\">");
    std::string namee="<div class=\"textC\">";
    namee.append(cb->name);
    client.println(namee.c_str()); 
    if(cb->actual_status) 
    {
        client.println("<div class=\"status-dot\">🟢</div></div>");
    }
    else
    {
        client.println("<div class=\"status-dot\">🔴</div></div>");
    }
    std::string buttons="<div class=\"button-line\"><a href=\"";
    buttons.append(cb->name);
    buttons.append("=ON\"><button class=\"on\">On</button></a><a href=\"");
    buttons.append(cb->name);
    buttons.append("=OFF\"><button class=\"off\">Off</button></a></div>");
    client.println(buttons.c_str()); 
    //client.println("<div class=\"button-line\"><a href=\"LED_SEARCH=ON\"><button class=\"on\">On</button></a><a href=\"LED_SEARCH=OFF\"><button class=\"off\">Off</button></a></div>");
    client.println("</div>");
}

void Renderer::drawHeader(WiFiClient client)
{
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
}
