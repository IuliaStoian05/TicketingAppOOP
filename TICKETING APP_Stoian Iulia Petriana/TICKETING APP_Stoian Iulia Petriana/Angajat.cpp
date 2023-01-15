#include "Angajat.h"

using namespace std;

Angajat::Angajat() {
	this->dataAngajare = "dd-mm-yyyy";
}

Angajat::Angajat(string nume, string prenume, string email, int varsta, string dataAngajare) 
	:User (nume, prenume, email, varsta){
	if (dataAngajare != "") {
		this->dataAngajare = dataAngajare;
	}
	else {
		this->dataAngajare = "01-01-2023";
	}
}

string Angajat::getDataAngajare()
{
	return dataAngajare;
}


void Angajat::setDataAngajare(string dataAngajare)
{
	if (dataAngajare != " ")
		this->dataAngajare = dataAngajare;
}

string Angajat::toString(string s){
	return "";
}