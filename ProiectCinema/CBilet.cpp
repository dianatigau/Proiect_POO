#include "CBilet.h"
#include<stdio.h>
#include<string>
#include<fstream>
#include"CID.h"

using namespace std;

CBilet::CBilet(int col_loc, int linie_loc, int sala, char* ora_rularii,char*nume_film)
{
	this->coloana_loc = col_loc;
	this->linie_loc = linie_loc;
	this->sala = sala;
	this->ora_rularii = (char*)malloc((strlen(ora_rularii) + 1) * sizeof(char));
	strcpy(this->ora_rularii, ora_rularii);
	this->ID = CID::get_instance().getID();
	this->nume_film = (char*)malloc((strlen(nume_film) + 1) * sizeof(char));
	strcpy(this->nume_film, nume_film);
}

void CBilet::print_bilet()
{
	char id[10];
	_itoa(this->ID, id, 10);
	ofstream f;
	strcat(id, ".txt");
	f.open(id);
	f << *this;
	system("CLS");
	cout <<*this;

}
std::ostream& operator<<(std::ostream& os, CBilet bilet)
{
	// TODO: insert return statement here
	os << "ID: " << bilet.ID << endl;
	os <<"Film: " <<bilet.nume_film << endl;
	char col = bilet.coloana_loc + 65;
	os << "LOC: " << bilet.linie_loc+1 << col<< endl;
	os << "SALA: " << bilet.sala << endl;
	os << "ORA: " << bilet.ora_rularii;
	return os;
}
