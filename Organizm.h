#pragma once
#include <string>
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
	bool zyje = true;

public:
	Organizm(int sila, int inicjatywa, int pozX, int pozY, Swiat* swiat, char symbol, int wiek);
	virtual void akcja() = 0;
	virtual void kolizja(Organizm* a) = 0;
	virtual void rysowanie() = 0;
	void setpozX(int X);
	int getpozX();
	void setpozY(int Y);
	int getpozY();
	int getInicjatywa();
	int getWiek();
	void setWiek(int wiek);
	int getSila();
	void setSila(int sila);
	char getSymbol();
	string JakiOrganizm();
	virtual Organizm* kopiuj() = 0;
	bool getZyje();
	void setZyje(bool zyje);
	bool czyOdbilAtak(Organizm* agresor) {
		return false;
	}
	bool czyUciekl(Organizm* agresor) {
		return false;
	}
	bool czyOtrul(Organizm* a) {
		return false;
	}
	bool czyWzmocnil(Organizm* a) {
		return false;
	}
	string serializuj() {
		return std::to_string(sila) + ' ' +
			std::to_string(inicjatywa) + ' ' +
			std::to_string(pozX) + ' ' +
			std::to_string(pozY) + ' ' +
			symbol + ' ' +
			std::to_string(wiek) + ' ' +
			std::to_string(zyje);
	}
};