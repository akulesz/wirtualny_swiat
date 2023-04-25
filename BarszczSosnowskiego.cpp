#include <iostream>
#include "BarszczSosnowskiego.h"
using namespace std;

BarszczSosnowskiego::BarszczSosnowskiego(int pozX, int pozY, Swiat* swiat, int wiek) : Roslina(10, 0, pozX, pozY, swiat, 'B', wiek) {};
BarszczSosnowskiego::BarszczSosnowskiego(int sila, int inicjatywa, int pozX, int pozY, Swiat* swiat, char symbol, int wiek) :Roslina(sila, inicjatywa, pozX, pozY, swiat, symbol, wiek) {};
void BarszczSosnowskiego::akcja() {
	if (swiat->czyStoiZwierze(pozX, pozY+1)) {
		swiat->zabijOrganizm(swiat->getOrganizm(pozX, pozY + 1));
	}
	if (swiat->czyStoiZwierze(pozX, pozY -1)) {
		swiat->zabijOrganizm(swiat->getOrganizm(pozX, pozY - 1));
	}
	if (swiat->czyStoiZwierze(pozX+1, pozY)) {
		swiat->zabijOrganizm(swiat->getOrganizm(pozX+1, pozY));
	}
	if (swiat->czyStoiZwierze(pozX-1, pozY)) {
		swiat->zabijOrganizm(swiat->getOrganizm(pozX-1, pozY));
	}

};
//void BarszczSosnowskiego::kolizja(Organizm* a) {};
void BarszczSosnowskiego::rysowanie() {
	cout << 'B';
};
Roslina* BarszczSosnowskiego::kopiuj() {
	return new BarszczSosnowskiego(pozX, pozY, swiat, 0);
};

bool BarszczSosnowskiego::czyOtrul(Organizm *a) {
	return true;
}
