#pragma once
#include <iostream>
#include "Zwierze.h"

class Czlowiek : public Zwierze {
	int odlicznanieDoUmiejetnosci = 0;
	
public:
	Czlowiek(int pozX, int pozY, Swiat* swiat, int wiek);
	void akcja() override;
	//void kolizja(Organizm* a) override;
	void rysowanie() override;
	bool czyUmiejetnoscAktywowana();
	void MagicznyEliksir();
	Organizm* kopiuj() override;
};