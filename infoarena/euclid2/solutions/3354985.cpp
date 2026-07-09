// https://infoarena.ro/problema/euclid2

// 60 puncte

#include<fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

// Algoritmul lui Euclid pentru determinarea CMMDC a doua numere, prin scaderi:
// Se scade, repetat, numarul mai mic din numarul mai mare, pana cand cele devin egale.
// Valoarea comuna este CMMDC-ul celor doua numere.
// Algoritmul functioneaza datorita unei teoreme din matematica, care ne spune ca, 
// daca doua numere sunt divizibile cu acelasi numar, d, atunci si diferenta lor este divizibila cu d.

// Varianta prin scaderi nu este optima.
// Un algoritm mai eficient este algoritmul lui Euclid prin impartiri repetate. 

// Complexitatea depinde de numarul de scaderi efectuate.
// Poate fi O(max(a, b)) in cel mai rau caz (ex.: cazul in care unul din numere este 1).

int main() {
	int T, a, b;

	fin >> T;

	for(int i = 0; i < T; i++) {
		fin >> a >> b;

		while(a != b) {
			if(a >= b) {
				a = a - b;
			} else {
				b = b - a;
			}
		}

		fout << a << "\n";
	}

	return 0;
}
