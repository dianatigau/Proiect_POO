#include "CAnimatie.h"

void CAnimatie::set_dub(bool is_dubbed)
{
	this->is_dubbed = is_dubbed;
}

const char* CAnimatie::get_dub()
{
	if (this->is_dubbed == true) return "dublat in limba romana";
	else return "";
}
