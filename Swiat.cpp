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
	this->mapa = new Organizm **[m.x];
	for (int i = 0; i < m.x; i++)
	{
		this->mapa[i] = new Organizm *[m.y];
	}

	for (int i = 0; i < m.x; i++)
	{
		for (int j = 0; j < m.y; j++)
		{
			this->mapa[i][j] = empty;
		}
	}


	Czlowiek* test = new Czlowiek(0, 0, this, 0);
	this->mapa[0][0] = test;
	//test->akcja();
	//return;
	
};

wymiary Swiat::getM()
{
	return this->m;
}

void Swiat::wykonajTure(){
	
	return;
};

void Swiat::rysujSwiat()
{
	for (int i = 0; i < m.x; i++)
	{
		for (int j = 0; j < m.y; j++)
		{
			if (mapa[i][j] == empty)
			{
				cout << '.';
			}
			else
			{
				mapa[i][j]->rysowanie();
			}
			// cout << mapa[i][j];
		}
		cout << endl;
	}
};

void Swiat::przesun(int x, int y, int newx, int newy)
{
	if (this->mapa[newx][newy] == empty)
	{
		this->mapa[newx][newy] = mapa[x][y]; 
		this->mapa[x][y] = empty;
	}
	else
	{
		this->mapa[x][y]->kolizja(mapa[newx][newy]);
	}
};
//
//void Swiat::rozprzestrzenianie(Organizm *nowy, int newx, int newy) {
//	this->mapa[newx][newy] = nowy;
//};

Swiat::~Swiat()
{
	for (int i = 0; i < m.x; i++)
	{
		delete[] this->mapa[i];
	}
	delete[] mapa;
}
