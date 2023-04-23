#include <iostream>
#include "Guarana.h"
using namespace std;

Guarana::Guarana(int pozX, int pozY, Swiat* swiat, int wiek) : Roslina(0, 0, pozX, pozY, swiat, 'G', wiek) {};
void Guarana::akcja() {};
void Guarana::kolizja(Organizm* a) {};
void Guarana::rysowanie() {
	cout << 'G';
}; Roslina* Guarana::kopiuj() {
	return new Guarana(pozX, pozY, swiat, 0);
};

