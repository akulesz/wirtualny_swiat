#include <iostream>
#include "Zwierze.h"
#include "Antylopa.h"
using namespace std;

Antylopa::Antylopa(int pozX, int pozY, Swiat* swiat, int wiek) : Zwierze(4, 4, pozX, pozY, swiat, 'A', wiek) {};
void Antylopa::akcja() {
	Random r(1, 4);
	switch (r.GetRandomNumber()) {
		int tmp;
	case 1:
		//ruch w gore
		if (pozY != 0 && pozY!=1) {
			tmp = pozY;
			pozY = pozY - 2;
			swiat->przesun(pozX, tmp, pozX, pozY);
			//swiat_o.map[pozX, pozY+1] = this
		}
		else
			tmp = pozY;
		pozY += 2;
		swiat->przesun(pozX, tmp, pozX, pozY);
		break;

	case 2:
		//ruch w dol
		if (pozY != swiat->getM().y - 1 && pozY!= swiat->getM().y-2 ) {
			tmp = pozY;
			pozY += 2;
			swiat->przesun(pozX, tmp, pozX, pozY);
		}
		else
			tmp = pozY;
		pozY = pozY - 2;
		swiat->przesun(pozX, tmp, pozX, pozY);
		break;

	case 3:
		//ruch w prawo
		if (pozX != swiat->getM().x - 1 && pozX!=swiat->getM().x-2) {
			tmp = pozX;
			pozX += 2;
			swiat->przesun(tmp, pozY, pozX, pozY);
		}
		else
			tmp = pozX;
		pozX += 2;
		swiat->przesun(pozX, tmp, pozX, pozY);
		break;

	case 4:
		//ruch w lewo
		if (pozX != 0 && pozX!=1) {
			tmp = pozX;
			pozX = pozX - 2;
			swiat->przesun(tmp, pozY, pozX, pozY);
		}
		else
			tmp = pozX;
		pozX += 2;
		swiat->przesun(tmp, pozY, pozX, pozY);
		break;
	}
};
void Antylopa::kolizja(Organizm* a) {};
void Antylopa::rysowanie() {
	cout << 'A';
};

