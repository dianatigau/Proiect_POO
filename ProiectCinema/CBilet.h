#pragma once
#include<iostream>
class CBilet
{
private:
	int coloana_loc;
	int linie_loc;
	int sala;
	char* ora_rularii;
	char* nume_film;
	int ID;
public:
	CBilet(int col_loc, int linie_loc, int sala, char* ora_rularii,char*nume_film);
	void print_bilet();
	friend std::ostream& operator<<(std::ostream& os,CBilet bilet);
};

std::ostream& operator<<(std::ostream& os,CBilet bilet);
