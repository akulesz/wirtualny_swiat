#include <iostream>
#include "Wilk.h"
using namespace std;

Wilk::Wilk(int pozX, int pozY, Swiat* swiat, int wiek) : Zwierze(9, 5, pozX, pozY, swiat, 'W', wiek) {}
Wilk::Wilk(int sila, int inicjatywa, int pozX, int pozY, Swiat* swiat, char symbol, int wiek) : Zwierze(sila, inicjatywa, pozX, pozY, swiat, symbol, wiek) {};
//void Wilk::akcja() {}
//void Wilk::kolizja(Organizm *a) {}
void Wilk::rysowanie() { 
	cout << 'W';
}
Organizm* Wilk::kopiuj() {
	return new Wilk(pozX, pozY, swiat, 0);
}
