#pragma once
#include <string>
class RxTxModule
{
    public:
    int rxpin;
    int txpin;
    RxTxModule(int rxpin,int txpin);
    virtual std::string GetStatus();
};
