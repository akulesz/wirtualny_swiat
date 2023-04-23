#include "Swiat.h"
#include "Organizm.h"
#include "Czlowiek.h"
#include "Owca.h"
#include "Wilk.h"
#include "Lis.h"
#include "Antylopa.h"
#include "Zolw.h"
#include "Mlecz.h"
#include "Trawa.h"
#include "BarszczSosnowskiego.h"
#include "WilczeJagody.h"
#include "Guarana.h"
#include "Random.h"
using namespace std;

Swiat::Swiat(wymiary m)
{
	this->m = m;
	this->mapa = new Organizm * *[m.x];
	for (int i = 0; i < m.x; i++)
	{
		this->mapa[i] = new Organizm * [m.y];
	}

	for (int i = 0; i < m.x; i++)
	{
		for (int j = 0; j < m.y; j++)
		{
			this->mapa[i][j] = empty;
		}
	}


	organizmy.push_back(new Owca(0, 0, this, 0));
	organizmy.push_back(new Owca(0, 0, this, 0));
	organizmy.push_back(new Owca(0, 0, this, 0));
	organizmy.push_back(new Wilk(0, 0, this, 0));
	organizmy.push_back(new Wilk(0, 0, this, 0));
	organizmy.push_back(new Wilk(0, 0, this, 0));
	organizmy.push_back(new Lis(0, 0, this, 0));
	organizmy.push_back(new Lis(0, 0, this, 0));
	organizmy.push_back(new Lis(0, 0, this, 0));
	organizmy.push_back(new Zolw(0, 0, this, 0));
	organizmy.push_back(new Zolw(0, 0, this, 0));
	organizmy.push_back(new Zolw(0, 0, this, 0));
	organizmy.push_back(new Antylopa(0, 0, this, 0));
	organizmy.push_back(new Antylopa(0, 0, this, 0));
	organizmy.push_back(new Antylopa(0, 0, this, 0));
	organizmy.push_back(new Czlowiek(0, 0, this, 0));
	organizmy.push_back(new Trawa(0, 0, this, 0));
	organizmy.push_back(new Trawa(0, 0, this, 0));
	organizmy.push_back(new Trawa(0, 0, this, 0));
	organizmy.push_back(new Mlecz(0, 0, this, 0));
	organizmy.push_back(new Mlecz(0, 0, this, 0));
	organizmy.push_back(new Mlecz(0, 0, this, 0));
	organizmy.push_back(new WilczeJagody(0, 0, this, 0));
	organizmy.push_back(new WilczeJagody(0, 0, this, 0));
	organizmy.push_back(new WilczeJagody(0, 0, this, 0));
	organizmy.push_back(new Guarana(0, 0, this, 0));
	organizmy.push_back(new Guarana(0, 0, this, 0));
	organizmy.push_back(new Guarana(0, 0, this, 0));
	organizmy.push_back(new BarszczSosnowskiego(0, 0, this, 0));
	organizmy.push_back(new BarszczSosnowskiego(0, 0, this, 0));
	organizmy.push_back(new BarszczSosnowskiego(0, 0, this, 0));

	Random x(0, m.x - 1);
	Random y(0, m.y - 1);
	for (Organizm* organizm : organizmy) { //przechdzimy po kazdym organizmie w wektorze
		int X;
		int Y;
		do {
			X = x.GetRandomNumber();
			Y = y.GetRandomNumber();
		} while (this->mapa[X][Y] != empty);
		this->mapa[X][Y] = organizm;
		organizm->setpozX(X);
		organizm->setpozY(Y);
	}

	/*int licznik = 0;
	while (licznik != 3) {
		int X = x.GetRandomNumber();
		int Y = y.GetRandomNumber();
		if (this->mapa[X][Y] == empty) {
			Owca* nowyOrganizm = new Owca(X, Y, this, 0);
			this->mapa[X][Y] = nowyOrganizm;
			licznik++;
		}
		else continue;
	}*/

	//licznik = 0;
	//while (licznik != 3) {
	//	int X = x.GetRandomNumber();
	//	int Y = y.GetRandomNumber();
	//	if (this->mapa[X][Y] == empty) {
	//		Wilk* nowyOrganizm = new Wilk(X, Y, this, 0);
	//		this->mapa[X][Y] = nowyOrganizm;
	//		licznik++;
	//	}
	//	else continue;
	//}

};

wymiary Swiat::getM()
{
	return this->m;
}
Organizm* Swiat::getOrganizm(int x, int y) {
	return this->mapa[x][y];
}

void Swiat::wykonajTure() {
	for (int i = 0; i < organizmy.size(); i++) {
		for (int j = 0; j < organizmy.size() - 1; j++) {
			if (organizmy[i]->getInicjatywa() > organizmy[j]->getInicjatywa()) {
				swap(organizmy[i], organizmy[j]);
			}
			else if (organizmy[i]->getInicjatywa() == organizmy[j]->getInicjatywa()) {
				if (organizmy[i]->getWiek() > organizmy[j]->getWiek() || organizmy[i]->getWiek() == organizmy[j]->getWiek()) {
					swap(organizmy[i], organizmy[j]);
				}
			}
		}
		
	}

	/*for (int i = 0; i < organizmy.size(); i++) {
		organizmy[i]->akcja();
	}*/

	vector<Organizm*> tmp(organizmy);

	for (Organizm* organizm : tmp) {
		if(organizm != nullptr)
			organizm->akcja();
	}
	// po posortowaniu u¿yæ foreach i wykonaæ akcje

	rysujSwiat();
	return;
};

void Swiat::rysujSwiat()
{
	for (int i = 0; i < m.y; i++)
	{
		for (int j = 0; j < m.x; j++)
		{
			if (mapa[j][i] == empty)
			{
				cout << '.';
			}
			else
			{
				mapa[j][i]->rysowanie();
			}
			// cout << mapa[i][j];
		}
		cout << endl;
	}
};

bool Swiat::czyPoleJestCzesiaMapy(int x, int y) {
	if (x < 0 || y < 0 || x >= m.x || y >= m.y)
		return false;
	else
		return true;
}


void Swiat::przesun(int x, int y, int newx, int newy)
{
	if (this->mapa[newx][newy] == empty)
	{
		this->mapa[newx][newy] = mapa[x][y];
		this->mapa[x][y] = empty;
		this->mapa[newx][newy]->setpozX(newx);
		this->mapa[newx][newy]->setpozY(newy);
	}
	else
	{
		this->mapa[x][y]->kolizja(mapa[newx][newy]);
	}
};

void Swiat::rozprzestrzenianie(Organizm *nowy, int newx, int newy) {
	if (this->mapa[newx][newy] == empty) {
		this->mapa[newx][newy] = nowy;
		this->mapa[newx][newy]->setpozX(newx);
		this->mapa[newx][newy]->setpozY(newy);
		organizmy.push_back(nowy);
	}
	else return; //pole nie jest puste wiec nic sie nie dzieje 
};

Swiat::~Swiat()
{
	for (int i = 0; i < m.x; i++)
	{
		delete[] this->mapa[i];
	}
	delete[] mapa;
}
