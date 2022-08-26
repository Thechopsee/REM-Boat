#pragma once
#include "smallBlok.hh"
#include <string>
class Status_blok :public SmallBlok
{
    public:
    std::string name;
    std::string status;
    Status_blok(std::string name);
};
