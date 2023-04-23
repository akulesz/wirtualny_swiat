#include <iostream>
#include "Mlecz.h"
using namespace std;

Mlecz::Mlecz(int pozX, int pozY, Swiat* swiat, int wiek) : Roslina(0, 0, pozX, pozY, swiat, 'M', wiek) {};
void Mlecz::akcja() {
	int ruchMozliwy = false;
	int proba = 0;
	do {
		Random r(1, 4);
		int tmp;
		switch (r.GetRandomNumber()) {
		case 1: //gora
			if (pozY != 0) {
				ruchMozliwy = true;
				proba++;
				swiat->rozprzestrzenianie(swiat->getOrganizm(pozX, pozY), pozX, pozY - 1);//chce stworzyc nowy organizm //musze sprawdzic czy to pole jest puste   
				//musze dodac go do wektora 
			}
			break;
		case 2: //dol
			if (pozY != swiat->getM().y - 1) {
				ruchMozliwy = true;
				proba++;
				swiat->rozprzestrzenianie(swiat->getOrganizm(pozX, pozY), pozX, pozY + 1);
			}
			break;
		case 3: //prawo
			if (pozY != swiat->getM().x - 1) {
				ruchMozliwy = true;
				proba++;
				swiat->rozprzestrzenianie(swiat->getOrganizm(pozX, pozY), pozX + 1, pozY);

			}
			break;
		case 4: //lewo
			if (pozY != 0) {
				ruchMozliwy = true;
				proba++;
				swiat->rozprzestrzenianie(swiat->getOrganizm(pozX, pozY), pozX - 1, pozY);
			}
			break;
		}

	} while (ruchMozliwy != true&& proba!=2);

	return;
};
void Mlecz::kolizja(Organizm* a) {};
void Mlecz::rysowanie() {
	cout << 'M';
};

