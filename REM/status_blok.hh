#pragma once
#include "smallBlok.hh"
#include <string>
#include "rxtxmodule.hh"
class Status_blok :public SmallBlok
{
    public:
    RxTxModule* module;
    Status_blok(int id,int blok_id,int pin,char *name,RxTxModule* module) ;
    void update();
};
