#include <iostream>
#include "Owca.h"
using namespace std;

Owca::Owca(int pozX, int pozY, Swiat* swiat, int wiek, bool zyje) : Zwierze(4, 4, pozX, pozY, swiat, 'O', wiek, zyje) {}
Owca::Owca(int sila, int inicjatywa, int pozX, int pozY, Swiat* swiat, char symbol, int wiek, bool zyje) : Zwierze(sila, inicjatywa, pozX, pozY, swiat, symbol, wiek,zyje) {}

void Owca::rysowanie() {
	cout << 'O';
}

Organizm* Owca::kopiuj() {
	return new Owca(pozX, pozY, swiat, 0,true);	
}
