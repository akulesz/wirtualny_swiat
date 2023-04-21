#pragma once
#include "Roslina.h"

class Guarana :public Roslina {
	Guarana(int pozX, int pozY, Swiat* swiat, int wiek);
	void akcja() override;
	void kolizja(Organizm* a) override;
	void rysowanie() override;

};