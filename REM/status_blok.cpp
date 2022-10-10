#include "status_blok.hh"
Status_blok::Status_blok(int id,int blok_id,int pin,char *name,RxTxModule* module) : SmallBlok(id,blok_id,pin,name)
{
    this->module=module;
    this->actual_status="Unknown";
}

void Status_blok::update()
{
    this->actual_status=this->module->GetStatus();
}
