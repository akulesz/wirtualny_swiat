#pragma once
#include "Swiat.h"
#include "Zwierze.h"

class Antylopa : public Zwierze {
public:
	Antylopa(int pozX, int pozY, Swiat* swiat, int wiek);
	void akcja() override;
	void kolizja(Organizm* a) override;
	void rysowanie() override;

};