#pragma once
#include "Swiat.h"
#include "Zwierze.h"

class Lis : public Zwierze {
	Lis(int pozX, int pozY, Swiat* swiat, int wiek);
	void akcja() override;
	void kolizja(Organizm *a) override;
	void rysowanie() override;

};