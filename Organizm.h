#pragma once
#include "Swiat.h"
#include <iostream>

class Swiat;

class Organizm {
protected:
	int sila;
	int inicjatywa;
	int pozX;
	int pozY;
	Swiat* swiat;
	//referencja do swiata ????
	

public:
	Organizm(int sila, int inicjatywa, int pozX, int pozY, Swiat* swiat) {
		this->sila = sila;
		//...
		//this->swiat = swiat;
	}
	virtual void akcja() = 0;
	virtual void kolizja(Organizm *a) = 0;
	virtual void rysowanie() = 0;

	virtual ~Organizm() {};

};