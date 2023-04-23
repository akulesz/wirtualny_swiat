#include <iostream>
#include "Roslina.h"
using namespace std;
Roslina::Roslina(int sila, int inicjatywa, int pozX, int pozY, Swiat* swiat, char symbol, int wiek) : Organizm(sila, inicjatywa, pozX, pozY, swiat, symbol, wiek) {};
void Roslina::akcja() { //stworzenie nowej rosliny na polu obok rosliny

	bool ruchMozliwy = false; //pole na ktore chce ruszyc sie lis nie wykracza poza mape
	do { 
		Random r(1, 4);
		int tmp;
		switch (r.GetRandomNumber()) {
		case 1: //gora
			if (pozY != 0) {  
				ruchMozliwy = true; 
				swiat->rozprzestrzenianie(swiat->getOrganizm(pozX, pozY), pozX, pozY - 1);//chce stworzyc nowy organizm //musze sprawdzic czy to pole jest puste   
					//musze dodac go do wektora 
			}
			break;
		case 2: //dol
			if (pozY != swiat->getM().y-1) { 
				ruchMozliwy = true; 
				swiat->rozprzestrzenianie(swiat->getOrganizm(pozX, pozY), pozX, pozY + 1);
			}
			break;
		case 3: //prawo
			if (pozY != swiat->getM().x-1) {
				ruchMozliwy = true;
				swiat->rozprzestrzenianie(swiat->getOrganizm(pozX, pozY), pozX+1, pozY);
				
			}
			break;
		case 4: //lewo
			if (pozY != 0) {
				ruchMozliwy = true;
				swiat->rozprzestrzenianie(swiat->getOrganizm(pozX, pozY), pozX-1, pozY);
			}
			break;
		}

	} while (ruchMozliwy != true);

	return;
};
void Roslina::kolizja(Organizm *a) {};


