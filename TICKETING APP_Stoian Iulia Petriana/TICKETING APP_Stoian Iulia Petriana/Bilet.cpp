#include "Bilet.h"
#include <string>
#include<iostream>
#include<vector>
#include "Eveniment.h"

using namespace std;

// destructor
Bilet::~Bilet() {
	if (tipLoc != NULL) {
		delete[]this->tipLoc;
	}
	if (loc != NULL) {
		delete[]this->loc;
	}
	if (rand != NULL) {
		delete[]this->rand;
	}
}
// constructor fara parametri
Bilet::Bilet() : cod(contorBilete++) {
	this->tipLoc = new char[strlen("NA") + 1];
	strcpy(tipLoc, "NA");
	this->pret = 0.0;
	this->loc = NULL;
	this->rand = NULL;
	this->esteValid = false;
}


// constructor cu 3 parametri
Bilet::Bilet(const int cod, double pret): cod (contorBilete++) {
	this->pret = pret;
	/*
	if (this->tipLoc != NULL) {
		delete[]this->tipLoc;
	}
	this->tipLoc = new char[strlen(tipLoc) + 1];
	strcpy(this->tipLoc,tipLoc);
	
	*/
//	this->loc = new int[eveniment.getNrTotalLocuri()];
	//for (int i = 0; i < eveniment.getNrTotalLocuri(); i++)
	//{
	//	this->loc[i] = loc[i];
	//}
	//this->rand = new int[eveniment.getNrTotalRanduri()];
	//for (int i = 0; i < eveniment.getNrTotalRanduri(); i++)
	//{
	//	this->rand[i] = rand[i];
	//}
}

// setteri
void Bilet::setTipLoc(char* tipLoc) {
	if (this->tipLoc != NULL) {
		delete[]this->tipLoc;
	}
	if (tipLoc != "") {
		this->tipLoc = tipLoc;
	}
	else {
		cout << "Introduceti tipul de loc dorit (ex. VIP, normal, loja etc)";
	}
}

void Bilet::setPret(double pret) {
	if (pret>=0.0) {
		this->pret = pret;
	}
	else {
		cout << "Prret invalid";
	}
	
}

void Bilet::setLoc(int* loc) {
	if (this->loc != NULL) {
		delete[]this->loc;
	}
	if (loc !=NULL) {
		this->loc = loc;
	}
	else {
		cout << "Numar loc invalid";
	}
}

void Bilet::setRand(int* rand) {
	if (this->rand != NULL) {
		delete[]this->rand;
	}
	if (rand !=NULL) {
		this->rand = rand;
	}
	else {
		cout << "Numar rand invalid";
	}
}

void Bilet::setEsteValid(bool esteValid) {
	if (esteValid == true) {
this->esteValid = esteValid;
	}
	else {
		cout << "Codul biletului este invalid";
	}
	
}

// getteri
int Bilet::getCod() {
	return cod;
}
char* Bilet::getTipLoc() {
	return tipLoc;
}
double Bilet::getPret()
{
	return pret;
}
int* Bilet::getLoc() {
	return loc;
}
int* Bilet::getRand() {
	return rand;
}
bool Bilet::getEsteValid() {
	return esteValid;
}

// operatorul <<
ostream& operator<<(ostream& out, const Bilet& b) {
	Eveniment e;
	out << b.cod << endl;
	out << b.tipLoc << endl;
	out << b.pret << endl;
	for (int i = 0; i < e.getNrTotalLocuri(); i++) {
		out << b.loc[i] << endl;
	}
	for (int i = 0; i < e.getNrTotalRanduri(); i++) {
		out << b.rand[i] << endl;
	}
	out << b.esteValid << endl;
	return out;
}
// operatorul >>
istream& operator>>(istream& in, Bilet& b) {
	Eveniment e;
	// char* tipLoc
	cout << "Tipul de loc: ";
	delete[]b.tipLoc;
	string auxiliar;
	getline(in, auxiliar);
	b.tipLoc = new char[auxiliar.size() + 1];
	strcpy_s(b.tipLoc, auxiliar.size() + 1, auxiliar.c_str());

	// double pret
	cout << "Pret: ";
	in >> b.pret;

	// int* loc
	delete[]b.loc;
	b.loc = new int[e.getNrTotalLocuri()];
	for (int i = 0; i < e.getNrTotalLocuri(); i++) {
		cout << "Locul " << i + 1 << ": ";
		in >> b.loc[i];
	}
	// int* rand

	delete[]b.rand;
	b.rand = new int[e.getNrTotalRanduri()];
	for (int i = 0; i < e.getNrTotalRanduri(); i++) {
		cout << "Rand: " << i + 1 << ": ";
		in >> b.rand[i];
	}
	//bool esteValid
	cout << "Biletul este valid? ";
	in >> b.esteValid;
	return in;
}

// operator de indexare[]
int& Bilet::operator[](int pozitie) {
	Eveniment* eveniment = new Eveniment();
	if (pozitie >= 0 && pozitie < eveniment->getNrTotalLocuri()) {
		return this->loc[pozitie];
	}
	else {
		int val = -1;
		return val;
	}
}

// operator cast ! explicit
bool Bilet::operator!(){
	bool raspuns = 0;
	if (this->esteValid == 1) {
		raspuns = 1;
		this->esteValid = 0;
	}
	else {
		raspuns = 0;
		this->esteValid = 1;
	}
	return raspuns;
}

int Bilet::contorBilete = 1;

// metode 
string Bilet::toString()
{
	return "Bilet\n";
}

void Bilet::verificaValiditate(vector<Bilet*> bileteValide, Bilet* b1, Bilet* b2) {
	bileteValide.push_back(b1);
	if (b1->getCod() != b2->getCod()) {
		bileteValide.push_back(b2);
	}
	else {
		cout << "Bilet invalid" << endl;
	}
}

void Bilet::seteazaAtribute() {

}

string Bilet::tooString()
{
	return "Bilet\n";
}

