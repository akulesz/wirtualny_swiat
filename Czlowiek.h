#pragma once
#include <iostream>
#include "Zwierze.h"

class Czlowiek : public Zwierze {
	int odlicznanieDoUmiejetnosci = 0;
	int stanPoczatkowy;
	bool czyUmiejetnoscAktywna = false;
	
public:
	Czlowiek(int pozX, int pozY, Swiat* swiat, int wiek, bool zyje);
	Czlowiek(int sila, int inicjatywa, int pozX, int pozY, Swiat* swiat, char symbol, int wiek, bool zyje, int odliczanieDoUmiejetnosci, int stanPoczatkowy, bool czyUmiejetnoscAktywna);
	void akcja() override;
	void magicznyEliksir();
	void rysowanie() override;
	Organizm* kopiuj() override;

	string serializuj() override {
		return std::to_string(sila) + ' ' +
			std::to_string(inicjatywa) + ' ' +
			std::to_string(pozX) + ' ' +
			std::to_string(pozY) + ' ' +
			symbol + ' ' +
			std::to_string(wiek) + ' ' +
			std::to_string(zyje) + ' ' +
			std::to_string(odlicznanieDoUmiejetnosci) + ' ' +
			std::to_string(stanPoczatkowy) + ' ' +
			std::to_string(czyUmiejetnoscAktywna);
	}
};