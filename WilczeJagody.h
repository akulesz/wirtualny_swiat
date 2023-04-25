#pragma once
#include "Roslina.h"

class WilczeJagody :public Roslina {
public:
	WilczeJagody(int pozX, int pozY, Swiat* swiat, int wiek);
	WilczeJagody(int sila, int inicjatywa, int pozX, int pozY, Swiat* swiat, char symbol, int wiek);
	//void akcja() override;
	//void kolizja(Organizm* a) override;
	void rysowanie() override;
	Roslina* kopiuj() override;
	bool czyOtrul();
};