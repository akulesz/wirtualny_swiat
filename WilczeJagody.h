#pragma once
#include "Roslina.h"

class WilczeJagody :public Roslina {
public:
	WilczeJagody(int pozX, int pozY, Swiat* swiat, int wiek, bool zyje);
	WilczeJagody(int sila, int inicjatywa, int pozX, int pozY, Swiat* swiat, char symbol, int wiek, bool zyje);
	void rysowanie() override;
	Roslina* kopiuj() override;
	bool czyOtrul(Organizm *a ) override;
};