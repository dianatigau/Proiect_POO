#pragma once
#include<vector>
#include<iostream>
using namespace std;
class CSali
{
private:
	int nr_sala;
	int nr_total_locuri;
	int nr_locuri_disponibile;
	int locuri[10][15];
public:
	CSali(int nr_sala);
	void select_loc(int& linie, int& coloana);
	void select_anulare_loc(int linie, int coloana);
	void print_situatie_locuri();
	friend std::istream& operator>>(std::istream& os, CSali& sala);
	friend std::ostream& operator<<(std::ostream& os, CSali sala);
	int get_id(); 
};

std::istream& operator>>(std::istream& os, CSali& sala);
std::ostream& operator<<(std::ostream& os, CSali sala);