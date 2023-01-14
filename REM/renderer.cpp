#include "renderer.hh"
#include <string>
void Renderer::drawBlok(Blok *bl,std::vector<SmallBlok*> cb,WiFiClient client)
{
  if(bl->type==controll || bl->type==status)
  {
    client.println("<div class=\"Box\">");
    client.println("<div class=\"fake-border\">");
    for(int i=0;i<cb.size();i++)
    {
      if(cb[i]->blok_id==bl->id)
      {
        this->drawSmallBlok(cb[i],client,bl->type);
      }
      
      
    }
    client.println("</div>");
    client.println("</div>");
  }
  else
  {
    
    client.println(((Nav_blok*)bl)->getBlokStyle().c_str());
  }
}

void Renderer::drawSmallBlok(SmallBlok* cb,WiFiClient client,BlokTypeEnum type)
{
  if(type==controll)
  {
    if(cb->identify()==ONOFF)
    {
      client.println("<div class=\"controll-box\">");
      std::string namee="<div class=\"textC\">";
      namee.append(cb->name);
      client.println(namee.c_str());
      std::string status= "<div class=\"status-dot\">";
      status.append(cb->actual_status);
      status.append("</div></div>");
      client.println(status.c_str());
      std::string buttons="<div class=\"button-line\"><a href=\"";
      buttons.append(cb->name);
      buttons.append("=ON\"><button class=\"on\">On</button></a><a href=\"");
      buttons.append(cb->name);
      buttons.append("=OFF\"><button class=\"off\">Off</button></a></div>");
      client.println(buttons.c_str()); 
      //client.println("<div class=\"button-line\"><a href=\"LED_SEARCH=ON\"><button class=\"on\">On</button></a><a href=\"LED_SEARCH=OFF\"><button class=\"off\">Off</button></a></div>");
      client.println("</div>");
    }
    else if(cb->identify()==RANGE)
    {
      client.println("<div class=\"controll-box\">");
      std::string namee="<div class=\"textC\">";
      namee.append(cb->name);
      client.println(namee.c_str());
      std::string status= "<div class=\"status-dot\">";
      status.append(cb->actual_status);
      status.append("</div></div>");
      client.println(status.c_str());
      std::string range="<form><input type=\"range\" name=";
      range.append(cb->name);
      range.append(" value=\""); 
      range.append(std::to_string(cb->getValue()));
      range.append("\" min=\"0\" max=\"250\" id=\"ran\" onchange=\"updateRange(this)\"><div id=\"ranhodnota\">0</div>");
      client.println(range.c_str());
      std::string buttons=("<div class=\"button-line\"><button class=\"on\">Submit</button>");
      buttons.append("</div></form>");
      client.println(buttons.c_str()); 
      //client.println("<div class=\"button-line\"><a href=\"LED_SEARCH=ON\"><button class=\"on\">On</button></a><a href=\"LED_SEARCH=OFF\"><button class=\"off\">Off</button></a></div>");
      client.println("</div>");
    }
  }
  else
  {
    client.println("<div class=\"status-box\">");
    std::string namee="<div class=\"textC\">";
    namee.append(cb->name);
    client.println(namee.c_str());
    client.println("</div>");
    std::string status= "<div class=\"textC\">";
    cb->update();
    status.append(cb->actual_status);
    status.append("</div>");
    client.println(status.c_str());
    client.println("</div>");
  }
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
  client.println("<meta http-equiv=\"refresh\" content=\"10\">");
  client.println("<link rel=\"stylesheet\" href=\"https://cdn.jsdelivr.net/gh/openlayers/openlayers.github.io@master/en/v6.15.1/css/ol.css\" type=\"text/css\">");
  client.println("<link rel=\"stylesheet\" href=\"https://raw.githack.com/Thechopsee/REM-Boat/main/style.css\" type=\"text/css\">");
  client.println("<script src=\"https://cdn.jsdelivr.net/gh/openlayers/openlayers.github.io@master/en/v6.15.1/build/ol.js\"></script>");
  client.println("<title>REM-Boat</title>");
  this->drawOLMJS(client);
  client.println("</head>");
  client.println("<body onload=start()>");
  client.println("<h1>REM-Boat</h1>");
  client.println("<div class=\"container\">");
}

void Renderer::drawOLMJS(WiFiClient client)
{
  client.println("<script type=\"text/javascript\">");
  client.println("function start(){var map = new ol.Map({target: \"map\",layers: [new ol.layer.Tile({source: new ol.source.OSM()})],view: new ol.View({center: ol.proj.fromLonLat([18.610968,49.754749]),zoom:17 })});");
  client.println("var markers = new ol.layer.Vector({");
  client.println("source: new ol.source.Vector(),style: new ol.style.Style({image: new ol.style.Icon({anchor: [0.5, 1],src: 'https://icons-for-free.com/download-icon-map+marker+icon-1320166582858325800_48.png'})})});");
  client.println("map.addLayer(markers);");

 client.println("var marker = new ol.Feature(new ol.geom.Point(ol.proj.fromLonLat([18.610968, 49.754749])));");
 client.println("markers.getSource().addFeature(marker);");
  client.println("}</script>");
}


void Renderer::drawNew(std::vector<Blok *>bl,std::vector<SmallBlok*> cb,WiFiClient client)
{
  if(this->strategy==nullptr)
  {
    this->strategy=new RenderStrategy(bl);
  }
  
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println(""); 
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");
  ///////////////////////////head////////////////
  client.println("<head>");
  for(int i=0;i<this->strategy->linkscomands.size();i++)
  {
    client.println(strategy->linkscomands[i]->renderMessage().c_str());
  }
 
  client.println("<script type=\"text/javascript\">");
  for(int i=0;i<this->strategy->jscomands.size();i++)
  {
    client.println(strategy->jscomands[i]->renderMessage().c_str());
  }
  client.println("</script>");
  client.println("</head>");
  //////////////////////body////////////////////
  client.println("<body onload=start()>");
  client.println("<h1>REM-Boat</h1>");
  client.println("<div class=\"container\">");
  for(int i=0;i<bl.size();i++)
  {
    this->drawBlok(bl[i],cb,client);
  }
  client.println("</div>");
  client.println("</body>");
}
