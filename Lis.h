#pragma once
#include "Swiat.h"
#include "Zwierze.h"

class Lis : public Zwierze {
public:
	Lis(int pozX, int pozY, Swiat* swiat, int wiek, bool zyje);
	Lis(int sila, int inicjatywa, int pozX, int pozY, Swiat* swiat, char symbol, int wiek, bool zyje);
	void akcja() override;
	void rysowanie() override;
	bool czyJestSilniejszyOd(int targetX, int targetY);
	Organizm* kopiuj() override;
};