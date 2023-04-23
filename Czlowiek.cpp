#include <iostream>
#include <conio.h>
#include "Zwierze.h"
#include "Czlowiek.h"

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

using namespace std;

Czlowiek::Czlowiek(int pozX, int pozY, Swiat* swiat, int wiek) : Zwierze(5, 4, pozX, pozY, swiat, 'C', wiek) {};

void Czlowiek::akcja() {
	//char znak;
	int tmp;
	//unsigned char znak = getchar();
	cout << "gdzie chcesz sie ruszyc? :";
	//cin >> znak;

	// https://stackoverflow.com/a/54581468
	int c = _getch();
	if (!(c && c != 224)) {
		c = _getch();
	}
	cout << endl;

	cout << c;
	cout << endl;

	switch (c) {
	case KEY_UP:
		if (swiat->czyPoleJestCzesiaMapy(pozX, pozY - 1)) {
			swiat->przesun(pozX, pozY, pozX, pozY - 1);
		}
		break;
	case KEY_DOWN:
		break;
	case KEY_LEFT:
		break;
	case KEY_RIGHT:
		break;
	default:
		break;

	}
	

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
	//return;
}
void Czlowiek::kolizja(Organizm* a) {};
void Czlowiek::rysowanie() {
	cout << (char)2;
};
