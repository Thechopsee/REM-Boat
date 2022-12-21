#pragma once
#include "nav_module.hh"
#include "rcommand.hh"
#include <vector>
#include "blok.hh"
#include <sstream>
class NavCommand :public Rcommand
{
    private:
    Nav_module * module;
    public:
    NavCommand(Nav_module * module);
    std::string renderMessage();
};
