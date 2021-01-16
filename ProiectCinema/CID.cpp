#include "CID.h"
#include<stdio.h>
#include<fstream>
#define ID_BASE 0x000000

using namespace std;

CID* CID::instance = (CID*)0;



CID& CID::get_instance()
{
	// TODO: insert return statement here
	if (instance == NULL)
		instance = new CID();
	return (CID&)*instance;

}

CID& CID::get_first_instance(int id)
{
	// TODO: insert return statement here
	if (instance == NULL)
		instance = new CID(id);
	return (CID&)*instance;
}

void CID::destroy_instance()
{
	if (instance == NULL)
		return;
	delete instance;
	instance = NULL;
}

unsigned int CID::getID()
{
	last_ID++;
	ofstream f;
	f.open("id.bin"); 
	f << last_ID;
	return last_ID;
}

CID::CID() :last_ID(ID_BASE)
{}
CID::CID(int id) : last_ID(id)
{}

CID::~CID()
{
}
