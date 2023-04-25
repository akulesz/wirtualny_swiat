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

	cout << "Wykonaj swoj ruch!";

	//https://stackoverflow.com/a/54581468
	int c = _getch();
	if (!(c && c != 224)) {
		c = _getch();
	}
	cout << endl;
	switch (c) {
	case KEY_UP:
		if (swiat->czyPoleJestCzesiaMapy(pozX, pozY - 1)) {
			swiat->przesun(pozX, pozY, pozX, pozY - 1);
		}
		break;
	case KEY_DOWN:
		if (swiat->czyPoleJestCzesiaMapy(pozX, pozY + 1)) {
			swiat->przesun(pozX, pozY, pozX, pozY + 1);
		}
		break;
	case KEY_LEFT:
		if (swiat->czyPoleJestCzesiaMapy(pozX - 1, pozY)) {
			swiat->przesun(pozX, pozY, pozX - 1, pozY);
		}
		break;
	case KEY_RIGHT:
		if (swiat->czyPoleJestCzesiaMapy(pozX + 1, pozY)) {
			swiat->przesun(pozX, pozY, pozX + 1, pozY);
		}
		break;
	default:
		break;
	}

	//if (odlicznanieDoUmiejetnosci < 5) {
	//	odlicznanieDoUmiejetnosci++;
	//}
	//if (odlicznanieDoUmiejetnosci == 5) {
	//	czyUmiejetnoscAktywowana();
	//}
}
//void Czlowiek::kolizja(Organizm* a) {};
void Czlowiek::rysowanie() {
	cout << (char)2;
}
//bool Czlowiek::czyUmiejetnoscAktywowana() {
//	//czytaj znak jesli U to tak jesli nie to nie
//
//
//}
//void Czlowiek::MagicznyEliksir() {
//
//}
Organizm* Czlowiek::kopiuj() {
	return new Czlowiek(pozX, pozY, swiat, 0);
};