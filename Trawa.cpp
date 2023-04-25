#include <iostream>
#include "Trawa.h"
using namespace std;

Trawa::Trawa(int pozX, int pozY, Swiat* swiat, int wiek) : Roslina(0, 0, pozX, pozY, swiat, 'T', wiek) {}
Trawa::Trawa(int sila, int inicjatywa, int pozX, int pozY, Swiat* swiat, char symbol, int wiek) : Roslina(sila, inicjatywa, pozX, pozY, swiat, symbol, wiek) {};
//void Trawa::akcja() {}
//void Trawa::kolizja(Organizm* a) {}
void Trawa::rysowanie() {
	cout << 'T';
}

Roslina* Trawa::kopiuj() {

	return new Trawa(pozX, pozY, swiat, 0);
}

