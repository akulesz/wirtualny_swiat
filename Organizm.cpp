#include "Organizm.h"

Organizm::Organizm(int sila, int inicjatywa, int pozX, int pozY, Swiat* swiat, char symbol, int wiek, bool zyje)
{
	this->sila = sila;
	this->inicjatywa = inicjatywa;
	this->pozX = pozX;
	this->pozY = pozY;
	this->swiat = swiat;
	this->symbol = symbol;
	this->wiek = wiek;
	this->zyje = zyje;
}

void Organizm::setpozX(int X) {
	this->pozX = X;
}

int Organizm::getpozX() {
	return this->pozX;
}
void Organizm::setpozY(int Y) {
	this->pozY = Y;
}

int Organizm::getpozY() {
	return this->pozY;
}

int Organizm::getInicjatywa() {
	return this->inicjatywa;
}

int Organizm::getWiek() {
	return this->wiek;
}

void Organizm::setWiek(int wiek) {
	this->wiek = wiek;
}

int Organizm::getSila() {
	return this->sila;
}

void Organizm::setSila(int sila) {
	this->sila = sila;
}

char Organizm::getSymbol() {
	return this->symbol;
}

bool Organizm::czyWiekWystarczajacy(Organizm* a, Organizm* b) {
	if (a->getWiek() > 3 && b->getWiek() > 3) {
		return true;
	}
	else return false;
}

string Organizm::JakiOrganizm() {
	string nazwa;
	switch (symbol) {
	case 'C':
		nazwa = "CZLOWIEK";
		break;
	case 'O':
		nazwa = "OWCA";
		break;
	case 'W':
		nazwa = "WILK";
		break;
	case 'L':
		nazwa = "LIS";
		break;
	case 'A':
		nazwa = "ANTYLOPA";
		break;
	case 'Z':
		nazwa = "ZOLW";
		break;
	case 'T':
		nazwa = "TRAWA";
		break;
	case 'M':
		nazwa = "MLECZ";
		break;
	case 'B':
		nazwa = "BARSZCZ SOSNOWSKIEGO";
		break;
	case 'J':
		nazwa = "WILCZE JAGODY";
		break;
	case 'G':
		nazwa = "GUARANA";
		break;
	}
	
	return nazwa;
}

bool Organizm::getZyje() {
	return this->zyje;
}

void Organizm::setZyje(bool zyje) {
	this->zyje = zyje;
}

void Organizm::setSwiat(Swiat* swiat) {
	this->swiat = swiat;
}