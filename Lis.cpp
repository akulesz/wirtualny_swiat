#include <iostream>
#include "Lis.h"
using namespace std;

Lis::Lis(int pozX, int pozY, Swiat* swiat, int wiek) : Zwierze(3, 7, pozX, pozY, swiat, 'L', wiek) {};
void Lis::akcja() {
	
	//bool ruchMozliwy = false; //pole na ktore chce ruszyc sie lis nie wykracza poza mape
	//bool silny = false; //pole na ktore chce ruszyc sie lis nie zajmuje organizm o wiekszej sile 
	//do {
	// ruchMozliwy=false;
	//	Random r(1, 4);
	//	int tmp;
	//	switch (r.GetRandomNumber()) {
	//	case 1: //gora
	//		if (pozY != 0) { 
	//			ruchMozliwy = true; 
	//			czySilny(pozX, pozY, pozX, pozY - 1);
	//		}
	//		break;
	//	case 2: //dol
	//		if (pozY != swiat->getM().y-1) { 
	//			ruchMozliwy = true; 
	//			czySilny(pozX, pozY, pozX, pozY + 1);
	//		}
	//		break;
	//	case 3: //prawo
	//		if (pozY != swiat->getM().x-1) {
	//			ruchMozliwy = true;
	//			czySilny(pozX, pozY, pozX+1, pozY );
	//		}
	//		break;
	//	case 4: //lewo
	//		if (pozY != 0) {
	//			ruchMozliwy = true;
	//			czySilny(pozX, pozY, pozX - 1, pozY);
	//		}
	//		break;
	//	}

	//} while (ruchMozliwy != true && silny != true);
	
	return;
};

//bool Lis::czySilny(int x, int y, int a, int b) {
//	if (1) {
//		//czy sila lisa jest wieksza od sily organizmu na polu na ktory lis chce sie ruszyc 
//		//chce wejsc w swiat znalezc organizm z [x][y] i wyjac sile
//		swiat->przesun(x, y, a, b);
//		return true;
//	}
//	else return false;
//};

void Lis::kolizja(Organizm* a) {
	return;
};
void Lis::rysowanie() {
	cout << 'L';
};
