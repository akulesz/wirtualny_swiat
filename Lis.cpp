#include <iostream>
#include "Lis.h"
using namespace std;

Lis::Lis(int pozX, int pozY, Swiat* swiat, int wiek, bool zyje) : Zwierze(3, 7, pozX, pozY, swiat, 'L', wiek,  zyje) {}
Lis::Lis(int sila, int inicjatywa, int pozX, int pozY, Swiat* swiat, char symbol, int wiek, bool zyje) :Zwierze(sila, inicjatywa, pozX, pozY, swiat, symbol, wiek, zyje) {}
void Lis::akcja() {
	Random r(1, 4);
	int randomNumber = r.GetRandomNumber();
	switch (randomNumber) {
	case 1:
		//ruch w gore
		if (swiat->czyPoleJestCzesiaMapy(pozX, pozY - 1)) {
			if(czyJestSilniejszyOd(pozX, pozY - 1))
			swiat->przesun(pozX, pozY, pozX, pozY - 1);
		}
		else {
			if(czyJestSilniejszyOd(pozX, pozY + 1))
			swiat->przesun(pozX, pozY, pozX, pozY + 1);
		}
		break;

	case 2:
		//ruch w dol
		if (swiat->czyPoleJestCzesiaMapy(pozX, pozY + 1)) {
			if(czyJestSilniejszyOd(pozX, pozY + 1))
			swiat->przesun(pozX, pozY, pozX, pozY + 1);
		}
		else {
			if(czyJestSilniejszyOd(pozX, pozY - 1))
			swiat->przesun(pozX, pozY, pozX, pozY - 1);
		}
		break;

	case 3:
		//ruch w prawo
		if (swiat->czyPoleJestCzesiaMapy(pozX + 1, pozY)) {
			if(czyJestSilniejszyOd(pozX+1, pozY))
			swiat->przesun(pozX, pozY, pozX + 1, pozY);
		}
		else {
			if(czyJestSilniejszyOd(pozX - 1, pozY))
			swiat->przesun(pozX, pozY, pozX - 1, pozY);
		}
		break;

	case 4:
		//ruch w lewo
		if (swiat->czyPoleJestCzesiaMapy(pozX - 1, pozY)) {
			if (czyJestSilniejszyOd(pozX - 1, pozY))
			swiat->przesun(pozX, pozY, pozX - 1, pozY);
		}
		else {
			if (czyJestSilniejszyOd(pozX + 1, pozY))
			swiat->przesun(pozX, pozY, pozX + 1, pozY);
		}
		break;
	}
}

bool Lis::czyJestSilniejszyOd(int targetX, int targetY) {
	Organizm* target = swiat->getOrganizm(targetX, targetY);
	if (target == nullptr) return true;

	else if (sila >= target->getSila())
		return true;
	else return false;
}

void Lis::rysowanie() {
	cout << 'L';
}

Organizm* Lis::kopiuj() {
	return new Lis(pozX, pozY, swiat, 0, true);
}