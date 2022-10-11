#pragma once
#include "status_blok.hh"
#include "blok.hh"
#include <string>
#include <vector>
#include "typeEnum.hh"
#include "NEO6MV2_module.hh"
class Nav_blok : public Blok
{
    private:
        std::string latitude;
        std::string longitude;
        std::vector<std::string> pathLon;
        std::vector<std::string> pathLat;
        NEO6MV2_module* module;
    public:
        Nav_blok(int id);
        std::string getBlokStyle();
        void setModule();
        void getStatus();
};
