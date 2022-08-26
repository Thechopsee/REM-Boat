#include "nav_blok.hh"
#include <string>
Nav_blok::Nav_blok(int id) :Blok(id,nav)
{
    this->id=id;
    this->type=nav;
    this->getStatus();
}
std::string Nav_blok::getBlokStyle()
{
    std::string blokstyle="";
    blokstyle.append("<div class=\"map\" id=\"map\"></div>");
    blokstyle.append("<div class=\"status-line\">N ");  
    blokstyle.append(this->latitude);
    blokstyle.append(" E ");
    blokstyle.append(this->longitude);
    blokstyle.append("</div>");       
    return blokstyle;
                
                
}
void Nav_blok::getStatus()
{
    ///ToDo
    this->latitude="0";
    this->longitude="0";
    this->pathLon.push_back(this->longitude);
    this->pathLat.push_back(this->latitude);
}
