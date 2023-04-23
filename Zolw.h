#pragma once
#include "Swiat.h"
#include "Zwierze.h"

class Zolw : public Zwierze {
public:
	int licznik = 1;
	Zolw(int pozX, int pozY, Swiat* swiat, int wiek);
	//void akcja() override;
	void kolizja(Organizm* a) override;
	void rysowanie() override;

};