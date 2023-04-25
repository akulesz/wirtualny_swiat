#include "Swiat.h"
#include "Organizm.h"
#include "Zwierze.h"
#include "Random.h"
#include "BarszczSosnowskiego.h"
#include "Zolw.h"
#include "WilczeJagody.h"
#include "Antylopa.h"
#include "Guarana.h"
using namespace std;
//class Swiat;

	Zwierze::Zwierze(int sila, int inicjatywa, int pozX, int pozY, Swiat* swiat, char symbol, int wiek) : Organizm(sila, inicjatywa, pozX, pozY, swiat, symbol, wiek) {
	
	}

	 void Zwierze::akcja() {
		Random r(1, 4);
		int randomNumber = r.GetRandomNumber();
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
			if (swiat->czyPoleJestCzesiaMapy(pozX+1, pozY )) {
				swiat->przesun(pozX, pozY, pozX+1, pozY );
			}
			else {
				swiat->przesun(pozX, pozY, pozX-1, pozY );
			}
			break;

		case 4:
			//ruch w lewo
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

		int x = broniacy->getpozX();
		int y = broniacy->getpozY();

		BarszczSosnowskiego* B = dynamic_cast<BarszczSosnowskiego*>(broniacy);
		Zolw* Z = dynamic_cast<Zolw*>(broniacy);
		WilczeJagody* J = dynamic_cast<WilczeJagody*>(broniacy);
		Antylopa* A = dynamic_cast<Antylopa*>(broniacy);
		Guarana* G = dynamic_cast<Guarana*>(broniacy);

		if (B != nullptr||J!=nullptr) { //barszcz
			swiat->zabijOrganizm(agresor); 
		}

		else if (Z != nullptr) { //zolw
			if (Z->czyOdbilAtak(agresor) == false) {
				swiat->zabijOrganizm(broniacy);
				swiat->przesun(agresor->getpozX(), agresor->getpozY(), x, y);
			}
			else {
				//swiat->powiadomienia.push_back("Organizm " + a->JakiOrganizm() + " umiera.");
				return;
			}
		}

		else if (A != nullptr) {
			if (A->czyUciekla(agresor) == true) {
				//przesun antylope na pole !!!to robie w antylopie, czyli to robi funkcja czyUciekla
				//agresor na miejscu antylopy
				swiat->przesun(agresor->getpozX(), agresor->getpozY(), x, y);
			}
			else {
				swiat->zabijOrganizm(broniacy);
				swiat->przesun(agresor->getpozX(), agresor->getpozY(), x, y);
			}
		}

		else if (G != nullptr) {
			agresor->setSila(agresor->getSila() + 3);

		}
		else if (agresor->getSymbol() == broniacy->getSymbol()) {
			swiat->rozmnazanie(agresor,broniacy);
		}

		else if (agresor->getSila() >= broniacy->getSila()) {
			//agresor zabija broniacego i wskakuje na jego miejsce
			swiat->zabijOrganizm(broniacy);
			swiat->przesun(agresor->getpozX(), agresor->getpozY(), x, y);
		}

		else{ //agresor ma wieksza sile od broniacego
			swiat->zabijOrganizm(agresor);
		}


		//// jezeli broniacy jest zolwiem i sila agresora < 5 => return;
		//Zolw* x = dynamic_cast<Zolw*>(broniacy);
		//if (x != nullptr) {
		//	if (this->sila < 5)
		//		return;
		//}//jezeli to nie jest zolw tylko np jakias roslina to x=nullptr
		//WilczeJagody* b = dynamic_cast<WilczeJagody*>(broniacy);

	}
	void Zwierze::rysowanie() {};




 