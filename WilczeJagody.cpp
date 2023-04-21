#include <iostream>
#include "WilczeJagody.h"
using namespace std;

WilczeJagody::WilczeJagody(int pozX, int pozY, Swiat* swiat, int wiek) : Roslina(0, 99, pozX, pozY, swiat, 'J', wiek) {};
void WilczeJagody::akcja() {};
void WilczeJagody::kolizja(Organizm* a) {};
void WilczeJagody::rysowanie() {
	cout << 'J';
};

