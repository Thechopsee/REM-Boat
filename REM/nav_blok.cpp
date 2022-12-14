#include "nav_blok.hh"
#include <string>
#include <sstream>
Nav_blok::Nav_blok(int id) :Blok(id,nav)
{
    this->id=id;
    this->type=nav;
    this->module=new NEO6MV2_module();
    this->getStatus();
}
std::string Nav_blok::getBlokStyle()
{
    std::string blokstyle="";
    this->getStatus();
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
    std::string data=this->module->getData();
    std::stringstream ss(data);
    std::string world;
    getline(ss,world,';');
    this->latitude=world;
    getline(ss,world,';');
    this->longitude=world;
    this->pathLon.push_back(this->longitude);
    this->pathLat.push_back(this->latitude);
}
