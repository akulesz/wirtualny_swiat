#include <iostream>
#include "Zwierze.h"
#include "Antylopa.h"
using namespace std;

Antylopa::Antylopa(int pozX, int pozY, Swiat* swiat, int wiek, bool zyje) : Zwierze(4, 4, pozX, pozY, swiat, 'A', wiek,zyje) {}
Antylopa::Antylopa(int sila, int inicjatywa, int pozX, int pozY, Swiat* swiat, char symbol, int wiek, bool zyje):Zwierze(sila, inicjatywa, pozX, pozY, swiat, symbol, wiek,zyje) {}

void Antylopa::akcja() {
	Random r(1, 4);
	switch (r.GetRandomNumber()) {

	case 1:
		//ruch w gore
		if (swiat->czyPoleJestCzesiaMapy(pozX, pozY - 2)) {
			swiat->przesun(pozX, pozY, pozX, pozY - 2);
		}
		else {
			swiat->przesun(pozX, pozY, pozX, pozY + 2);
		}
		break;

	case 2:
		//ruch w dol
		if (swiat->czyPoleJestCzesiaMapy(pozX, pozY + 2)) {
			swiat->przesun(pozX, pozY, pozX, pozY + 2);
		}
		else {
			swiat->przesun(pozX, pozY, pozX, pozY - 2);
		}
		break;

	case 3:
		//ruch w prawo
		if (swiat->czyPoleJestCzesiaMapy(pozX + 2, pozY)) {
			swiat->przesun(pozX, pozY, pozX + 2, pozY);
		}
		else {
			swiat->przesun(pozX, pozY, pozX - 2, pozY);
		}
		break;

	case 4:
		//ruch w lewo
		if (swiat->czyPoleJestCzesiaMapy(pozX - 2, pozY)) {
			swiat->przesun(pozX, pozY, pozX - 2, pozY);
		}
		else {
			swiat->przesun(pozX, pozY, pozX + 2, pozY);
		}
		break;
	}
}

void Antylopa::rysowanie() {
	cout << 'A';
}

bool Antylopa::czyUciekl(Organizm *agresor) {
	Random r(1, 2);
	int ucieczka = r.GetRandomNumber();
	if (ucieczka == 1) {
		Random p(1, 4);
		int ruch = p.GetRandomNumber();
		// ruch w gore
		if (swiat->czyPustePole(pozX, pozY - 1)) {
			swiat->przesun(pozX, pozY, pozX, pozY - 1);
			return true;
		} //dol
		else if (swiat->czyPustePole(pozX, pozY + 1)) {
			swiat->przesun(pozX, pozY, pozX, pozY + 1);
			return true;
		}//lewo
		else if (swiat->czyPustePole(pozX - 1, pozY)) {
			swiat->przesun(pozX, pozY, pozX - 1, pozY);
			return true;
		}//prawo
		else if (swiat->czyPustePole(pozX + 1, pozY)) {
			swiat->przesun(pozX, pozY, pozX + 1, pozY);
			return true;
		}
		else return false;
	}
	else return false;
}

Organizm* Antylopa::kopiuj() {
	return new Antylopa(pozX, pozY, swiat, 0, true);
}