#include <iostream>
#include "Mlecz.h"
using namespace std;

Mlecz::Mlecz(int pozX, int pozY, Swiat* swiat, int wiek) : Roslina(0, 0, pozX, pozY, swiat, 'M', wiek) {};
void Mlecz::akcja() {};
void Mlecz::kolizja(Organizm* a) {};
void Mlecz::rysowanie() {
	cout << 'M';

};

