#pragma once
#include<iostream>
#include"Eveniment.h"
#include<string>

using namespace std;

class Film: public Eveniment
{
private:
	double oraIncepere;
	int durataMinute;
	string locatie;

public:
	Film();
	Film(char* tipEveniment, string denumire, string locatie, string data, double oraIncepere, int durataMinute, int nrLocuriDisponibile);
	Film(Film& film);
	~Film();

	//getteri
	double getOraIncepere();
	int getDurataMinute();

	//setteri
	void setOraIncepere(double oraIncepere);
	void setDurataMinute(int durataMinute);
};

