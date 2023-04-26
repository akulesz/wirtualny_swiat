#include <iostream>
#include <cstdlib>
#include <ctime>
#include<conio.h>
#include <string>
#include "Swiat.h"
#include "Random.h"
using namespace std;

int main() {
    srand(time(nullptr)); 
	int x, y;

	cout << "WITAJ W MOIM SWIECIE!" << endl;
	cout << "ZACZNIJ GRE!!!" << endl;
	cout << "n - nowy swiat" << endl;
	cout << "w- wczytaj zapisany swiat" << endl;
	char gra;
	cin >> gra;

	if (gra == 'w') {
		Swiat* wczytanySwiat = Swiat::wczytaj();
		while (true) {
			char wykonaj;
			system("cls");
			wczytanySwiat->rysujSwiat();

			while (true) {
				wykonaj = _getch();
				if (wykonaj == 't') {
					wczytanySwiat->wykonajTure();
					continue;
				}
				if (wykonaj == 'z') {
					wczytanySwiat->zapisz();
					cout << "Zapisano swiat!" << endl;
				}
				return 0;
			}
		}
	}

	else if(gra=='n') {
		cout << "ABY STWORZYC SWIAT PODAJ WYMIARY SWIATA: ";
		cin >> x >> y;
		cout << endl;
		char wykonaj;
		
		while (x * y < 40) {
			cout << " UPS! SWIAT JEST ZBYT MALY. PODAJ INNE WYMIARY SWIATA: ";
			cin >> x >> y;
			cout << endl;
		}
		system("cls");
		Swiat mojSwiat({ x,y });
		mojSwiat.rysujSwiat();

		while(true){
			wykonaj = _getch();
			if(wykonaj=='t'){
				mojSwiat.wykonajTure();
				continue;
			}
			if (wykonaj == 'z') {
				mojSwiat.zapisz();
				cout << "Zapisano swiat!" << endl;
			}
		}
		while (getchar() == '\n') {
			mojSwiat.wykonajTure();
		}
	}

	return 0;
}