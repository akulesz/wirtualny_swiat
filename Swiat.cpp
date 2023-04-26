#include <fstream>
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
#define UPARROW 30
#define DOWNARROW 31
#define RIGHTARROW 16
#define LEFTARROW 17
static const string SCIEZKA = "zapis.txt";

using namespace std;
Swiat::Swiat(wymiary m, vector<Organizm*>& organizmy, int tura) {
	this->m = m;
	this->organizmy = organizmy;
	this->tura = tura;
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

	for (Organizm* organizm : organizmy) { //przechodzimy po kazdym organizmie w wektorze
				this->mapa[organizm->getpozX()][organizm->getpozY()] = organizm;
				organizm->setSwiat(this);
				
	}

	

}
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

	if (m.x * m.y > 500) { //dla bardzo duzej mapy tworze wiecej organizmow
		for (int i = 0; i < 5; i++) {
			organizmy.push_back(new Owca(0, 0, this, 0));
			organizmy.push_back(new Wilk(0, 0, this, 0));
			organizmy.push_back(new Lis(0, 0, this, 0));
			organizmy.push_back(new Zolw(0, 0, this, 0));
			organizmy.push_back(new Antylopa(0, 0, this, 0));
			organizmy.push_back(new Trawa(0, 0, this, 0));
			organizmy.push_back(new Mlecz(0, 0, this, 0));
			organizmy.push_back(new WilczeJagody(0, 0, this, 0));
			organizmy.push_back(new Guarana(0, 0, this, 0));
			organizmy.push_back(new BarszczSosnowskiego(0, 0, this, 0));
		}
	}

	for (int i = 0; i < 3; i++) {
		organizmy.push_back(new Owca(0, 0, this, 0));
		organizmy.push_back(new Wilk(0, 0, this, 0));
		organizmy.push_back(new Lis(0, 0, this, 0));
		organizmy.push_back(new Zolw(0, 0, this, 0));
		organizmy.push_back(new Antylopa(0, 0, this, 0));
		organizmy.push_back(new Trawa(0, 0, this, 0));
		organizmy.push_back(new Mlecz(0, 0, this, 0));
		organizmy.push_back(new WilczeJagody(0, 0, this, 0));
		organizmy.push_back(new Guarana(0, 0, this, 0));
		organizmy.push_back(new BarszczSosnowskiego(0, 0, this, 0));
	}
	

	organizmy.push_back(new Czlowiek(0, 0, this, 0));

	Random x(0, m.x - 1);
	Random y(0, m.y - 1);
	for (Organizm* organizm : organizmy) { //przechodzimy po kazdym organizmie w wektorze
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
void Swiat::dodajPowiadomienie(string powiadomienie) {
	powiadomienia.push_back(powiadomienie);
}
wymiary Swiat::getM()
{
	return this->m;
}
void Swiat::wypiszPowiadomienia() {
	if (powiadomienia.size() < 6) {
		for (int i = 0; i < powiadomienia.size(); i++) {
			cout << powiadomienia[i]<<endl;
		}
	}
	else
	for (int i = 0; i < 6; i++) {
		cout << powiadomienia[i]<<endl;
}
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

	
		vector<Organizm*> tmp(organizmy);
		for (Organizm* organizm : tmp) {
			if (organizm != nullptr&&organizm->getZyje()) {
				organizm->akcja();
				organizm->setWiek(organizm->getWiek() + 1);
			}
		}
	
	setTura(getTura() + 1);
	system("cls");
	rysujSwiat();
	powiadomienia.clear();
	//zapisz();
	return;
}

void Swiat::rysujSwiat()
{
	cout << "ABY PORUSZYC SIE UZYWAJ STRZALEK" << endl;
	cout << (char)UPARROW << " ruch w gore, " ;
	cout << (char)DOWNARROW << " ruch w dol, " ;
	cout << (char)RIGHTARROW << " ruch w prawo, ";
	cout << (char)LEFTARROW << " ruch w lewo" << endl;
	cout << "* - Superumiejetnosc - MAGICZNY ELIKSIR - zwieksza sile czlowieka do 10" << endl;
	cout << "t - wykonaj ture" << endl;
	cout << "z - zapisz swiat" << endl << endl;
	
	
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
				
			}
			cout << endl;
		}
		cout << "TURA " << getTura() << endl;
		wypiszPowiadomienia();
	
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
	Koordynaty pustePole = znajdzPustePoleObok(rodzic1);

	if (pustePole == Koordynaty{ -1, -1 }) {
		pustePole = znajdzPustePoleObok(rodzic2);
	}
	if (pustePole == Koordynaty{ -1, -1 }) {
		return;
	}

	stworzNowyOrganizm(rodzic1->kopiuj(), pustePole.x, pustePole.y);
	powiadomienia.push_back("Organizm " + rodzic1->JakiOrganizm() + " rozmnozyl sie.");
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

bool Swiat::czyStoiZwierze(int x, int y) {
	
	if (czyPoleJestCzesiaMapy(x, y) && getOrganizm(x, y) != empty) {
		Zwierze* z = dynamic_cast<Zwierze*>(getOrganizm(x, y));
		if (z == nullptr) return false;
		else return true;
	}
	else return false;
}

bool Swiat::czyPustePole(int x, int y) {
	if ( this->mapa[x][y] == empty ) return true;
	else return false;
}

void Swiat::zapisz() {
	ofstream plik(SCIEZKA);
	plik << tura << endl;
	plik << m.x << endl;
	plik << m.y << endl;
	plik << organizmy.size() << endl;
	for (auto o : organizmy) {
		plik << o->serializuj() << endl;
	}
}

Organizm* wczytajOrganizm(ifstream& plik) {
	int sila;
	int inicjatywa;
	int pozX;
	int pozY;
	char symbol;
	int wiek;
	bool zyje;
	plik >> sila;
	plik >> inicjatywa;
	plik >> pozX;
	plik >> pozY;
	plik >> symbol;
	plik >> wiek;
	plik >> zyje;
	switch (symbol) {
	case 'O':
		return new Owca(sila,inicjatywa,pozX, pozY, nullptr, wiek,zyje);
		break;
	case 'C':
		int odliczanieDoUmiejetnosci;
		int stanPoczatkowy;
		bool czyUmiejetnoscAktywna;
		plik >> odliczanieDoUmiejetnosci;
		plik >> stanPoczatkowy;
		plik >> czyUmiejetnoscAktywna;
		return new Czlowiek(sila, inicjatywa, pozX, pozY, nullptr, wiek, zyje, odliczanieDoUmiejetnosci, stanPoczatkowy, czyUmiejetnoscAktywna);
		break;
	case 'W':
		return new Wilk(sila, inicjatywa, pozX, pozY, nullptr, wiek, zyje);
		break;
	case 'L':
		return new Lis(sila, inicjatywa, pozX, pozY, nullptr, wiek, zyje);
		break;
	case 'A':
		return new Antylopa(sila, inicjatywa, pozX, pozY, nullptr, wiek, zyje);
		break;
	case 'Z':
		int licznik;
		plik >> licznik;
		return new Zolw(sila, inicjatywa, pozX, pozY, nullptr, wiek, zyje, licznik);
		break;
	case 'T':
		return new Trawa(sila, inicjatywa, pozX, pozY, nullptr, wiek, zyje);
		break;
	case 'M':
		return new Mlecz(sila, inicjatywa, pozX, pozY, nullptr, wiek, zyje);
		break;
	case 'B':
		return new BarszczSosnowskiego(sila, inicjatywa, pozX, pozY, nullptr, wiek, zyje);
		break;
	case 'J':
		return new WilczeJagody(sila, inicjatywa, pozX, pozY, nullptr, wiek, zyje);
		break;
	case 'G':
		return new Guarana(sila, inicjatywa, pozX, pozY, nullptr, wiek, zyje);
		break;
	}
}

vector<Organizm*>& wczytajOrganizmy(ifstream& plik) {
	vector<Organizm*> org;
	int ileWczytac;
	plik >> ileWczytac;
	for (int i = 0; i < ileWczytac; i++) {
		Organizm* o = wczytajOrganizm(plik);
		org.push_back(o);
	}
	return org;

}


Swiat* Swiat::wczytaj() {
	ifstream plik(SCIEZKA);
	string f;
	wymiary m;
	int tura;
	plik >> tura;
	plik >> m.x;
	plik >> m.y;

	auto organizmy= wczytajOrganizmy(plik);

	for (auto organizm : organizmy) {
		cout << organizm->JakiOrganizm() << endl;
	}
	//auto o = wczytajOrganizm(plik);
	//petla wczytujaca organizmy
	Swiat* s = new Swiat(m, organizmy, tura);

	return s;
}

Swiat::~Swiat()
{
	for (int i = 0; i < m.x; i++)
	{
		delete[] this->mapa[i];
	}
	delete[] mapa;
}
