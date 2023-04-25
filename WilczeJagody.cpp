#include <iostream>
#include "WilczeJagody.h"
using namespace std;

WilczeJagody::WilczeJagody(int pozX, int pozY, Swiat* swiat, int wiek) : Roslina(99, 0, pozX, pozY, swiat, 'J', wiek) {}
WilczeJagody::WilczeJagody(int sila, int inicjatywa, int pozX, int pozY, Swiat* swiat, char symbol, int wiek) : Roslina(sila, inicjatywa, pozX, pozY, swiat, symbol, wiek) {};
//void WilczeJagody::akcja() {}
//void WilczeJagody::kolizja(Organizm* a) {}
void WilczeJagody::rysowanie() {
	cout << 'J';
}

Roslina* WilczeJagody::kopiuj() {
	return new WilczeJagody(pozX, pozY, swiat, 0);
}

bool WilczeJagody::czyOtrul() {
	return true;
}