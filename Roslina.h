#pragma once
#include "Swiat.h"
#include "Organizm.h"
#include "Random.h"

 class Roslina : public Organizm {
 public:
	 Roslina(int sila, int inicjatywa, int pozX, int pozY, Swiat* swiat, char symbol, int wiek, bool zyje);
	 void akcja() override;
	 void kolizja(Organizm* a) override;
};