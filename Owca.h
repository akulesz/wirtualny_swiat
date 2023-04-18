#pragma once
#include <iostream>
#include "Zwierze.h"
using namespace std;
class Owca : public Zwierze {
public:
	Owca(int pozX, int pozY, Swiat* swiat) : Zwierze(4, 4, pozX, pozY, swiat) {

	}
	void rysowanie() override {
		cout << 'O';
	}
	/*void akcja() override {
	}*/
};