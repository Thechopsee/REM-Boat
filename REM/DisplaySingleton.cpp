#include "DisplaySingleton.hh"

DisplaySingleton::DisplaySingleton()
    {
       buffer=new CircularBuffer(10);
       handler=new OLEDDisplayHandler();
       buffer->Add(new DisplayToken("OLED Ready",2));
       buffer->Add(new DisplayToken("ip",100000000));
    }
DisplaySingleton* DisplaySingleton::returnInstance()
    {
        if(singleton==nullptr)
        {
           singleton = new DisplaySingleton();
        }
        return  singleton;
    }

    void DisplaySingleton::Tick()
    {
        std::string text=this->buffer->Next();
        this->handler->showText(text);
    }


    void DisplaySingleton::Add(std::string textt,int lifetime)
    {
      this->buffer->Add(new DisplayToken(textt.c_str(),lifetime));
    }        
    void DisplaySingleton::AddIp(IPAddress ip)
    {
      this->handler->setIP(ip);
    }

    DisplaySingleton* DisplaySingleton::singleton=nullptr;