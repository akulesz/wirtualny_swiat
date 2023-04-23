#include "Swiat.h"
#include "Organizm.h"
#include "Zwierze.h"
#include "Random.h"
using namespace std;
//class Swiat;

	Zwierze::Zwierze(int sila, int inicjatywa, int pozX, int pozY, Swiat* swiat, char symbol, int wiek) : Organizm(sila, inicjatywa, pozX, pozY, swiat, symbol, wiek) {

	}
	 void Zwierze::akcja() {
		Random r(1, 4);
		int randomNumber = r.GetRandomNumber();
		switch (randomNumber) {
			int tmp;
			//bool czyMozeSieRuszyc;
		case 1:
			//ruch w gore
			//czyMozeSieRuszyc = pozY != 0;
			// sprobujSiePrzesunac(int newx, int newy, int fallbackX, int fallbackY)
			if (swiat->czyPoleJestCzesiaMapy(pozX, pozY - 1)) {
				swiat->przesun(pozX, pozY, pozX, pozY - 1);
			}
			else {
				swiat->przesun(pozX, pozY, pozX, pozY + 1);
			}
			break;

		case 2:
			//ruch w dol
			//czyMozeSieRuszyc = pozY != swiat->getM().y - 1;
			if (swiat->czyPoleJestCzesiaMapy(pozX, pozY + 1)) {
				swiat->przesun(pozX, pozY, pozX, pozY + 1);
			}
			else {
				swiat->przesun(pozX, pozY, pozX, pozY - 1);
			}
			break;

		case 3:
			//ruch w prawo
			//czyMozeSieRuszyc = pozX != swiat->getM().x - 1;
			if (swiat->czyPoleJestCzesiaMapy(pozX+1, pozY )) {
				swiat->przesun(pozX, pozY, pozX+1, pozY );
			}
			else {
				swiat->przesun(pozX, pozY, pozX-1, pozY );
			}
			break;

		case 4:
			//ruch w lewo
			//czyMozeSieRuszyc = pozX != 0;
			if (swiat->czyPoleJestCzesiaMapy(pozX-1, pozY)) {
				swiat->przesun(pozX, pozY, pozX - 1, pozY);
			}
			else {
				swiat->przesun(pozX, pozY, pozX + 1, pozY);
			}
			break;
		}
	}

	void Zwierze::kolizja(Organizm* a) {
		Organizm* agresor = this;
		Organizm* broniacy = a;
		// jezeli broniacy jest zolwiem i sila agresora < 5 => return;
		Zolw* x = dynamic_cast<Zolw*>(broniacy);
		if (x != nullptr) {
			if (this->sila < 5)
				return;
		}

	}




 