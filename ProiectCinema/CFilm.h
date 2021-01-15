#pragma once
#include "IFilm.h"
#include<iostream>

using namespace std;
class CFilm :
	public IFilm
{
protected:
	char* nume_film;
	char* categorie;
	char* ora;
	int sala;
	int pret;

public:

	CFilm();
	CFilm(const char* nume_film, const char* categorie, const char* ora, int sala, int pret);
	CFilm(const CFilm& copy);
	virtual ~CFilm();

	CFilm operator=(const CFilm& copy);

	virtual char* get_ora() const;
	virtual int get_sala_asociata()const;
	virtual int get_pret() const;
	virtual char* get_nume_film() const;
	virtual char* get_categorie()const;
	virtual const char* get_4dx() { return nullptr; }
	virtual const char* get_dub() { return nullptr; }

	friend std::ostream& operator<<(ostream& os, const CFilm& film);
	friend std::istream& operator>>(istream& os, CFilm& film);

	virtual void set_dub(bool is_dubbed) { ; }
	virtual void set_4dx(bool is4dx) { ; }
	virtual void set_categorie(const char* categorie);
	virtual void set_ora(const char* ora);
	virtual void set_sala_asociata(int sala);
	virtual void set_pret(int pret);
	virtual void set_nume_film(const char* nume_film);
};

std::ostream& operator<<(ostream& os, const CFilm& film);
std::istream& operator>>(istream& os, CFilm& film);