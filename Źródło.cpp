#include <iostream>
#include "Swiat.h"
#include "Random.h"
using namespace std;

int main() {
    std::srand(std::time(nullptr)); // seed the random number generator with the current time

	Swiat aga({ 10,20 });
	aga.rysujSwiat();

	for (int i = 0; i < 5; i++) {
		cout << endl;
		aga.wykonajTure();
	}
	
	/*Random numer({ 1,4 });
	for (int i = 0; i < 20; i++) {
		cout << numer.GetRandomNumber();
	}*/
	return 0;
}