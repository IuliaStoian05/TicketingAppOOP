#pragma once
#include "User.h"
#include <string>
#include<iostream>

using namespace std;

class Angajat : public User
{
private: 
	string dataAngajare;

public:
	Angajat();
	Angajat(string nume, string prenume, string email, int varsta, string dataAngajare);

	// getteri
	string getDataAngajare();

	// setteri
	void setDataAngajare(string dataAngajare);

	// metode
	virtual string toString(string s);
};

