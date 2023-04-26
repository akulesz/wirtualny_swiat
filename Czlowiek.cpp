#include <iostream>
#include <string>
#include <conio.h>
#include "Zwierze.h"
#include "Czlowiek.h"
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

using namespace std;

Czlowiek::Czlowiek(int pozX, int pozY, Swiat* swiat, int wiek, bool zyje) : Zwierze(5, 4, pozX, pozY, swiat, 'C', wiek, zyje) {}
Czlowiek::Czlowiek(int sila, int inicjatywa, int pozX, int pozY, Swiat* swiat, char symbol, int wiek, bool zyje, int odliczanieDoUmiejetnosci, int stanPoczatkowy, bool czyUmiejetnoscAktywna) :Zwierze(sila, inicjatywa, pozX, pozY, swiat, symbol, wiek,zyje) {}

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

	if (odlicznanieDoUmiejetnosci < 5) {
		odlicznanieDoUmiejetnosci++;
		stanPoczatkowy = sila;
	}
	magicznyEliksir();
}

void Czlowiek::magicznyEliksir() {
	char znak;
	znak = _getch();
	if (znak == '*' && odlicznanieDoUmiejetnosci == 5) {
		czyUmiejetnoscAktywna = true;
	}

	if (czyUmiejetnoscAktywna) {
		if (stanPoczatkowy <= 10) {
			sila = 11;
			sila--;
			swiat->dodajPowiadomienie("Superumiejetnosc aktywowana! ");
			if (sila == stanPoczatkowy) {
				czyUmiejetnoscAktywna = false;
				odlicznanieDoUmiejetnosci = 0;
			}
		}
	}
} 

void Czlowiek::rysowanie() {
	cout << (char)2;
}

Organizm* Czlowiek::kopiuj() {
	return new Czlowiek(pozX, pozY, swiat, 0,true);
};