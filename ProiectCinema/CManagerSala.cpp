#include "CManagerSala.h"
#include<stdio.h>
#include<fstream>
#include"CID.h"

CManagerSala* CManagerSala::instance = (CManagerSala*)0;



CManagerSala& CManagerSala::get_instance()
{
	// TODO: insert return statement here
	if (instance == NULL)
		instance = new CManagerSala();
	return (CManagerSala&)*instance;

}

void CManagerSala::destroy_instance()
{
	if (instance == NULL)
		return;
	delete instance;
	instance = NULL;
}

void CManagerSala::afisare_program()
{
	CProgramCinema::get_instance().print_program();
}

void CManagerSala::add_film(CFilm& film)
{
	
	while (true)
	{
		if (CProgramCinema::get_instance().verify_sala_ocupata(film.get_sala_asociata()) == true)
		{
			CSali sala(film.get_sala_asociata());
			CProgramCinema::get_instance().add_Sala(sala);
			CProgramCinema::get_instance().add_film(film);
			break;
		}
		else
		{
			printf("va rugam sa asociati alta sala filmului %s\n",film.get_nume_film());
			printf("salile ocupate deja sunt: ");
			CProgramCinema::get_instance().print_sali_ocupate();
			int sala_noua = 0;
			scanf("%d", &sala_noua);
			system("CLS");
			film.set_sala_asociata(sala_noua);
		}
	}
	ofstream f;
	f.open("init.bin", ios::app);
	if (strcmp(film.get_categorie(), "actiune") == 0)
	{
		
		f << film << " ";
		if (strcmp(film.get_4dx(), "4dx") == 0)
			f << 1;
		else f << 0;
		f << endl;
		//fprintf(f, "%s %s %s %d %d", film.get_nume_film(), film.get_categorie(), film.get_ora(), film.get_sala_asociata(), film.get_pret());
	}
	else if (strcmp(film.get_categorie(), "animatie") == 0)
	{
		f << film << " " ;
		if (strcmp(film.get_dub(), "dublat in limba romana")==0) f << 1;
		else f << 0;

		f << endl;
	}
	else if (strcmp(film.get_categorie(), "actiune") == 0)
	{
		f << film << " ";
		if (strcmp(film.get_dub(), "4dx") == 0) f << 1;
		else f << 0;

		f << endl;
	}
	else
	{
		f << film<<endl;
	}
	f.close();
}

void CManagerSala::delete_film(int nr_crt)
{
	CProgramCinema::get_instance().delete_film(nr_crt);
}

void CManagerSala::print_situatie_locuri(int i)
{
	CProgramCinema::get_instance().print_situatie_locuri(i);
}

void CManagerSala::select_loc(int linie, int coloana,int nr_crt_film)
{
	CProgramCinema::get_instance().select_loc(linie, coloana, nr_crt_film);

	
}

void CManagerSala::select_anulare_loc(int linie, int coloana, int nr_crt_film)
{
	CProgramCinema::get_instance().select_anulare_loc(linie, coloana, nr_crt_film);
}

void CManagerSala::init(const char* nume_fisier_lista_filme)
{
	
	ifstream f;
	int id;
	f.open("id.bin");
	f >> id;
	f.close();
	CID::get_first_instance(id);

	f.open(nume_fisier_lista_filme);
	CFilm* film=new CFilm();
	while (f >> *film)
	{
		

		int ok;

		if (strcmp(film->get_categorie(), "actiune") == 0)
		{
			f >> ok;
			bool bo;
			if (ok == 1) bo = true;
			else bo = false;
			film = this->create_film_actiune(film->get_nume_film(), film->get_ora(), film->get_pret(), film->get_sala_asociata(), bo);
		}
		else if (strcmp(film->get_categorie(), "animatie") == 0)
		{
			f >> ok;
			bool bo;
			if (ok == 1) bo = true;
			else bo = false;
			film = this->create_film_animatie(film->get_nume_film(), film->get_ora(), film->get_pret(), film->get_sala_asociata(), bo);
		}

		CProgramCinema::get_instance().add_film(*film);
		CSali sala(film->get_sala_asociata());

		char nume_fisier_sala[10];
		_itoa(film->get_sala_asociata(), nume_fisier_sala, 10);
		strcat(nume_fisier_sala, ".bin");
		ifstream file_sala;
		file_sala.open(nume_fisier_sala);
		file_sala>> sala;
		file_sala.close();
		CProgramCinema::get_instance().add_Sala(sala);
		film = new CFilm();
	}
	f.close();




}

CFilm* CManagerSala::create_film_actiune(const char* nume_film, const char* ora, int pret, int sala, bool is_4dx)
{
	CActiune *film=new CActiune() ;
	film->set_4dx(is_4dx);
	film->set_categorie("actiune");
	film->set_nume_film(nume_film);
	film->set_ora(ora);
	film->set_pret(pret);
	film->set_sala_asociata(sala);
	return film;
}

CFilm* CManagerSala::create_film_animatie(const char* nume_film,const char* ora, int pret, int sala, bool is_dubbed)
{
	CAnimatie* film = new CAnimatie();
	film->set_dub(is_dubbed);
	film->set_categorie("animatie");
	film->set_nume_film(nume_film);
	film->set_ora(ora);
	film->set_pret(pret);
	film->set_sala_asociata(sala);
	return film;
}

CFilm* CManagerSala::create_film(const char* nume_film, const char* categorie, const char* ora, int pret, int sala)
{
	CFilm* film = new CFilm(nume_film, categorie, ora, sala, pret);
	return film;
}



CManagerSala::CManagerSala()
{
}
CManagerSala::~CManagerSala()
{
}