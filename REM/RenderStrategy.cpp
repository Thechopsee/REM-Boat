#include "RenderStrategy.hh"

void RenderStrategy::buildStrategy(std::vector<Blok *> blk)
{
    
    this->linkscomands.push_back(new LinkCommand());
    for(int i=0;i<blk.size();i++)
    {
        if(blk[i]->type==nav)
        {
            Nav_blok * temp=(Nav_blok *)blk[i];
            this->jscomands.push_back(new NavCommand(temp->getModule()));
            break;
        }
    }
    return;
};

RenderStrategy::RenderStrategy(std::vector<Blok *>  blk)
{
    buildStrategy(blk);
    return;
}
