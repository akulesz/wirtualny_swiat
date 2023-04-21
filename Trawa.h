#pragma once
#include "Roslina.h"

class Trawa :public Roslina {
public:
	Trawa(int pozX, int pozY, Swiat* swiat, int wiek);
	void akcja() override;
	void kolizja(Organizm* a) override;
	void rysowanie() override;

};