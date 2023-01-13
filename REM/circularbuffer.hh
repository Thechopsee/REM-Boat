
#pragma once
#include "DisplayToken.hh"
#include <vector>

class CircularBuffer
{
    public:
    int max_size;
    std::vector<DisplayToken *> buffer;
    int size;
    int actual_index;
    CircularBuffer(int max)
    {
        this->size=0;
        this->max_size=max; 
        this->actual_index=-1;
    }
    void Add(DisplayToken * tkn)
    {
        if(actual_index==-1)
        {
            actual_index=0;
        }
        if(size!=max_size)
        {
        size++;
        buffer.push_back(tkn);
        }
    }
    void Delete(int id)
    {
      buffer.erase(buffer.begin() + id);
      if(id==actual_index)
      {
        actual_index--;
        
      }
      size--;
    }
};