#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include "Bilet.h"
#include <string>
#include<iostream>
#include<vector>

using namespace std;

enum CATEGORIE_VARSTA{ copil=1, student, elev, adult, pensionar};

class User
{
private:
	string nume;
	string prenume;
	int varsta;
	CATEGORIE_VARSTA categorieBilet;
	bool areReducere;
	string email;
	std::vector<Bilet*> bilete;
public:
	//Bilet bilet;
	//Eveniment evenimentulDorit;

	// constructor fara parametri
	User();
	
	// constructor cu toti parametri
	User(string nume, string prenume, string email, int varsta, CATEGORIE_VARSTA categorieBilet, bool areReducere, vector<Bilet*> bilete);
	
	// setteri
	void setNume(string nume);
	void setPrenume(string prenume);
	void setVarsta(int varsta);
	void setCategorieBilet(CATEGORIE_VARSTA categorieBilet);
	void setAreReducere(bool areReducere);
	void setEmail(string email);

	// getteri
	string getNume();
	string getPrenume();
	int getVarsta();
	CATEGORIE_VARSTA getCategorieBilet();
	bool getAreReducere();
	int getNrBilete();
	// operatorul <<
	friend ostream& operator<<(ostream& out, const User& c);

	// operatorul >>
	friend istream& operator>>(istream& in, User& c);

	// operator =
	User& operator=(const User& c);

	// operator <
	friend bool operator<(int varstamin, User c);

	// metode 
	void stergeBiletDinCos(vector<Bilet*>& bilete, int index);
	void adaugaEveniment(vector<Eveniment*> evenimente);
};

