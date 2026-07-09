#include <iostream>

using namespace std;

int main(){
	// vom utiliza metoda impartirii
	// declaram variabilele
	int p, a, b, r;
	
	fropen("euclid2.in", "r", stdin);
	fropen("euclid2.out", "w", stdout);
	// citim nr de perechi
	cin >> p;

	for(int i = 1; i <= p; i++){

	// citim de la tastatura cele 2 numere
	cin >> a >> b;
	while(a != 0){
		r = b % a;
		b = a;
		a = r;
	}
	
	cout << b << '\n';
	}
	
	return 0;
}
