#include <iostream>
#include "Roslina.h"
using namespace std;
Roslina::Roslina(int sila, int inicjatywa, int pozX, int pozY, Swiat* swiat, char symbol, int wiek) : Organizm(sila, inicjatywa, pozX, pozY, swiat, symbol, wiek) {};
void Roslina::akcja() { //stworzenie nowej rosliny na polu obok rosliny
	//Random r(1, 4);
	//int tmp;
	//switch (r.GetRandomNumber()) {
	//case 1: //w gore
	//	if (pozY != 0) {
	//			
	//		// mapa w y-1 = symbol
	//	}
	//	else
	//		tmp = pozY;	
	//	break;
	//}

};
void Roslina::kolizja(Organizm *a) {};


