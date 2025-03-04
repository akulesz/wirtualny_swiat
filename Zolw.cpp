#include <iostream>
#include "Zwierze.h"
#include "Zolw.h"
using namespace std;

Zolw::Zolw(int pozX, int pozY, Swiat* swiat, int wiek, bool zyje) : Zwierze(2, 1, pozX, pozY, swiat, 'Z', wiek, zyje) {}
Zolw::Zolw(int sila, int inicjatywa, int pozX, int pozY, Swiat* swiat, char symbol, int wiek, bool zyje, int licznik) : Zwierze(sila, inicjatywa, pozX, pozY, swiat, symbol, zyje, wiek) {}

void Zolw::akcja() {
	Random r(1, 4);
	int randomNumber = r.GetRandomNumber();
	licznik++;
	if (licznik == 3) {
		switch (randomNumber) {
		case 1:
			//ruch w gore
			if (swiat->czyPoleJestCzesiaMapy(pozX, pozY - 1)) {
				swiat->przesun(pozX, pozY, pozX, pozY - 1);
			}
			else {
				swiat->przesun(pozX, pozY, pozX, pozY + 1);
			}
			break;

		case 2:
			//ruch w dol
			if (swiat->czyPoleJestCzesiaMapy(pozX, pozY + 1)) {
				swiat->przesun(pozX, pozY, pozX, pozY + 1);
			}
			else {
				swiat->przesun(pozX, pozY, pozX, pozY - 1);
			}
			break;

		case 3:
			//ruch w prawo
			if (swiat->czyPoleJestCzesiaMapy(pozX + 1, pozY)) {
				swiat->przesun(pozX, pozY, pozX + 1, pozY);
			}
			else {
				swiat->przesun(pozX, pozY, pozX - 1, pozY);
			}
			break;

		case 4:
			//ruch w lewo
			if (swiat->czyPoleJestCzesiaMapy(pozX - 1, pozY)) {
				swiat->przesun(pozX, pozY, pozX - 1, pozY);
			}
			else {
				swiat->przesun(pozX, pozY, pozX + 1, pozY);
			}
			break;
		}
		licznik = 0;
	}
}

void Zolw::rysowanie() {
	cout << 'Z';
}

bool Zolw::czyOdbilAtak(Organizm* agresor) {
	if (agresor->getSila() < 5) {
		return true;
	}
	else return false;
}

Organizm* Zolw::kopiuj() {
	return new Zolw(pozX, pozY, swiat, 0, true);
}