#include <iostream>
#include "Zwierze.h"
#include "Zolw.h"
using namespace std;

Zolw::Zolw(int pozX, int pozY, Swiat* swiat, int wiek) : Zwierze(2, 1, pozX, pozY, swiat, 'Z', wiek) {};
void Zolw::akcja() {
	
	if (licznik == 4)
	{
		Random r(1, 4);
		switch (r.GetRandomNumber()) {
			int tmp;
		case 1:
			//ruch w gore
			if (pozY != 0) {
				tmp = pozY;
				pozY = pozY - 1;
				swiat->przesun(pozX, tmp, pozX, pozY);
				//swiat_o.map[pozX, pozY+1] = this
			}
			else
				tmp = pozY;
			pozY += 1;
			swiat->przesun(pozX, tmp, pozX, pozY);
			break;

		case 2:
			//ruch w dol
			if (pozY != swiat->getM().y - 1) {
				tmp = pozY;
				pozY += 1;
				swiat->przesun(pozX, tmp, pozX, pozY);
			}
			else
				tmp = pozY;
			pozY = pozY - 1;
			swiat->przesun(pozX, tmp, pozX, pozY);
			break;

		case 3:
			//ruch w prawo
			if (pozX != swiat->getM().x - 1) {
				tmp = pozX;
				pozX += 1;
				swiat->przesun(tmp, pozY, pozX, pozY);
			}
			else
				tmp = pozX;
			pozX += 1;
			swiat->przesun(pozX, tmp, pozX, pozY);
			break;

		case 4:
			//ruch w lewo
			if (pozX != 0) {
				tmp = pozX;
				pozX = pozX - 1;
				swiat->przesun(tmp, pozY, pozX, pozY);
			}
			else
				tmp = pozX;
			pozX += 1;
			swiat->przesun(tmp, pozY, pozX, pozY);
			break;
		}
		licznik = 1;
	}
	else licznik++;
};
void Zolw::kolizja(Organizm* a) {};
void Zolw::rysowanie() {
	cout << 'Z';
};

