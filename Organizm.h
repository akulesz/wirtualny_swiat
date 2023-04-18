#pragma once
#include "Swiat.h"

//class Swiat;

class Organizm {
protected:
	int sila;
	int inicjatywa;
	int pozX;
	int pozY;
	Swiat* swiat;
	//referencja do swiata ????
	

public:
	Organizm(int sila, int inicjatywa, int pozX, int pozY, Swiat* swiat);
	virtual void akcja();
	virtual void kolizja(Organizm *a);
	virtual void rysowanie();

	virtual ~Organizm();

};