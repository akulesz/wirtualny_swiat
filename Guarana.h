#pragma once
#include "Roslina.h"

class Guarana :public Roslina {
public:
	Guarana(int pozX, int pozY, Swiat* swiat, int wiek, bool zyje);
	Guarana(int sila, int inicjatywa, int pozX, int pozY, Swiat* swiat, char symbol, int wiek, bool zyje);
	void rysowanie() override;
	Roslina* kopiuj() override;
	bool czyWzmocnil(Organizm* a) override;
};