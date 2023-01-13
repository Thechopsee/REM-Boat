#include "DisplayToken.hh"

DisplayToken::DisplayToken(std::string text,int lifesize)
{
    this->text=text;
    this->TokenValidity=lifesize;
}

std::string DisplayToken::getText()
{
    this->TokenValidity--;
    return text;
}