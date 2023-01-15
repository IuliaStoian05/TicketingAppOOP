#define _CRT_SECURE_NO_WARNINGS
#include "User.h"
#include "Bilet.h"
#include <string>
#include<iostream>
#include<vector>

using namespace std;

// constructor fara parametri
User::User() {
	this->nume = "";
	this->prenume = "";
	this->varsta = 0;
	this->categorieBilet = adult;
	this->areReducere = false;
	this->email = "abc@abc";
}

// constructor cu toti parametrii
User::User(string nume, string prenume, string email, int varsta) {
	this->nume = "";
	this->prenume = "";
	this->email = "";
	this->varsta = 0;
	this->categorieBilet = categorieBilet;
	this->areReducere = areReducere;
	this->bilete = bilete;
}

// setteri
void User::setNume(string nume) {

	if (nume == "[a - zA - Z]") {
		this->nume = nume;
	}
}

void User::setPrenume(string prenume) {
	if (prenume == "^ [a - zA - Z\\s] + $") {
		this->prenume = prenume;
	}
}

void User::setVarsta(int varsta) {
	if (varsta >= 0) {
		this->varsta = varsta;
	}
	else {
		cout << "Varsta invalida" << endl;
	}
}

void User::setCategorieBilet(CATEGORIE_VARSTA categorieBilet) {
	if (categorieBilet == copil || categorieBilet == student || categorieBilet == elev || categorieBilet == adult || categorieBilet == pensionar) {
		this->categorieBilet = categorieBilet;
	}
	else {
		cout << "Categorie invalida" << endl;
	}
}

void User::setEmail(string email) {
	if (email != " ") {
		this->email = email;
	}
	else { cout << "Email invalid" << endl; }
}

void User::setAreReducere(bool areReducere) {
	this->areReducere = areReducere;
}

// getteri
string User::getNume() {
	return this->nume;
}

string User::getPrenume() {
	return this->prenume;
}

int User::getVarsta() {
	return this->varsta;
} 

CATEGORIE_VARSTA User::getCategorieBilet() {
	return this->categorieBilet;
}

bool User::getAreReducere() {
	return this->areReducere;
}
int User::getNrBilete() {
	int dim = bilete.size();
	return dim;
}

// operatorul <<
ostream& operator<<(ostream& out, const User& c) {
	out << c.nume << endl;
	out << c.prenume << endl;
	out << c.varsta << endl;
	out << c.categorieBilet << endl;
	out << c.areReducere << endl;
	return out;
}
// operatorul >>
istream& operator>>(istream& in, User& c) {
	cout << "Nume ";
	in >> c.nume;
	cout << endl;
	cout << "Prenume: ";
	in >> c.prenume;
	cout << endl;
	cout << "Varsta: ";
	in >> c.varsta;
	cout << endl;
	cout << "Are reducere? ";
	in >> c.areReducere;
	cout << endl;
	return in;
}

// operator =
User& User::operator=(const User& c) {
	this->nume = c.nume;
	this->prenume = c.prenume;
	this->varsta = c.varsta;
	this->categorieBilet = c.categorieBilet;
	this->areReducere = c.areReducere;
	return *this;
}

// operator <
bool operator< (int varstamin, User c) {
	return varstamin < c.varsta;
}

// metode

void User::stergeBiletDinCos(vector<Bilet*>& bileteDisp, int index) {
	bileteDisp.push_back(this->bilete[index - 1]);
	this->bilete[index - 1] = this->bilete.back();
	this->bilete.pop_back();
}


void User::adaugaEveniment(vector<Eveniment*> evenimente) {
	evenimente.push_back(new Eveniment());
}

