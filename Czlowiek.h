#pragma once
#include <iostream>
#include "Zwierze.h"

class Czlowiek : public Zwierze {
	int odlicznanieDoUmiejetnosci = 0;
	int stanPoczatkowy;//set
	bool czyUmiejetnoscAktywna = false;
	
public:
	Czlowiek(int pozX, int pozY, Swiat* swiat, int wiek);
	Czlowiek(int sila, int inicjatywa, int pozX, int pozY, Swiat* swiat, char symbol, int wiek, int odliczanieDoUmiejetnosci, int stanPoczatkowy, bool czyUmiejetnoscAktywna);
	//Czlowiek(int pozX, int pozY, Swiat* swiat, int wiek, int odlicznanieDoUmiejetnosci, int stanPoczatkowy, bool czyUmiejetnoscAktywna);
	void akcja() override;
	//void kolizja(Organizm* a) override;
	void rysowanie() override;
	//bool czyUmiejetnoscAktywowana();
	//void MagicznyEliksir();
	Organizm* kopiuj() override;
	string serializuj() {
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