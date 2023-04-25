#pragma once
#include "Swiat.h"
#include "Zwierze.h"

// class Swiat;

class Owca : public Zwierze {
public:
	Owca(int pozX, int pozY, Swiat* swiat, int wiek);
	Owca(int sila, int inicjatywa, int pozX, int pozY, Swiat* swiat, char symbol, int wiek);
//	void akcja() override;
//	void kolizja(Organizm *a) override;
	void rysowanie() override;
	Organizm* kopiuj() override;
};