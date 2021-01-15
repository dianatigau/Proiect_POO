#pragma once
class IFilm
{

public:
	IFilm() { ; }
	IFilm(const IFilm&) { ; }
	virtual ~IFilm() { ; }


	virtual char* get_ora()const = 0;
	virtual int get_sala_asociata()const = 0;
	virtual int get_pret() const = 0;
	virtual char* get_nume_film()const = 0;


	virtual void set_ora(const char* ora) = 0;
	virtual void set_sala_asociata(int sala) = 0;
	virtual void set_pret(int pret) = 0;
	virtual void set_nume_film(const char* nume_film) = 0;

};

