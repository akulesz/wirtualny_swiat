#pragma once
#include "Roslina.h"

class Mlecz :public Roslina {
public:
	Mlecz(int pozX, int pozY, Swiat* swiat, int wiek);
	void akcja() override;
	void kolizja(Organizm* a) override;
	void rysowanie() override;
	Roslina* kopiuj() override;
};