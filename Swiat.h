#pragma once
#include <iostream>
#include "Organizm.h"
#include "Owca.h"
#define empty nullptr

struct wymiary {
	int x;
	int y;
};

class Swiat {
private:
	wymiary m;// = { 20,20 };
	Organizm*** mapa; // mapa[m.x][m.y]
public:
	Swiat(wymiary m);
	
	wymiary getM();

	void wykonajTure();

	void rysujSwiat();
	void przesun(int x, int y, int newx, int newy);

	~Swiat();
};