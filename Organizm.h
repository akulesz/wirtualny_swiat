#pragma once
#include "Swiat.h"

// class Swiat;

class Organizm {
protected:
	int sila;
	int inicjatywa;
	int pozX;
	int pozY;
	Swiat* swiat;
	char symbol;
	int wiek;

public:
	Organizm(int sila, int inicjatywa, int pozX, int pozY, Swiat* swiat, char symbol, int wiek);
	virtual void akcja() = 0;
	virtual void kolizja(Organizm* a) = 0;
	virtual void rysowanie() = 0;
	void setpozX(int X);
	void setpozY(int Y);
};