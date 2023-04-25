#pragma once
#include "Swiat.h"
#include "Zwierze.h"

class Zolw : public Zwierze {
private:
	int licznik = 0;
public:
	Zolw(int pozX, int pozY, Swiat* swiat, int wiek);
	Zolw(int sila, int inicjatywa, int pozX, int pozY, Swiat* swiat, char symbol, int wiek,int licznik);
	void akcja() override;
	//void kolizja(Organizm* a) override;
	void rysowanie() override;
	bool czyOdbilAtak(Organizm* agresor);
	Organizm* kopiuj() override;
	string serializuj() {
		return std::to_string(sila) + ' ' +
			std::to_string(inicjatywa) + ' ' +
			std::to_string(pozX) + ' ' +
			std::to_string(pozY) + ' ' +
			symbol + ' ' +
			std::to_string(wiek) + ' ' +
			std::to_string(zyje) + ' ' +
			std::to_string(licznik);
		
	}
};