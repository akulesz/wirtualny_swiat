#include <iostream>
#include "Zwierze.h"
#include "Owca.h"
using namespace std;

Owca::Owca(int pozX, int pozY, Swiat* swiat) : Zwierze(4, 4, pozX, pozY, swiat) {

}
void Owca::rysowanie() {
	cout << 'O';
}
