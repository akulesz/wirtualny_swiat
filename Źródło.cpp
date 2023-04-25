#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "Swiat.h"
#include "Random.h"
using namespace std;

int main() {
    std::srand(std::time(nullptr)); // seed the random number generator with the current time
	int x, y;
	cout << "WITAJ W MOIM SWIECIE!" << endl;
	cout << "ABY STWORZYC SWIAT PODAJ WYMIARY SWIATA: ";
	cin >> x >> y;
	cout << endl;
	while (x * y < 40) {
		cout << " UPS! SWIAT JEST ZBYT MALY. PODAJ INNE WYMIARY SWIATA: ";
		cin >> x >> y;
		cout << endl;
	}
	//wyszyscic ekran
	system("cls");
	Swiat mojSwiat({ x,y });
	

	while (getchar() == '\n') {
		//for (int i = 0; i < 100; i++) {
			//cout << endl;
			mojSwiat.wykonajTure();
			
		}
		//}
	
	
	
	return 0;
}