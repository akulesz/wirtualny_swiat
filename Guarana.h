#pragma once
#include "Roslina.h"

class Guarana :public Roslina {
public:
	Guarana(int pozX, int pozY, Swiat* swiat, int wiek);
	void akcja() override;
	void kolizja(Organizm* a) override;
	void rysowanie() override;

};