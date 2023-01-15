
#include "Main.h"
#include "Eveniment.h"
#include "Bilet.h"
#include "User.h"
#include "Meniu.h"
#include "IBilet.h"
#include "Angajat.h"
#include "Credentiale.h"
#include "Login.h"
#include <string>
#include<iostream>
#include<vector>
#include<fstream>
#include<list>

using namespace std;

void main() {
	Meniu meniu;
	Login login;

	int i = 1;
	Bilet bilet1(123456789, 100.00);
	char s[] = { 'f','i','l','m' };
	Eveniment event1(s, "abc", "12-03-2023", 100);
	vector<Eveniment*> evenimenteExistente;
	evenimenteExistente.push_back(&event1);
	vector<Bilet*> bileteExistente;
	bileteExistente.push_back(&bilet1);
;
//	cout << bileteDisponibile.size();

	while (i != 0) { 
		login.login();
		i = meniu.alegeInput(0, 2);

		if (i == 1) {
			cout << "V-ati autentificat ca angajat. Configureaza-ti profilul." << endl;
			Angajat angajat;
			angajat.setDataAngajare("01-01-2023");

			angajat.setPrenume(meniu.adaugaInformatii("Prenumele dvs: "));
			angajat.setNume(meniu.adaugaInformatii("Numele dvs: "));
			angajat.setEmail(meniu.adaugaInformatii("Emailul dvs: "));

			cout << "Bine ati venit!" << endl;

			while (i != 0) {
				login.meniu(1);
				i = meniu.alegeInput(0, 7);
				if (i == 1) {
					login.arataToateEvenimentele(evenimenteExistente);
				}
				else if (i == 2) {
					login.adaugaBileteInCos();
					i = meniu.alegeInput(1, 8);
				}
				else if (i == 3) {
					login.arataToateEvenimentele(evenimenteExistente);
					cout << "\n Ce eveniment vreti sa stergeti?\n";
					if (evenimenteExistente.size())
					{
						i = meniu.alegeInput(1, evenimenteExistente.size());
						meniu.stergeEveniment(evenimenteExistente, i);
					}
				}
				else if (i == 4) {
					login.arataToateEvenimentele(evenimenteExistente);
					if (evenimenteExistente.size()) {
						cout << "\nCe eveniment doriti sa editati?\n";
						i = meniu.alegeInput(1, evenimenteExistente.size());
						meniu.modificaEveniment(evenimenteExistente, i);
					}
				}
				else if (i == 5) {
					meniu.veziBileteVandute();
				}
				else if (i == 6) {
					meniu.veziEvenimente();
				}
			}
		}
	}

}
