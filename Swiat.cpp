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
#define UPARROW 24
#define DOWNARROW 25
#define RIGHTARROW 26
#define LEFTARROW 27

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
}
bool operator==(const Koordynaty& k1, const Koordynaty& k2)
{
	if (k1.x == k2.x && k1.y == k2.y) return true;
	return false;

}
wymiary Swiat::getM()
{
	return this->m;
}

Organizm* Swiat::getOrganizm(int x, int y) {
	return this->mapa[x][y];
}

int Swiat::getTura() {
	return this->tura;
}
void Swiat::setTura(int tura) {
	this->tura = tura;
}
void Swiat::wykonajTure() {
	//porzadkowanie wedlug inicjatywy
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

	if (tura > 0) {
		vector<Organizm*> tmp(organizmy);
		for (Organizm* organizm : tmp) {
			if (organizm != nullptr&&organizm->getZyje()) {
				organizm->akcja();
				organizm->setWiek(organizm->getWiek() + 1);
			}
		}
	}
	setTura(getTura() + 1);
	system("cls");
	rysujSwiat();
	return;
}

void Swiat::rysujSwiat()
{
	cout << "ABY PORUSZYC SIE UZYWAJ STRZALEK" << endl;
	cout << (char)UPARROW << " - ruch w gore" << endl;
	cout << (char)DOWNARROW << " - ruch w dol" << endl;
	cout << (char)RIGHTARROW << " - ruch w prawo " << endl;
	cout << (char)LEFTARROW << "- ruch w lewo" << endl;
	cout << "enter - wykonaj ture" << endl << endl;
	
	
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
		cout << "TURA " << getTura() << endl;
	
		//if(tura!=1) cout<wyswietlPowiadomiena
}

bool Swiat::czyPoleJestCzesiaMapy(int x, int y) {
	if (x < 0 || y < 0 || x >= m.x || y >= m.y)
		return false;
	else
		return true;
}


void Swiat::przesun(int x, int y, int newx, int newy)
{
	if (czyPustePole(newx, newy))
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
}

void Swiat::stworzNowyOrganizm(Organizm* nowy, int newx, int newy) {
	this->mapa[newx][newy] = nowy;
	this->mapa[newx][newy]->setpozX(newx);
	this->mapa[newx][newy]->setpozY(newy);
	organizmy.push_back(nowy);
}

void Swiat::rozprzestrzenianie(Organizm *a, int x, int y) {
	if (czyPustePole(x, y)) {
		stworzNowyOrganizm(a, x, y);
		powiadomienia.push_back("Organizm " + a->JakiOrganizm() + " rozprzestrzenil sie.");

	}
	else return; //pole nie jest puste wiec nic sie nie dzieje 
}

// jesli rozmnozyl to zwraca true
//bool Swiat::rozmnozJesliMoze(Organizm* rodzic1, Organizm* rodzic2, int ) {
//	if (czyPustePole(rodzic1->getpozX(), rodzic1->getpozY() + 1)) {
//		stworzNowyOrganizm(rodzic1, rodzic1->getpozX(), rodzic1->getpozY() + 1);
//		powiadomienia.push_back("Organizm " + rodzic1->JakiOrganizm() + " rozmnozyl sie.");
//	}
//}

Koordynaty Swiat::znajdzPustePoleObok(Organizm* organizm) {
	int x = organizm->getpozX();
	int y = organizm->getpozY();
	if (czyPoleJestCzesiaMapy(x, y + 1) && czyPustePole(x, y + 1)) {
		return { x, y + 1 };
	}
	if (czyPoleJestCzesiaMapy(x + 1, y)&&czyPustePole(x + 1, y)) {
		return { x + 1, y };
	}
	if (czyPoleJestCzesiaMapy(x - 1, y)&&czyPustePole(x - 1, y)) {
		return { x - 1, y };
	}
	if (czyPoleJestCzesiaMapy(x , y + 1)&&czyPustePole(x, y - 1)) {
		return { x, y - 1 };
	}
	return {-1, -1};
}


void Swiat::rozmnazanie(Organizm* rodzic1, Organizm* rodzic2) {
	/*Koordynaty r1= znajdzPustePoleObok(rodzic1);
	Koordynaty r2= znajdzPustePoleObok(rodzic2);*/
	Koordynaty pustePole = znajdzPustePoleObok(rodzic1);

	if (pustePole == Koordynaty{ -1, -1 }) {
		pustePole = znajdzPustePoleObok(rodzic2);
	}
	if (pustePole == Koordynaty{ -1, -1 }) {
		return;
	}
	stworzNowyOrganizm(rodzic1->kopiuj(), pustePole.x, pustePole.y);


	/*if(czyPustePole(rodzic1->getpozX(), rodzic1->getpozY()+1)){ 
		stworzNowyOrganizm(rodzic1, rodzic1->getpozX(), rodzic1->getpozY() + 1);
		powiadomienia.push_back("Organizm " + rodzic1->JakiOrganizm() + " rozmnozyl sie.");
	}
	else if(czyPustePole(rodzic1->getpozX(), rodzic1->getpozY() -1)){ 
		stworzNowyOrganizm(rodzic1, rodzic1->getpozX(), rodzic1->getpozY() - 1); 
		powiadomienia.push_back("Organizm " + rodzic1->JakiOrganizm() + " rozmnozyl sie.");
	}
	else if (czyPustePole(rodzic1->getpozX() + 1, rodzic1->getpozY())) { 
		stworzNowyOrganizm(rodzic1, rodzic1->getpozX() + 1, rodzic1->getpozY()); 
		powiadomienia.push_back("Organizm " + rodzic1->JakiOrganizm() + " rozmnozyl sie.");
	}
	else if (czyPustePole(rodzic1->getpozX() - 1, rodzic1->getpozY())) {
		stworzNowyOrganizm(rodzic1, rodzic1->getpozX() - 1, rodzic1->getpozY()); 
		powiadomienia.push_back("Organizm " + rodzic2->JakiOrganizm() + " rozmnozyl sie.");
	}
	else if (czyPustePole(rodzic2->getpozX(), rodzic2->getpozY() + 1)) { 
		stworzNowyOrganizm(rodzic2, rodzic2->getpozX(), rodzic2->getpozY() + 1);
		powiadomienia.push_back("Organizm " + rodzic1->JakiOrganizm() + " rozmnozyl sie.");
	}
	else if (czyPustePole(rodzic2->getpozX(), rodzic2->getpozY() - 1)) { 
		stworzNowyOrganizm(rodzic2, rodzic2->getpozX(), rodzic2->getpozY() - 1); 
		powiadomienia.push_back("Organizm " + rodzic2->JakiOrganizm() + " rozmnozyl sie.");
	}
	else if (czyPustePole(rodzic2->getpozX() + 1, rodzic2->getpozY())) { 
		stworzNowyOrganizm(rodzic2, rodzic2->getpozX() + 1, rodzic2->getpozY()); 
		powiadomienia.push_back("Organizm " + rodzic2->JakiOrganizm() + " rozmnozyl sie.");
	}
	else if (czyPustePole(rodzic2->getpozX() - 1, rodzic2->getpozY())) { 
		stworzNowyOrganizm(rodzic2, rodzic2->getpozX() - 1, rodzic2->getpozY()); 
		powiadomienia.push_back("Organizm " + rodzic2->JakiOrganizm() + " rozmnozyl sie.");
	}
	*/
}

void Swiat::zabijOrganizm(Organizm* a) {

	this->mapa[a->getpozX()][a->getpozY()] = empty;
	
	for(int i=0; i<organizmy.size(); i++){
		if (a == organizmy[i]) {
			powiadomienia.push_back("Organizm " + a->JakiOrganizm() + " umiera.");
			a->setZyje(false);
			organizmy.erase(organizmy.begin() + i);

		}
	}
}

bool Swiat::czyPustePole(int x, int y) {
	if ( this->mapa[x][y] == empty ) return true;
	else return false;
}

Swiat::~Swiat()
{
	for (int i = 0; i < m.x; i++)
	{
		delete[] this->mapa[i];
	}
	delete[] mapa;
}
