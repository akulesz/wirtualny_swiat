#include <iostream>
#include "Organizm.h"
#include "Owca.h"
#include "Swiat.h"
#define empty nullptr
using namespace std;


Swiat::Swiat(wymiary m) {
	this->m = m;
	this->mapa = new Organizm **[m.x];
	for (int i = 0; i < m.x; i++) {
		this->mapa[i] = new Organizm *[m.y];
	}

	for (int i = 0; i < m.x; i++) {
		for (int j = 0; j < m.y; j++) {
			this->mapa[i][j] = empty;
		}
	}

	Owca* test = new Owca(0, 1, this);
	this->mapa[0][1] = test;
	//owoca - 3


};

wymiary Swiat::getM() {
		return this->m;
	}

void Swiat::wykonajTure() {};

void Swiat::rysujSwiat() {
		for (int i = 0; i < m.x; i++) {
			for (int j = 0; j < m.y; j++) {
				if (mapa[i][j] == empty) {
					cout << '.';
				}
				else {
					mapa[i][j]->rysowanie();
				}
				//cout << mapa[i][j];
			}
			cout << endl;
		}
	};

	void Swiat::przesun(int x, int y, int newx, int newy) {
		if (this->mapa[newx][newy] == empty) {
			this->mapa[newx][newy] = mapa[x][y]; ///czy to jest dobrze???
			this->mapa[x][y] = empty;
		}
		else {
			mapa[x][y]->kolizja(mapa[newx][newy]);
		}

	};

	Swiat::~Swiat() {
		for (int i = 0; i < m.x; i++) {
			delete[] this->mapa[i];
		}
		delete[] mapa;
	}
