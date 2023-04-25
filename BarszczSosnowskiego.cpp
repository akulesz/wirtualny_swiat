#include <iostream>
#include "BarszczSosnowskiego.h"
using namespace std;

BarszczSosnowskiego::BarszczSosnowskiego(int pozX, int pozY, Swiat* swiat, int wiek) : Roslina(10, 0, pozX, pozY, swiat, 'B', wiek) {};
void BarszczSosnowskiego::akcja() {
	if (swiat->czyPoleJestCzesiaMapy(pozX, pozY+1) && !swiat->czyPustePole(pozX, pozY + 1)) {
		swiat->zabijOrganizm(swiat->getOrganizm(pozX, pozY + 1));
	}
	if (swiat->czyPoleJestCzesiaMapy(pozX, pozY-1) && !swiat->czyPustePole(pozX, pozY - 1)) {
		swiat->zabijOrganizm(swiat->getOrganizm(pozX, pozY - 1));
	}
	if (swiat->czyPoleJestCzesiaMapy(pozX+1, pozY - 1) && !swiat->czyPustePole(pozX+1, pozY)) {
		swiat->zabijOrganizm(swiat->getOrganizm(pozX+1, pozY));
	}
	if (swiat->czyPoleJestCzesiaMapy(pozX-1, pozY) && !swiat->czyPustePole(pozX-1, pozY)) {
		swiat->zabijOrganizm(swiat->getOrganizm(pozX-1, pozY));
	}

};
void BarszczSosnowskiego::kolizja(Organizm* a) {};
void BarszczSosnowskiego::rysowanie() {
	cout << 'B';
};
Roslina* BarszczSosnowskiego::kopiuj() {
	return new BarszczSosnowskiego(pozX, pozY, swiat, 0);
};

