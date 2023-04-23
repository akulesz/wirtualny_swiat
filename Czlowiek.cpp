#include <iostream>
#include <conio.h>
#include "Zwierze.h"
#include "Czlowiek.h"
using namespace std;

Czlowiek::Czlowiek(int pozX, int pozY, Swiat* swiat, int wiek) : Zwierze(5, 4, pozX, pozY, swiat, 'C', wiek) {};

void Czlowiek::akcja() {
	//char znak;
	//int tmp;
	////unsigned char znak = getchar();
	//cout << "gdzie chcesz sie ruszyc? :";
	//cin >> znak;

	//if (znak == 72) { //gora
	//	if (pozY != 0) {
	//		tmp = pozY;
	//		pozY = pozY - 1;
	//		swiat->przesun(pozX, tmp, pozX, pozY);
	//	}	
	//}
	//else if (znak == 66) { //dol
	//	if (pozY != swiat->getM().y ) {
	//		tmp = pozY;
	//		pozY = pozY + 1;
	//		swiat->przesun(pozX, tmp, pozX, pozY);
	//	}
	//}
	//else if (znak == 67) { //prawo
	//	if (pozX != swiat->getM().x) {
	//		tmp = pozX;
	//		pozY = pozX + 1;
	//		swiat->przesun(pozX, tmp, pozX, pozY);
	//	}
	//}
	//else if (znak == 68) { //lewo
	//	if (pozX != 0 ) {
	//		tmp = pozX;
	//		pozY = pozX + 1;
	//		swiat->przesun(pozX, tmp, pozX, pozY);
	//	}
	//}
	return;
}
void Czlowiek::kolizja(Organizm* a) {};
void Czlowiek::rysowanie() {
	cout << (char)2;
};
