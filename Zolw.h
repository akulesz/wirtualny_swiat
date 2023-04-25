#pragma once
#include "Swiat.h"
#include "Zwierze.h"

class Zolw : public Zwierze {
public:
	int licznik = 0;
	Zolw(int pozX, int pozY, Swiat* swiat, int wiek);
	void akcja() override;
	//void kolizja(Organizm* a) override;
	void rysowanie() override;
	bool czyOdbilAtak(Organizm* agresor);
	Organizm* kopiuj()override;
};