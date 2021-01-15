#pragma once
#include "CFilm.h"
class CActiune :
    public CFilm
{
private:
    bool is4dx;

public:
    void set_4dx(bool is4dx);
    const char* get_4dx();
};


