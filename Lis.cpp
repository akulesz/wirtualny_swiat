#include <iostream>
#include "Lis.h"
using namespace std;

Lis::Lis(int pozX, int pozY, Swiat* swiat, int wiek) : Zwierze(3, 7, pozX, pozY, swiat, 'L', wiek) {};
void Lis::akcja() {
	//przed wykonaniem ruchu Lis.sila> organizm.sila
};
void Lis::kolizja(Organizm *a) {};
void Lis::rysowanie() {
	cout << 'L';
};
