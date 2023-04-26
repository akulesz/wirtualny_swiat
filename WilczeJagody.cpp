#include <iostream>
#include "WilczeJagody.h"
using namespace std;

WilczeJagody::WilczeJagody(int pozX, int pozY, Swiat* swiat, int wiek, bool zyje) : Roslina(99, 0, pozX, pozY, swiat, 'J', wiek, zyje) {}
WilczeJagody::WilczeJagody(int sila, int inicjatywa, int pozX, int pozY, Swiat* swiat, char symbol, int wiek, bool zyje) : Roslina(sila, inicjatywa, pozX, pozY, swiat, symbol, wiek,zyje) {}

void WilczeJagody::rysowanie() {
	cout << 'J';
}

Roslina* WilczeJagody::kopiuj() {
	return new WilczeJagody(pozX, pozY, swiat, 0, true);
}

bool WilczeJagody::czyOtrul(Organizm *a) {
	return true;
}