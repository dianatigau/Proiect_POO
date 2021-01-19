#include<stdio.h>
#include"CManagerSala.h"
#include"CFilm.h"
#include<conio.h>
int main()
{
	char comanda[20];
	CManagerSala &program = CManagerSala::get_instance();
	program.init("init.bin");
	printf("Doriti sa va logati ca admin sau ca user normal?\n");
	int ok=' ';
	printf("Pentru admin tastati 0, iar pentru user 1\n");
	scanf("%d", &ok);

	int logged = 0;
	if (ok == 0)
	{
		printf("Logare admin\n");
		printf("introduceti parola: ");
	}
	while (ok == 0)
	{
		char parola[10];
		while (logged==0)
		{
			scanf("%s", parola);
			system("CLS");
			if (strcmp(parola, "admin") == 0)
			{
				printf("Logare reusita\n");
				logged = 1;
				_getch();
				system("CLS");
				break;
			}
			printf("Parola incorecta\nva rugam sa reintroduceti parola: ");
		}

		printf("\t\t\tProgram\n");
		program.afisare_program();

		printf("Pentru a inchide aplicatia tastati \"exit\"");
		printf("\nPentru a introduce un film nou, tastati 1\n");
		printf("Pentru a sterge un film tastati 2 urmat de nr. crt. al filmului\n");
		printf("Pentru a te muta pe cont de user normal tastati 3\n");

		scanf("%s", comanda);
		if (strcmp(comanda, "exit") == 0) return 0;

		if (atoi(comanda) == 1)
		{
			
			
			int dub_or_4dx;

			CFilm* film = new CFilm();

			printf("Introduceti datele filmului in ordinea urmatoare:\nnume filme, categorie, pret, sala, ora\n");
			cin >> *film;

			if (strcmp(film->get_categorie(), "actiune") == 0)
			{
				cout << "este filmul 4dx?\n0=nu\t1=da" << endl;;
				cin >> dub_or_4dx;
				bool bo;
				if (dub_or_4dx == 1) bo = true;
				else bo = false;
				film = program.create_film_actiune(film->get_nume_film(), film->get_ora(), film->get_pret(), film->get_sala_asociata(), bo);
			}
			else if (strcmp(film->get_categorie(), "animatie") == 0)
			{
				cout << "este filmul dublat in limba romana?\n0=nu\t1=da" << endl;
				cin >> dub_or_4dx;
				bool bo;
				if (dub_or_4dx== 1) bo = true;
				else bo = false;
				film = program.create_film_animatie(film->get_nume_film(), film->get_ora(), film->get_pret(), film->get_sala_asociata(), bo);
			}
			program.add_film(*film);
			system("CLS");
		}

		if (atoi(comanda) == 2)
		{
			int nr_crt = 0;
			cin >> nr_crt;
			program.delete_film(nr_crt);
		}

		if (atoi(comanda) == 3)
			ok = 1;

	}

	system("CLS");

	printf("\t\t\tProgram\t\t\t\t\t\t Pentru a inchide aplicatia tastati \"exit\"\n\n");
	program.afisare_program();
	printf("\nIntroduceti numarul curent al filmului pentru care vreti sa achizitionati un bilet:");
	while (true)
	{
		int ok = 1;
		scanf("%s", comanda);
		system("CLS");
		if (strcmp(comanda, "exit") == 0) break;
		int nr_crt_film = atoi(comanda)-1;
		program.print_situatie_locuri(nr_crt_film);
		printf("Daca doriti sa eliberati un loc introduceti 0 urmat de rand coloana(ex.0 1 A)\n");

		
		scanf("%s", comanda);
		char coloana=' ';
		if (strcmp(comanda, "exit") == 0) break;
		if (strcmp(comanda, "0") == 0)
		{
			char linie = ' ';
			scanf(" %c %c", &linie, &coloana);
			program.select_anulare_loc(linie-49, coloana - 65, nr_crt_film);
		}
		else
		{
			scanf(" %c", &coloana);
			program.select_loc(atoi(comanda) - 1, coloana - 65, nr_crt_film);
		}


		system("CLS");
		printf("\t\t\tProgram\t\t\t\t\t\t Pentru a inchide aplicatia tastati \"exit\"\n\n");
		program.afisare_program();
		printf("\nIntroduceti numarul curent al filmului pentru care vreti sa achizitionati un bilet:");
		


		
	}
	
	/*
	CFilm* film = program.create_film("Focus", "comedie", "20:00", 25, 1);
	program.add_film(*film);
	film = program.create_film_actiune("Fast", "18:25", 40, 2, true);
	program.add_film(*film);
	film = program.create_film_animatie("Frozen", "15:40", 20, 3, false);
	program.add_film(*film);
	program.afisare_program();
	printf("\t\t\tProgram\t\t\t\t\t\t Pentru a inchide aplicatia tastati \"exit\"\n\n");
	program.afisare_program();
	printf("\nIntroduceti numarul curent al filmului pentru care vreti sa achizitionati un bilet:");
	while (true)
	{
		int ok = 1;
		scanf("%s", comanda);
		system("CLS");
		if (strcmp(comanda, "exit") == 0) break;
		int nr_crt_film = atoi(comanda)-1;
		program.print_situatie_locuri(nr_crt_film);

		scanf("%s", comanda);
		char coloana = ' ';
		if (strcmp(comanda, "exit") == 0) break;

		scanf(" %c", &coloana);
		program.select_loc(atoi(comanda) - 1, coloana - 65, nr_crt_film);
		system("CLS");
		program.print_situatie_locuri(nr_crt_film);



	}*/
	return 0;
}