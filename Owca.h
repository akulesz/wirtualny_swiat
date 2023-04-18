#pragma once
#include "Zwierze.h"
#include "Swiat.h"
class Owca : public Zwierze {
public:
	Owca(int pozX, int pozY, Swiat* swiat);
	void rysowanie() override;
	/*void akcja() override {
	}*/
};