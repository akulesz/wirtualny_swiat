#pragma once
#include "Roslina.h"

class Guarana :public Roslina {
public:
	Guarana(int pozX, int pozY, Swiat* swiat, int wiek);
	Guarana(int sila, int inicjatywa, int pozX, int pozY, Swiat* swiat, char symbol, int wiek);
	//void akcja() override;
	//void kolizja(Organizm* a) override;
	void rysowanie() override;
	Roslina* kopiuj() override;
	bool czyWzmocnil(Organizm* a);
};