#pragma once
#include <iostream>
#include <vector>
#include "wymiary.h"

// #include "Organizm.h"
// #include "Owca.h"
#define empty nullptr

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
	void przesun(int x, int y, int newx, int newy);
	//void rozprzestrzenianie(Organizm* nowy, int newx, int newy);

	~Swiat();
};