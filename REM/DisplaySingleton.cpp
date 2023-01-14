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
        if(this->buffer->actual_index==-1)
        {
            return;
        }
        
        this->buffer->buffer[this->buffer->actual_index]->TokenValidity--;
        this->handler->showText(this->buffer->buffer[this->buffer->actual_index]->getText());
        if(this->buffer->buffer[this->buffer->actual_index]->TokenValidity<=0)
        {
            this->buffer->Delete(buffer->actual_index);
        }
        
        this->buffer->actual_index++;
        if(this->buffer->actual_index>=buffer->size)
        {
            this->buffer->actual_index=0;
        }
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