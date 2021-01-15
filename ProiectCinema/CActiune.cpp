#include "CActiune.h"


void CActiune::set_4dx(bool is4dx)
{
	this->is4dx = is4dx;
}

const char* CActiune::get_4dx()
{
	if (this->is4dx == true)
		return "4dx";
	else return "";
}
