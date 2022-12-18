
#include"Eveniment.h"
#include <string>
#include<iostream>
#include<vector>

using namespace std;

// destructor
Eveniment::~Eveniment() {
	if (tipEveniment != NULL) {
		delete[]this->tipEveniment;
	}
}
// constructor fara parametri
Eveniment::Eveniment() {
	this->denumire = "NA";
	this->data = "dd.mm.yyyy";
	this->nrLocuriDisponibile = 1;
	this->nrTotalRanduri = 1;
	this-> nrTotalLocuriPeRand = 1;
	this->tipEveniment = new char[strlen("NA") + 1];
	strcpy(this->tipEveniment, "NA");
}
// constructor cu 4 parametri
Eveniment::Eveniment(char* tipEveniment, string denumire, string data, int nrLocuriDisponibile){
	this->denumire = denumire;
	this->data = data;
	this->nrLocuriDisponibile = nrLocuriDisponibile;
	this->nrTotalRanduri = 1;
	this->nrTotalLocuriPeRand = 1;
	this->nrTotalLocuri = 1;
	this->tipEveniment = new char[strlen(tipEveniment) + 1];
	strcpy(this->tipEveniment, tipEveniment);
}

// setteri
void Eveniment::setDenumire(string denumire) {
	if (denumire == "[a-zA-Z_]") {
		this->denumire = denumire;
	}
	else {
		cout << "Reintroduceti denumirea!" << endl;
	}
}
void Eveniment::setData(string data) {
	if (data != "") {
		this->data = data;
	}
	else {
		cout << "Introduceti data evenimentului!" << endl;
	}
}

void Eveniment::setNrLocuriDisponibile(int nrLocuriDisponibile) {
	if (nrLocuriDisponibile > nrTotalLocuri) {
		cout << "Nr de locuri disponibile invalid!" << endl;
	} else {
		this->nrLocuriDisponibile = nrLocuriDisponibile;
	}
}

void Eveniment::setNrTotalLocuri(int nrTotalLocuri) {
	if (nrTotalRanduri != 0 && nrTotalLocuriPeRand != 0) {
		nrTotalLocuri = nrTotalLocuriPeRand * nrTotalRanduri;
	}
	else {
		cout << "Nr total locuri invalid" << endl;
	}
}

void Eveniment::setNrTotalRanduri(int nrTotalRanduri) {
	if (nrTotalRanduri != 0) {
		this->nrTotalRanduri = nrTotalRanduri;
	}
	else {
		cout << "Nr total randuri invalid" << endl;
	}
}

void Eveniment::setNrTotalLocuriPeRand(int nrTotalLocuriPeRand) {
	if (nrTotalLocuriPeRand != 0) {
		this->nrTotalLocuriPeRand = nrTotalLocuriPeRand;
	}
	else {
		cout << "Nr total locuri pe rand invalid" << endl;
	}
}

void Eveniment::setTipEveniment(char* tipEveniment) {
	if (tipEveniment != NULL) {
		delete[]this->tipEveniment;
	}
	if (tipEveniment != "") {
		this->tipEveniment = tipEveniment;
	}
	else {
		cout << "Introduceti tipul de eveniment" << endl;
	}
}

// getteri
string Eveniment::getDenumire() {
	return this->denumire;
}

string Eveniment::getData() {
	return this->data;
}

int Eveniment::getNrLocuriDisponibile() {
	return this->nrLocuriDisponibile;
}

int Eveniment::getNrTotalLocuri() {
	return this->nrTotalLocuri;
}

int Eveniment::getNrTotalRanduri() {
	return this->nrTotalRanduri;
}

int Eveniment::getNrTotalLocuriPeRand() {
	return this->nrTotalLocuriPeRand;
}

char* Eveniment::getTipEveniment() {
	return this->tipEveniment;
}

// operatorul <<
ostream& operator<<(ostream& out, const Eveniment& e) {
	out << e.denumire << endl;
	out << e.data << endl;
	out << e.nrLocuriDisponibile << endl;
	out << e.nrTotalRanduri << endl;
	out << e.nrTotalLocuriPeRand << endl;
	out << e.nrTotalLocuri << endl;
	out << e.tipEveniment << endl;
	return out;
}
// operatorul >>
istream& operator>>(istream& in, Eveniment& e) {
	cout << "Denumire eveniment: ";
	in >> e.denumire;
	cout << "Data: ";
	in >> e.data;
	cout << "Nr locuri disponibile: ";
	in >> e.nrLocuriDisponibile;
	cout << "Nr total de randuri: ";
	in >> e.nrTotalRanduri;
	cout << "Nr total locuri pe rand: ";
	in >> e.nrTotalLocuriPeRand;
	cout << "Nr total locuri: ";
	in >> e.nrTotalLocuri;
	cout << "Tipul de eveniment: ";
	delete[]e.tipEveniment;
	string auxiliar;
	getline(in, auxiliar);
	e.tipEveniment = new char[auxiliar.size() + 1];
	strcpy_s(e.tipEveniment, auxiliar.size() + 1, auxiliar.c_str());
	return in;
}

// operator ++ (post)
Eveniment Eveniment::operator++(int) {
	Eveniment copieEveniment = *this;
	this->nrLocuriDisponibile++;
	return copieEveniment;
}

// operator ==
bool Eveniment::operator==(Eveniment e) {
	return this->denumire == e.denumire;
}

// metode
int Eveniment::calculeazaNrLocuriDisponibile(int nrTotalLocuri, vector<Bilet*> bileteVandute) {
	int nrLocuriOcupate = bileteVandute.size();
	nrLocuriDisponibile = nrTotalLocuri - nrLocuriOcupate;
	return nrLocuriDisponibile;
}

void Eveniment::calculeazaNrLocuriTotal(int nrLocuriPeRand, int nrTotalRanduri) {
	nrTotalLocuri = nrLocuriPeRand * nrTotalRanduri;
}
