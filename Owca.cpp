#include <iostream>
#include "Owca.h"
using namespace std;

Owca::Owca(int pozX, int pozY, Swiat* swiat, int wiek) : Zwierze(4, 4, pozX, pozY, swiat, 'O', wiek) {}
Owca::Owca(int sila, int inicjatywa, int pozX, int pozY, Swiat* swiat, char symbol, int wiek) : Zwierze(sila, inicjatywa, pozX, pozY, swiat, symbol, wiek) {};
//void Owca::akcja() {}
//void Owca::kolizja(Organizm* a) {}
void Owca::rysowanie() {
	cout << 'O';
}
Organizm* Owca::kopiuj() {
	return new Owca(pozX, pozY, swiat, 0);
}
