#pragma once
#include "Swiat.h"
#include "Zwierze.h"

class Wilk : public Zwierze {
public:
	Wilk(int pozX, int pozY, Swiat* swiat, int wiek);
	void akcja() override;
	void kolizja(Organizm *a) override;
	void rysowanie() override;

};