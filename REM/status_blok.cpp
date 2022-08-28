#include "status_blok.hh"
Status_blok::Status_blok(int id,int blok_id,int pin,char *name) : SmallBlok(id,blok_id,pin,name)
{
    this->actual_status="Unknown";
}