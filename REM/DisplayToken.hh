#pragma once
#include <string>
class DisplayToken
{   
    public:
        std::string text;
        int TokenValidity;
        DisplayToken(std::string text,int lifesize);
    std::string getText();
};