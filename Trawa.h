#pragma once
#include "Roslina.h"

class Trawa :public Roslina {
public:
	Trawa(int pozX, int pozY, Swiat* swiat, int wiek);
	Trawa(int sila, int inicjatywa, int pozX, int pozY, Swiat* swiat, char symbol, int wiek);
	//void akcja() override;
	//void kolizja(Organizm* a) override;
	void rysowanie() override;
	Roslina* kopiuj() override;
};