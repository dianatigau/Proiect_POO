#include "CFilm.h"
#include<string>

#include"CID.h"

CFilm::CFilm()
{
	this->nume_film = nullptr;
	this->categorie = nullptr;
	this->ora = nullptr;
	this->pret = 0;
	this->sala = 0;
}

CFilm::CFilm(const char* nume_film,const char *categorie,const char* ora, int sala, int pret)
{

	this->sala = sala;
	this->pret = pret;
	this->categorie= (char*)malloc((strlen(categorie) + 1) * sizeof(char));
	strcpy(this->categorie, categorie);
	this->nume_film = (char*)malloc((strlen(nume_film) + 1) * sizeof(char));
	strcpy(this->nume_film, nume_film);
	this->ora= (char*)malloc((strlen(ora) + 1) * sizeof(char));
	strcpy(this->ora, ora);
}

CFilm::CFilm(const CFilm& copy)
{
	this->pret = copy.get_pret();
	this->sala= copy.get_sala_asociata();
	this->categorie = (char*)malloc((strlen(copy.categorie) + 1) * sizeof(char));
	strcpy(this->categorie, copy.categorie);
	this->nume_film = (char*)malloc((strlen(copy.get_nume_film()) + 1) * sizeof(char));
	strcpy(this->nume_film, copy.get_nume_film());
	this->ora = (char*)malloc((strlen(copy.get_ora()) + 1) * sizeof(char));
	strcpy(this->ora, copy.get_ora());
}

CFilm::~CFilm()
{
	this->pret = 0;
	this->sala = 0;
	free(this->categorie);
	this->categorie = nullptr;
	free(this->nume_film);
	this->nume_film = nullptr;
	free(this->ora);
	this->ora = nullptr;
}

CFilm CFilm::operator=(const CFilm& copy)
{
	this->pret = copy.get_pret();
	this->sala = copy.get_sala_asociata();
	this->categorie = (char*)malloc((strlen(copy.categorie) + 1) * sizeof(char));
	strcpy(this->categorie, copy.categorie);
	this->nume_film = (char*)malloc((strlen(copy.get_nume_film()) + 1) * sizeof(char));
	strcpy(this->nume_film, copy.get_nume_film());
	this->ora = (char*)malloc((strlen(copy.get_ora()) + 1) * sizeof(char));
	strcpy(this->ora, copy.get_ora());
	return *this;
}

char* CFilm::get_ora()const
{
	return this->ora;
}

int CFilm::get_sala_asociata()const
{
	return this->sala;
}

int CFilm::get_pret()const
{
	return this->pret;
}

char* CFilm::get_nume_film()const
{
	return this->nume_film;
}

char* CFilm::get_categorie()const
{
	
	return this->categorie;
}

/*std::ostream& CFilm::operator<<(ostream& os)
{
	// TODO: insert return statement here
	os << this->nume_film << "\t" << this->categorie << "\t" << this->pret << "\t" << this->sala << "\t" << this->ora << endl;
	return os;
}
*/


void CFilm::set_categorie(const char* categorie)
{
	this->categorie = (char*)malloc((strlen(categorie) + 1) * sizeof(char));
	strcpy(this->categorie, categorie);
}

void CFilm::set_ora(const char* ora)
{
	this->ora = (char*)malloc((strlen(ora) + 1) * sizeof(char));
	strcpy(this->ora, ora);
}

void CFilm::set_sala_asociata(int sala)
{
	this->sala = sala;
}

void CFilm::set_pret(int pret)
{
	this->pret = pret;
}

void CFilm::set_nume_film(const char* nume_film)
{
	this->nume_film = (char*)malloc((strlen(nume_film) + 1) * sizeof(char));
	strcpy(this->nume_film, nume_film);
}

std::ostream& operator<<(ostream& os, const CFilm& film)
{
	// TODO: insert return statement here
	if (strcmp(film.categorie, "animatie") == 0)
	{
		os << film.nume_film << "\t" << film.categorie <<"  " << film.pret << "\t" << film.sala << "\t" << film.ora<<" ";
	}
	else os << film.nume_film << "\t" << film.categorie << "\t  " << film.pret << "\t" << film.sala << "\t" << film.ora<<" ";
	return os;
}

std::istream& operator>>(istream& os, CFilm& film)
{
	// TODO: insert return statement here
	char nume_film[20];
	char categorie[20];
	char ora[10];
	int sala;
	int pret;
	bool bo;
	int ok;
	os >> nume_film;
	os >> categorie;
	os >> pret;
	os >> sala;
	os >> ora;

	film.set_nume_film(nume_film);
	film.set_categorie(categorie);
	film.set_pret(pret);
	film.set_sala_asociata(sala);
	film.set_ora(ora);

	return os;

}

