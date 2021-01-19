#pragma once
#include"CProgramCinema.h"
#include"CActiune.h"
#include"CAnimatie.h"
class CManagerSala
{
public:
	static CManagerSala& get_instance();
	static void destroy_instance();
	void afisare_program();
	void add_film(CFilm&film);
	void delete_film(int nr_crt);
	void print_situatie_locuri(int i);

	void select_loc(int linie, int coloana,int nr_crt_film);
	void select_anulare_loc(int linie, int coloana, int nr_crt_film);

	void init(const char *nume_fisier_lista_filme);

	CFilm* create_film_actiune(const char *nume_film,const char *ora,int pret,int sala, bool is_4dx);
	CFilm* create_film_animatie(const char* nume_film,const char* ora, int pret, int sala, bool is_dubbed);
	CFilm* create_film(const char* nume_film,const char* categorie,const char* ora, int pret, int sala);

private:
	CManagerSala();
	~CManagerSala();



	static CManagerSala* instance;


};

