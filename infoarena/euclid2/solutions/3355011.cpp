// https://infoarena.ro/problema/euclid2

// 100 puncte

#include<fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

// Algoritmul lui Euclid pentru determinarea CMMDC a doua numere, prin impartiri:
// Se impart cele doua numere in mod repetat, pana cand restul impartirii devine 0.
// La fiecare pas, restul devine impartitor, iar impartitorul devine deimpartit.
// Valoarea obtinuta prin impartire, atunci cand numerele se impart exact, reprezinta CMMDC-ul celor doua numere.

// Algoritmul functioneaza datorita unei teoreme din matematica, care ne spune ca, 
// daca doua numere sunt divizibile la acelasi numar, d, atunci si restul impartirii numerelor este divizibil la acelasi numar, d.

// Varianta prin scaderi nu este optima.
// Un algoritm mai eficient este algoritmul lui Euclid prin impartiri repetate. 

// Complexitatea depinde de numarul de impartiri efectuate si este logaritmica: O(log min(a, b))

int main() {
	int T, a, b, rest;

	fin >> T;

	for(int i = 0; i < T; i++) {
		fin >> a >> b;

		while(b != 0) {
			rest = a % b;

			a = b;
			b = rest;
		}

		fout << a << "\n";
	}

	return 0;
}
