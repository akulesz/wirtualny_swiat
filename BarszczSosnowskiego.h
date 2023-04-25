#pragma once
#include "Roslina.h"

class BarszczSosnowskiego :public Roslina {
public:
	BarszczSosnowskiego(int pozX, int pozY, Swiat* swiat, int wiek);
	BarszczSosnowskiego(int sila, int inicjatywa, int pozX, int pozY, Swiat* swiat, char symbol, int wiek);
	void akcja() override;
	//void kolizja(Organizm* a) override;
	void rysowanie() override;
	Roslina* kopiuj() override;
	bool czyOtrul(Organizm *a);
};