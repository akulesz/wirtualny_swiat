#pragma once
#include <string>
#include "Swiat.h"

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
	Organizm(int sila, int inicjatywa, int pozX, int pozY, Swiat* swiat, char symbol, int wiek, bool zyje);
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
	void setSwiat(Swiat* swiat);
	bool czyWiekWystarczajacy(Organizm* a, Organizm* b);
	string JakiOrganizm();
	virtual Organizm* kopiuj() = 0;
	bool getZyje();
	void setZyje(bool zyje);

	virtual bool czyOdbilAtak(Organizm* agresor) {
		return false;
	}

	virtual bool czyUciekl(Organizm* agresor) {
		return false;
	}

	virtual bool czyOtrul(Organizm* a) {
		return false;
	}

	virtual bool czyWzmocnil(Organizm* a) {
		return false;
	}

	virtual string serializuj() {
		return std::to_string(sila) + ' ' +
			std::to_string(inicjatywa) + ' ' +
			std::to_string(pozX) + ' ' +
			std::to_string(pozY) + ' ' +
			symbol + ' ' +
			std::to_string(wiek) + ' ' +
			std::to_string(zyje);
	}
};