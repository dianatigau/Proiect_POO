#include "CProgramCinema.h"
#include<stdio.h>
#include"CActiune.h"
#include"CAnimatie.h"
#include"CBilet.h"
#include<fstream>
#include<conio.h>

using namespace std;
CProgramCinema* CProgramCinema::instance = (CProgramCinema*)0;

CProgramCinema& CProgramCinema::get_instance()
{
	if (instance == NULL)
		instance = new CProgramCinema();
	return (CProgramCinema&)*instance;
}

void CProgramCinema::destroy_instance()
{
	if (instance == NULL)
		return;
	delete instance;
	instance = NULL;
}

void CProgramCinema::add_film(CFilm &film)
{
	this->lista_filme.push_back(&film);
	
}

void CProgramCinema::add_Sala(CSali& sala)
{
	this->sali_asociate_filmelor.push_back(sala);
}

void CProgramCinema::delete_film(int nr_crt)
{
	this->lista_filme.erase(this->lista_filme.begin() + nr_crt - 1);
	this->sali_asociate_filmelor.erase(this->sali_asociate_filmelor.begin() + nr_crt - 1);
	ofstream f;
	f.open("init.bin");
	for (int i = 0; i < this->lista_filme.size(); i++)
	{
		f << *this->lista_filme[i] << " ";
		if (strcmp(this->lista_filme[i]->get_categorie(), "actiune") == 0)
		{

			
			if (strcmp(this->lista_filme[i]->get_4dx(), "4dx") == 0)
				f << 1;
			else f << 0;
			
			//fprintf(f, "%s %s %s %d %d", film.get_nume_film(), film.get_categorie(), film.get_ora(), film.get_sala_asociata(), film.get_pret());
		}
		else if (strcmp(this->lista_filme[i]->get_categorie(), "animatie") == 0)
		{
			
			if (strcmp(this->lista_filme[i]->get_dub(), "dublat in limba romana") == 0) f << 1;
			else f << 0;

		}
		f << endl;
	}
	f.close();
}

int CProgramCinema::get_ultima_sala()
{
	return this->sali_asociate_filmelor.size();
}

void CProgramCinema::print_sali_ocupate()
{
	for (int i = 0; i < this->lista_filme.size(); i++)
		cout << this->lista_filme[i]->get_sala_asociata() << " ";
	cout << endl;
}

void CProgramCinema::print_situatie_locuri(int i)
{
	printf("\t\tFILM: %s\n", this->lista_filme[i]->get_nume_film());
	this->sali_asociate_filmelor[i].print_situatie_locuri();
}

void CProgramCinema::select_loc(int linie, int coloana,int nr_crt_film)
{
	this->sali_asociate_filmelor[nr_crt_film].select_loc(linie, coloana);
	CBilet* bilet = new CBilet(coloana, linie, this->sali_asociate_filmelor[nr_crt_film].get_id(),
		this->lista_filme[nr_crt_film]->get_ora(), this->lista_filme[nr_crt_film]->get_nume_film());
	bilet->print_bilet();
	_getch();
}

void CProgramCinema::select_anulare_loc(int linie, int coloana, int nr_crt_film)
{
	this->sali_asociate_filmelor[nr_crt_film].select_anulare_loc(linie, coloana);
}

bool CProgramCinema::verify_sala_ocupata(int nr_sala)
{
	for (int i = 0; i < this->sali_asociate_filmelor.size(); i++)
	{
		if (this->sali_asociate_filmelor[i].get_id() == nr_sala) return false;
	}
	return true;
}



void CProgramCinema::print_program()
{
	printf("nr.crt\tfilm\tgen\t  pret\tsala\tora\toptiuni speciale\n");
	for (int i = 0; i < this->lista_filme.size(); i++)
	{
		cout << i + 1<<"\t";
		
		CFilm *film_local = this->lista_filme[i];
		cout << *film_local;
		if (strcmp(film_local->get_categorie(), "actiune") == 0) cout << "\t" << film_local->get_4dx();
		if (strcmp(film_local->get_categorie(), "animatie") == 0) cout << "\t" << film_local->get_dub();
		
		cout<<endl;
	}
}




CProgramCinema::CProgramCinema()
{}

CProgramCinema::~CProgramCinema()
{
}
