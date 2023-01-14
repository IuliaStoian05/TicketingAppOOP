#pragma once
#include<iostream>
#include"Eveniment.h"
#include<string>

using namespace std;

class MeciFotbal: public Eveniment
{
private:
	string echipa1;
	string echipa2;
	string locatie;
	double oraIncepere;
public:
	MeciFotbal();
	MeciFotbal(char* tipEveniment, string denumire, string locatie,double oraIncepere, string echipa1, string echipa2,string data);
	MeciFotbal(MeciFotbal& meci);
	~MeciFotbal();

	// getteri
	string getLocatie();
	string getEchipa1();
	string getEchipa2();
	double getOraIncepere();

	//setteri
	void setLocatie(string locatie);
	void setOraIncepere(double oraIncepere);
	void setEchipa1(string echipa1);
	void setEchipa2(string echipa2);
};

