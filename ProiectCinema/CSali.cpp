#include "CSali.h"
#include<fstream>
#include<conio.h>
CSali::CSali(int nr_sala)
{
	this->nr_sala = nr_sala;
	this->nr_total_locuri = 10 * 15;
	this->nr_locuri_disponibile = 10 * 15;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 15; j++)
			this->locuri[i][j] = 0;
	}
}


void CSali::select_loc(int& linie, int& coloana)
{
	while (true)
	{
		if (this->locuri[linie][coloana] == 0)
		{
			this->nr_locuri_disponibile--;
			this->locuri[linie][coloana] = 1;
			system("CLS");

			break;
		}
		else
		{
			printf("\nlocul %d%c este deja ocupat, va rugam sa selectati altul\n", linie + 1, 65 + coloana);
			char lin[10], col = ' ';
			scanf("%s", lin);
			if (strcmp(lin, "exit") == 0) exit;
			scanf(" %c", &col);
			linie = atoi(lin) - 1;
			coloana = col - 65;

		}
	}
	char nume_fisier[10];
	_itoa(this->nr_sala, nume_fisier, 10);
	strcat(nume_fisier, ".bin");
	ofstream f;
	f.open(nume_fisier);
	f << *this;
	f.close();

}

void CSali::select_anulare_loc(int linie, int coloana)
{
	while (true)
	{
		if (this->locuri[linie][coloana] == 1)
		{
			this->nr_locuri_disponibile++;
			this->locuri[linie][coloana] = 0;
			break;
		}
		else {
			printf("locul %d%c era deja liber, probabil ati introdus gresit locul de pe bilet\ntastati exit daca vreti sa inchideti aplicatia\nsau reintroduceti randul si coloana: ", linie, 65 + coloana);
			char lin[10], col = ' ';
			scanf("%s", lin);
			if (strcmp(lin, "exit") == 0) exit;
			scanf(" %c", &col);
			linie = atoi(lin) - 1;
			coloana = col - 65;
		}

	}
	char nume_fisier[10];
	_itoa(this->nr_sala, nume_fisier, 10);
	strcat(nume_fisier, ".bin");
	ofstream f;
	f.open(nume_fisier);
	f << *this;
	f.close();
}

void CSali::print_situatie_locuri()
{
	printf("Total numar locuri=%d\tlocuri disponibile=%d\n", this->nr_total_locuri, this->nr_locuri_disponibile);
	printf("   ");
	for (int i = 0; i < 15; i++)
		printf("%c ", 65 + i);
	printf("\t\t\t Pentru a inchide aplicatia tastati \"exit\"");
	printf("\n");
	for (int i = 0; i < 10; i++)
	{
		if (i != 9) printf("%d  ", i + 1);
		else printf("%d ", i + 1);
		for (int j = 0; j < 15; j++)
		{
			printf("%d ", locuri[i][j]);
		}
		printf("\n");
	}
	printf("0=liber\t\t1=ocupat\n");
	printf("\nIntroduceti randul si coloana locului pe care il doriti:\nexemplu: 1 B\n");
}

int CSali::get_id()
{
	return nr_sala;
}

std::istream& operator>>(std::istream& os, CSali& sala)
{
	// TODO: insert return statement here
	os >> sala.nr_total_locuri >> sala.nr_locuri_disponibile;
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 15; j++)
			os >> sala.locuri[i][j];
	return os;
}

std::ostream& operator<<(std::ostream& os, CSali sala)
{
	// TODO: insert return statement here
	os << sala.nr_total_locuri << " " << sala.nr_locuri_disponibile << endl;;
	for (int i = 0; i < 10; i++) 
	{
		for (int j = 0; j < 15; j++)
			os << sala.locuri[i][j] << " ";
		os << endl;
	}
	return os;
}
