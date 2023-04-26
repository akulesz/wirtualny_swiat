#include <iostream>
#include "Wilk.h"
using namespace std;

Wilk::Wilk(int pozX, int pozY, Swiat* swiat, int wiek, bool zyje) : Zwierze(9, 5, pozX, pozY, swiat, 'W', wiek,zyje) {}
Wilk::Wilk(int sila, int inicjatywa, int pozX, int pozY, Swiat* swiat, char symbol, int wiek, bool zyje) : Zwierze(sila, inicjatywa, pozX, pozY, swiat, symbol, wiek,zyje) {}

void Wilk::rysowanie() { 
	cout << 'W';
}

Organizm* Wilk::kopiuj() {
	return new Wilk(pozX, pozY, swiat, 0, true);
}
