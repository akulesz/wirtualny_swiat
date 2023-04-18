#pragma once
#include "Organizm.h"
#include "Random.h"
#include "Swiat.h"

class Zwierze : public Organizm {
public:
	Zwierze(int sila, int inicjatywa, int pozX, int pozY, Swiat* swiat) : Organizm(sila, inicjatywa, pozX, pozY, swiat);
	void akcja() override;
	void kolizja(Organizm* a) override;

};
