#include "Login.h"
#include<iostream>

using namespace std;

void Login::login() {
	cout << "LOGIN" << endl;
	cout << "Alegeti tipul de utilizator" << endl;
	cout << "  1. Angajat\n";
	cout << "  2. Client\n";
	cout << "  0. Exit\n";
}

void Login::meniu(int tipUser) {
    if (tipUser == 1) {
        cout << "\nCe actiune doriti sa realizati?\n";
        cout << "1. Vezi evenimente existente\n";
        cout << "2. Adauga eveniment\n";
        cout << "3. Sterge eveniment\n";
        cout << "4. Modifica eveniment\n";
        cout << "5. Vezi bilete vandute\n";
        cout << "0. Exit\n";
    }
    else if (tipUser == 2) {
        cout << "\nCe actiune doriti sa realizati?\n";
        cout << "1. Vezi evenimente existente\n";
        cout << "2. Adauga bilet in cos\n";
        cout << "0. Exit\n";
    }
    else cout << "Input Gresit! Va rugam reintroduceti!\n";
}

void Login::arataToateEvenimentele(vector<Eveniment*> evenimente) 
{
    vector<Eveniment*>::iterator i;
    cout << "\nAfisare evenimente\n";
    int count = 1;
    if (evenimente.size())
    {
        for (i = evenimente.begin(); i != evenimente.end(); i++)
        {
            cout << count << ". " << (*i)->toString() << endl;
            count++;
        }
    }
    else cout << "\n\tNu sunt evenimente momentan\t\n";
}

void Login::adaugaBileteInCos() {

}