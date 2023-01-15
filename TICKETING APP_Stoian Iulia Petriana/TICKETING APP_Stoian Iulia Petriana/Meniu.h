#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include "Meniu.h"
#include "User.h"
#include "Bilet.h"

using namespace std;

class Meniu
{
public:
	int alegeInput(int start, int finish); 
	void getBilete(Bilet* bilete); 
	void adaugaBilet(Bilet* bilet); 
	void veziEvenimente(); 
	string adaugaInformatii(string s); 
	void adaugaEvenimente(vector<Eveniment*>& evenimenteExistente, Eveniment* const& evenimente); //
	void stergeEveniment(vector<Eveniment*>& evenimenteExistente, int i); //
	void modificaEveniment(vector<Eveniment*>& evenimenteExistente, int i);
	void veziBileteVandute(); 
	void salveazaBilet(Bilet* b); 
	void salveazaEveniment(Eveniment* e); 
	virtual void greeting();
};

