#pragma once
#include "Swiat.h"
#include "Zwierze.h"

class Owca : public Zwierze {
public:
	Owca(int pozX, int pozY, Swiat* swiat, int wiek, bool zyje);
	Owca(int sila, int inicjatywa, int pozX, int pozY, Swiat* swiat, char symbol, int wiek, bool zyje);
	void rysowanie() override;
	Organizm* kopiuj() override;
};