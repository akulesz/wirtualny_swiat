#include <iostream>
#include "Mlecz.h"
using namespace std;

Mlecz::Mlecz(int pozX, int pozY, Swiat* swiat, int wiek) : Roslina(0, 0, pozX, pozY, swiat, 'M', wiek) {};
Mlecz::Mlecz(int sila, int inicjatywa, int pozX, int pozY, Swiat* swiat, char symbol, int wiek) : Roslina(sila, inicjatywa, pozX, pozY, swiat, symbol, wiek) {};
void Mlecz::akcja() {
	for (int i = 0; i < 3; i++) {
		Random a(0, 25); //roslina ma 5% szansy na rozmno¿enie siê
		int szansa = a.GetRandomNumber();
		if (szansa == 0) {
			bool ruchMozliwy = false; //pole na ktore chce ruszyc sie lis nie wykracza poza mape
			do {
				Random r(1, 4);
				int tmp;
				switch (r.GetRandomNumber()) {
				case 1: //gora
					if (pozY != 0) {
						ruchMozliwy = true;
						Roslina* nowa = this->kopiuj();
						swiat->rozprzestrzenianie(nowa, pozX, pozY - 1);
					}
					break;
				case 2: //dol
					if (pozY != swiat->getM().y - 1) {
						ruchMozliwy = true;
						swiat->rozprzestrzenianie(this->kopiuj(), pozX, pozY + 1);
					}
					break;
				case 3: //prawo
					if (pozX != swiat->getM().x - 1) {
						ruchMozliwy = true;
						swiat->rozprzestrzenianie(this->kopiuj(), pozX + 1, pozY);

					}
					break;
				case 4: //lewo
					if (pozX != 0) {
						ruchMozliwy = true;
						swiat->rozprzestrzenianie(this->kopiuj(), pozX - 1, pozY);
					}
					break;
				}

			} while (ruchMozliwy != true);
		}
		return;
	}
};
//void Mlecz::kolizja(Organizm* a) {};
void Mlecz::rysowanie() {
	cout << 'M';
};

Roslina* Mlecz::kopiuj() {
	return new Mlecz(pozX, pozY, swiat, 0);
};