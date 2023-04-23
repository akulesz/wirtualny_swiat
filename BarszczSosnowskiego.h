#pragma once
#include "Roslina.h"

class BarszczSosnowskiego :public Roslina {
public:
	BarszczSosnowskiego(int pozX, int pozY, Swiat* swiat, int wiek);
	void akcja() override;
	void kolizja(Organizm* a) override;
	void rysowanie() override;

};