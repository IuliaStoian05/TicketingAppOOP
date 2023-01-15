#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <string>
#include<iostream>
#include<vector>
#include "Bilet.h"

using namespace std;

class Eveniment {
private:
	string denumire;
	string data;
	int nrLocuriDisponibile;
	int nrTotalRanduri;
	int nrTotalLocuriPeRand;
	int nrTotalLocuri;
	char* tipEveniment;

public:
	// destructor
	~Eveniment();

	// constructor fara parametri
	Eveniment();

	// constructor cu 4 parametri
	Eveniment(char* tipEveniment, string denumire, string data, int nrLocuriDisponibile);
	
	// setteri
	void setDenumire(string denumire);
	void setData(string data);
	void setNrLocuriDisponibile(int nrLocuriDisponibile);
	void setNrTotalLocuri(int nrTotalLocuri);
	void setNrTotalRanduri(int nrTotalRanduri);
	void setNrTotalLocuriPeRand(int nrTotalLocuriPeRand);
	void setTipEveniment(char* tipEveniment);
	
	// getteri
	string getDenumire();
	string getData();
	int getNrLocuriDisponibile();
	int getNrTotalLocuri();
	int getNrTotalRanduri();
	int getNrTotalLocuriPeRand();
	char* getTipEveniment();
	
	// operatorul <<
	friend ostream& operator<<(ostream& out, const Eveniment& e);

	// operatorul >>
	friend istream& operator>>(istream& in, Eveniment& e);

	// operator ==
	bool operator==(Eveniment e);

	// operator ++ (post)
	Eveniment operator++(int);

	//metode

	virtual string toString();
	void calculeazaNrLocuriTotal(int nrLocuriPeRand, int nrTotalRanduri);
//	int calculeazaNrLocuriDisponibile(int nrTotalLocuri, vector<Bilet*> bileteVandute);
	virtual void setAttributes();
};
	