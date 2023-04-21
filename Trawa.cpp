#include <iostream>
#include "Trawa.h"
using namespace std;

Trawa::Trawa(int pozX, int pozY, Swiat* swiat, int wiek) : Roslina(0, 0, pozX, pozY, swiat, 'T', wiek) {};
void Trawa::akcja() {};
void Trawa::kolizja(Organizm* a) {};
void Trawa::rysowanie() {
	cout << 'T';
};

