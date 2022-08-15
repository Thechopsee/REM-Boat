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
    client.println("<div class=\"button-line\"><a href=\"LED_SEARCH=ON\"><button class=\"on\">On</button></a><a href=\"LED_SEARCH=OFF\"><button class=\"off\">Off</button></a></div>");
    client.println("</div>");
}
