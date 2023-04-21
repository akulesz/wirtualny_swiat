#pragma once
#include <iostream>
#include "Zwierze.h"

class Czlowiek : public Zwierze {
public:
	Czlowiek(int pozX, int pozY, Swiat* swiat, int wiek);
	void akcja() override;
	void kolizja(Organizm* a) override;
	void rysowanie() override;

};