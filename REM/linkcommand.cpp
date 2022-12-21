#include "linkcommand.hh"

std::string LinkCommand::renderMessage()
{
std::string data="";
  data.append("<meta charset=\"UTF-8\">"); 
  data.append("<meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
  data.append("<meta http-equiv=\"refresh\" content=\"10\">");
  data.append("<link rel=\"stylesheet\" href=\"https://cdn.jsdelivr.net/gh/openlayers/openlayers.github.io@master/en/v6.15.1/css/ol.css\" type=\"text/css\">");
  data.append("<link rel=\"stylesheet\" href=\"https://raw.githack.com/Thechopsee/REM-Boat/main/style.css\" type=\"text/css\">");
  data.append("<script src=\"https://cdn.jsdelivr.net/gh/openlayers/openlayers.github.io@master/en/v6.15.1/build/ol.js\"></script>");
  data.append("<title>REM-Boat</title>");
  return data;
}