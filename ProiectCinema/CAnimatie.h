#pragma once
#include "CFilm.h"
class CAnimatie :
    public CFilm
{
private:
    bool is_dubbed;
public:
    void set_dub(bool is_dubbed);
    const char* get_dub();
};

