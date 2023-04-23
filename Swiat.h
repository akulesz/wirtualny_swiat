#pragma once
#include <iostream>
#include <vector>
#include "wymiary.h"
// #include "Organizm.h"
// #include "Owca.h"
#define empty nullptr
using namespace std;
class Organizm;

class Swiat {
private:
	wymiary m;
	Organizm*** mapa; // mapa[m.x][m.y]
	vector<Organizm*> organizmy;

public:
	Swiat(wymiary m);

	wymiary getM();

	void wykonajTure();

	void rysujSwiat();
	bool czyPoleJestCzesiaMapy(int x, int y);
	void przesun(int x, int y, int newx, int newy);
	void rozprzestrzenianie(Organizm* nowy, int newx, int newy);
	Organizm* getOrganizm(int x, int y);


	~Swiat();
};