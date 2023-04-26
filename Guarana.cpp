#include <iostream>
#include "Guarana.h"
using namespace std;

Guarana::Guarana(int pozX, int pozY, Swiat* swiat, int wiek, bool zyje) : Roslina(0, 0, pozX, pozY, swiat, 'G', wiek, zyje) {}
Guarana::Guarana(int sila, int inicjatywa, int pozX, int pozY, Swiat* swiat, char symbol, int wiek, bool zyje) : Roslina(sila, inicjatywa, pozX, pozY, swiat, symbol, wiek, zyje) {}

void Guarana::rysowanie() {
	cout << 'G';
}

Roslina* Guarana::kopiuj() {
	return new Guarana(pozX, pozY, swiat, 0, true);
}

bool Guarana::czyWzmocnil(Organizm*a) {
	return true;
}
