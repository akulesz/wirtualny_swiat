#pragma once
#include "Roslina.h"

class WilczeJagody :public Roslina {
public:
	WilczeJagody(int pozX, int pozY, Swiat* swiat, int wiek);
	void akcja() override;
	void kolizja(Organizm* a) override;
	void rysowanie() override;

};