#pragma once
#include <iostream>
#include <vector>
#include "wymiary.h"
#define empty nullptr
using namespace std;
class Organizm;

struct Koordynaty {
	int x;
	int y;
};

class Swiat {
private:
	wymiary m;
	Organizm*** mapa; // mapa[m.x][m.y]
	vector<Organizm*> organizmy;
	vector<string> powiadomienia;
	int tura = 1;

public:
	Swiat(wymiary m);
	Swiat(wymiary m, vector<Organizm*>& organizmy, int tura);
	wymiary getM();
	void wykonajTure();
	void rysujSwiat();
	int getTura();
	Koordynaty znajdzPustePoleObok(Organizm* organizm);
	void setTura(int tura);
	Organizm* getOrganizm(int x, int y);
	void dodajPowiadomienie(string powiadomienie);
	bool czyPoleJestCzesiaMapy(int x, int y);
	bool czyPustePole(int x, int y);
	void przesun(int x, int y, int newx, int newy);
	void stworzNowyOrganizm(Organizm* nowy, int x, int y);
	void rozprzestrzenianie(Organizm* a, int x, int y);
	void rozmnazanie(Organizm* a, Organizm *b);
	void zabijOrganizm(Organizm* a);
	void wypiszPowiadomienia();
	void uporzadkuj();
	bool czyStoiZwierze(int X, int Y);
	void zapisz();
	static Swiat* wczytaj();//zeby nie trorzyc swiata przed wczytaniem
	~Swiat();
};