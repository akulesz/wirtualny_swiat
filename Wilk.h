#pragma once
#include "Swiat.h"
#include "Zwierze.h"

class Wilk : public Zwierze {
public:
	Wilk(int pozX, int pozY, Swiat* swiat, int wiek, bool zyje);
	Wilk(int sila, int inicjatywa, int pozX, int pozY, Swiat* swiat, char symbol, int wiek, bool zyje);
	void rysowanie() override;
	Organizm* kopiuj() override;

};