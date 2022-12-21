#pragma once
#include <iostream>
#include <vector>
#include "rcommand.hh"
#include "blok.hh"
#include "linkcommand.hh"
#include "navcommand.hh"
#include "nav_blok.hh"
class RenderStrategy
{
    public:
    std::vector<Rcommand *> jscomands;
    std::vector<Rcommand *> linkscomands;
    std::vector<Rcommand *> blokcomands;
    RenderStrategy(std::vector<Blok *> blk);
    void buildStrategy(std::vector<Blok *> blk);
};