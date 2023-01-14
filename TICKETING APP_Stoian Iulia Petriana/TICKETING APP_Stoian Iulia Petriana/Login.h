#pragma once
#include<iostream>
#include<vector>
#include"Bilet.h"
#include "Eveniment.h"

using namespace std;

class Login
{
public:
	void login();
	void meniu(int tipUser);
	void arataToateEvenimentele(vector<Eveniment*> evenimente);
	void adaugaBileteInCos();

};

