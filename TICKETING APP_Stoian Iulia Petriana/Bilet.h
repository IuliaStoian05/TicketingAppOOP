#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <string>
#include<iostream>
#include<vector>
#include "Eveniment.h"


using namespace std;

class Bilet
{
private:
	const int cod;
	char* tipLoc; // ex. VIP, normal, loja etc.
	double pret;
	int* loc;
	int* rand;
	bool esteValid; 
	static int contorBilete;
public:
	Eveniment eveniment;
	// destructor
	~Bilet();

	// constructori
	Bilet();
	Bilet(char* tipLoc, double pret, int* loc, int* rand, bool esteValid);
	
	// setteri
	void setTipLoc(char* tipLoc);
	void setPret(double pret);
	void setLoc(int* loc);
	void setRand(int* rand);
	void setEsteValid(bool esteValid);
	
	// getteri
	int getCod();
	char* getTipLoc();
	double getPret();
	int* getLoc();
	int* getRand();
	bool getEsteValid();

	// operatorul <<
	friend ostream& operator<<(ostream& out, const Bilet& b);

	// operatorul >>
	friend istream& operator>>(istream& in, Bilet& b);

	// operator de indexare []
	int& operator[](int pozitie);

	// operator negare !
	bool operator!();

	//metode
	string toString();
	void verificaValiditate(vector<Bilet*> bileteValide, Bilet* b1, Bilet* b2);
};


