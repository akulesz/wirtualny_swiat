#pragma once
#include "Roslina.h"

class Mlecz :public Roslina {
public:
	Mlecz(int pozX, int pozY, Swiat* swiat, int wiek);
	Mlecz(int sila, int inicjatywa, int pozX, int pozY, Swiat* swiat, char symbol, int wiek);
	void akcja() override;
	//void kolizja(Organizm* a) override;
	void rysowanie() override;
	Roslina* kopiuj() override;
};