#pragma once
#include "User.h"

class Angajat : public User
{
private: 
	string dataAngajare;

public:
	Angajat();
	Angajat(string nume, string prenume, string email, string dataAngajare);

	// getteri
	string getDataAngajare();

	// setteri
	void setDataAngajare(string dataAngajare);
};

