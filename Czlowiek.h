#pragma once
#include "Zwierze.h"
#include <iostream>

class Czlowiek : public Zwierze {
	void akcja() override {
		char znak;
		int tmp;
		//znak = getchar();
		//cin >> znak;
		//if (znak == 65) { //gora
		//	if (pozY != 0) {
		//		tmp = pozY;
		//		pozY = pozY - 1;
		//		swiat->przesun(pozX, tmp, pozX, pozY);
		//	}	
		//}
		//else if (znak == 66) { //dol
		//	if (pozY != ? ) {
		//		tmp = pozY;
		//		pozY = pozY + 1;
		//		swiat->przesun(pozX, tmp, pozX, pozY);
		//	}
		//}
		//else if (znak == 67) { //prawo
		//	if (pozX != ?) {
		//		tmp = pozX;
		//		pozY = pozX + 1;
		//		swiat->przesun(pozX, tmp, pozX, pozY);
		//	}
		//}
		//else if (znak == 68) { //lewo
		//	if (pozX != 0 ) {
		//		tmp = pozX;
		//		pozY = pozX + 1;
		//		swiat->przesun(pozX, tmp, pozX, pozY);
		//	}
		//}
	}
};