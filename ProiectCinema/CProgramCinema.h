#pragma once
#include"CFilm.h"
#include"CSali.h"
#include<vector>
#include<iostream>
using namespace std;
class CProgramCinema
{
public:
	static CProgramCinema& get_instance();
	static void destroy_instance();
	void add_film(CFilm &film);
	void add_Sala(CSali& sala);
	void delete_film(int nr_crt);
	int get_ultima_sala();
	void print_sali_ocupate();
	void print_situatie_locuri(int i);
	void select_loc(int linie, int coloana,int nr_crt_film);
	void select_anulare_loc(int linie, int coloana, int nr_crt_film);
	bool verify_sala_ocupata(int nr_sala);//true=liber false=ocupat
	


	void print_program();
private:
	std::vector<CFilm*> lista_filme;
	std::vector<CSali> sali_asociate_filmelor;
	CProgramCinema();
	~CProgramCinema();

	static CProgramCinema* instance;


};

/*
std::ostream& operator<<(ostream& os, CFilm& film)
{
	// TODO: insert return statement here
	os << film.get_nume_film() << "\t" << film.get_categorie() << "\t" << film.get_pret() << "\t" << film.get_sala_asociata() << "\t" << film.get_ora() << endl;
	return os;
}
*/

