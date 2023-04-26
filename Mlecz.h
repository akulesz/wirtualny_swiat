#pragma once
#include "Roslina.h"

class Mlecz :public Roslina {
public:
	Mlecz(int pozX, int pozY, Swiat* swiat, int wiek, bool zyje);
	Mlecz(int sila, int inicjatywa, int pozX, int pozY, Swiat* swiat, char symbol, int wiek, bool zyje);
	void akcja() override;
	void rysowanie() override;
	Roslina* kopiuj() override;
};