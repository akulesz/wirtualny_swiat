#include <iostream>
#include "Trawa.h"
using namespace std;

Trawa::Trawa(int pozX, int pozY, Swiat* swiat, int wiek, bool zyje) : Roslina(0, 0, pozX, pozY, swiat, 'T', wiek, zyje) {}
Trawa::Trawa(int sila, int inicjatywa, int pozX, int pozY, Swiat* swiat, char symbol, int wiek, bool zyje) : Roslina(sila, inicjatywa, pozX, pozY, swiat, symbol, wiek, zyje) {}

void Trawa::rysowanie() {
	cout << 'T';
}

Roslina* Trawa::kopiuj() {

	return new Trawa(pozX, pozY, swiat, 0, true);
}

