#include "rxtxmodule.hh"
RxTxModule::RxTxModule(int rxpin,int txpin)
{
    this->rxpin=rxpin;
    this->txpin=txpin;
}

std::string RxTxModule::GetStatus()
{
    return "";
}