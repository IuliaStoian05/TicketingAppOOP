#include "Meniu.h"
#include<iostream>
#include<string>
#include<iterator>
#include "Bilet.h"
#include "PiesaTeatru.h"
#include "Eveniment.h"
#include "MeciFotbal.h"
#include "Film.h"

using namespace std;

int Meniu::alegeInput(int start, int finish) {
	int i;
    bool wrong = false;
    do {
        if (wrong) {
            cout << "\nInput gresit\n" << endl;
        }
        cout << "\nAlege optiune: ";
        cin >> i;
        wrong = true;
    } while (i < start || i > finish);
    system("CLS");

    return i;

}

void Meniu::getBilete(Bilet* bilete) {
    
        ifstream in;
        string item;
        in.open("bilete.bin", ios::in | ios::binary);
        if (in.fail())
        {
            cout << " ";
            exit(1);
        }
        while (getline(in, item))
        {
            cout << item << endl;
        }
        in.close();

}

void Meniu::adaugaBilet(Bilet* bilet) {
    {
        ofstream out("bilete.bin", ios::binary | ios_base::app);
        out.write((char*)bilet, sizeof(bilet));
        out.close();
    }
}

void Meniu::adaugaEvenimente(vector<Eveniment*>& evenimenteExistente, Eveniment* const& evenimente)
{
    {
        evenimente->setAttributes();
        evenimenteExistente.push_back(evenimente);
        this->salveazaEveniment(evenimente);
    }
}

string Meniu::adaugaInformatii(string s) {
        cout << "\n" << s;
        string i;
        cin >> i;
        return i;
}

void Meniu::veziBileteVandute() {
    ifstream in;
    string item;
    in.open("bilete.bin", ios::in | ios::binary);
    if (in.fail())
    {
        cout << "Fail";
        exit(1);
    }
    while (getline(in, item))
    {
        cout << item << endl;
    }
    in.close();
}

void Meniu::stergeEveniment(vector<Eveniment*>& evenimenteExistente, int i) 
{
    evenimenteExistente[i--] = evenimenteExistente.back();
    evenimenteExistente.pop_back();
}

void Meniu::salveazaBilet(Bilet* b) {
    ofstream out;
    out.open("tickets.bin", ios::out | ios::binary | ios_base::app);

    out << b->toString() << endl;

    out.close();
}

void Meniu::salveazaEveniment(Eveniment* e)
{
    ofstream out("events.txt",ios_base::app);
    out.write((char*)e, sizeof(e));
    out.close();
}