#include "Main.h"
#include "Eveniment.h"
#include "Bilet.h"
#include "User.h"
#include "Meniu.h"
#include "IBilet.h"
#include "Film.h"
#include "MeciFotbal.h"
#include "PiesaTeatru.h"
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
	Bilet bilet2(7873828292, 50.00);
	Bilet bilet3(109292829, 27.00);
	vector<Bilet*> bileteDisponibile;
	bileteDisponibile.push_back(&bilet1);
	bileteDisponibile.push_back(&bilet2);
	bileteDisponibile.push_back(&bilet3);
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
				i = meniu.alegeInput(0, 6);
			}

		}
	}

}
