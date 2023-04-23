#include <iostream>
#include "BarszczSosnowskiego.h"
using namespace std;

BarszczSosnowskiego::BarszczSosnowskiego(int pozX, int pozY, Swiat* swiat, int wiek) : Roslina(10, 0, pozX, pozY, swiat, 'B', wiek) {};
void BarszczSosnowskiego::akcja() {};
void BarszczSosnowskiego::kolizja(Organizm* a) {};
void BarszczSosnowskiego::rysowanie() {
	cout << 'B';
};

