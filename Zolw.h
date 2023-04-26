#pragma once
#include "Swiat.h"
#include "Zwierze.h"

class Zolw : public Zwierze {
private:
	int licznik = 0;
public:
	Zolw(int pozX, int pozY, Swiat* swiat, int wiek, bool zyje);
	Zolw(int sila, int inicjatywa, int pozX, int pozY, Swiat* swiat, char symbol, int wiek, bool zyje,int licznik);
	void akcja() override;
	void rysowanie() override;
	bool czyOdbilAtak(Organizm* agresor) override;
	Organizm* kopiuj() override;

	string serializuj() override {
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