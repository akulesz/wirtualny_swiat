#pragma once
#include "Swiat.h"
#include "Zwierze.h"

class Lis : public Zwierze {
public:
	Lis(int pozX, int pozY, Swiat* swiat, int wiek);
	void akcja() override;
	void kolizja(Organizm *a) override;
	void rysowanie() override;
	bool czySilny(int z, int y, int a, int b );

};