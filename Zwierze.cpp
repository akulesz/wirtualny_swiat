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

Zwierze::Zwierze(int sila, int inicjatywa, int pozX, int pozY, Swiat* swiat, char symbol, int wiek,bool zyje) : Organizm(sila, inicjatywa, pozX, pozY, swiat, symbol, wiek,zyje) {}

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

	if (broniacy->czyOtrul(agresor)) { 
		swiat->zabijOrganizm(agresor); 
	}

	else if (broniacy->czyOdbilAtak(agresor)) {
		return;
	}

	else if (broniacy->czyUciekl(agresor)) {
		swiat->przesun(agresor->getpozX(), agresor->getpozY(), x, y);
	}
		
	else if (czyWzmocnil(agresor)) {
		agresor->setSila(agresor->getSila() + 3);
	}

	else if (agresor->getSymbol() == broniacy->getSymbol()) {
		if (czyWiekWystarczajacy(agresor, broniacy)) {
			swiat->rozmnazanie(agresor, broniacy);
		}
		else return;
	}

	else if (agresor->getSila() >= broniacy->getSila()) {
		swiat->zabijOrganizm(broniacy);
		swiat->przesun(agresor->getpozX(), agresor->getpozY(), x, y);
		swiat->dodajPowiadomienie("Organizm " + agresor->JakiOrganizm() + " zabil " +broniacy->JakiOrganizm()+".");
	}

	else{ //agresor ma wieksza sile od broniacego
		swiat->zabijOrganizm(agresor);
	}
}

void Zwierze::rysowanie() {};




 