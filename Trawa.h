#pragma once
#include "Roslina.h"

class Trawa :public Roslina {
public:
	Trawa(int pozX, int pozY, Swiat* swiat, int wiek, bool zyje);
	Trawa(int sila, int inicjatywa, int pozX, int pozY, Swiat* swiat, char symbol, int wiek, bool zyje);
	void rysowanie() override;
	Roslina* kopiuj() override;
};