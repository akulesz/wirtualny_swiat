#include "Organizm.h"
Organizm::Organizm(int sila, int inicjatywa, int pozX, int pozY, Swiat *swiat, char symbol, int wiek)
{
	this->sila = sila;
	this->inicjatywa = inicjatywa;
	this->pozX = pozX;
	this->pozY = pozY;
	this->swiat = swiat;
	this->symbol = symbol;
	this->wiek = wiek;
}
