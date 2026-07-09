//Fie v un vector cu N elemente.Se numeste subsir de lungime K al vectorului v un nou vector v' = (vi1, vi2, ... viK), cu i1 < i2 < ... < iK. De exemplu, vectorul v = (5 7 8 9 1 6) contine ca subsir sirurile (5 8 6) sau (7 8 1), dar nu contine subsirul (1 5). Se dau doi vectori A si B cu elemente numere naturale nenule.
//
//	Cerinta
//	Sa se determine subsirul de lungime maxima care apare atat in A cat si in B.
//
//	Date de intrare
//	Fisierul de intrare cmlsc.in contine pe prima linie M si N, numarul de elemente pentru vectorul A, respectiv pentru B.A doua linie contine M numere naturale, elementele vectorului A.A treia linie contine descrierea vectorului B sub acelasi format.
//
//	Date de iesire
//	Fisierul de iesire cmlsc.out va contine pe prima linie MAX, lungimea maxima a unui subsir comun.A doua linie va contine MAX numere ce reprezinta un subsir comun pentru A si B.Daca exista mai multe solutii se poate afisa oricare.
//
//	Restrictii
//	1 ≤ M, N ≤ 1024
//	Numerele din cei doi vectori nu depasesc 256
//	Exemplu
//	cmlsc.in	cmlsc.out
//	5 3            2
//	1 7 3 9 8     7 8
//	7 5 8

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

fstream in("cmlsc.in", ios::in);             // fisierul din care voi extrage datele
fstream out("cmlsc.out", ios::out);          // fisierul in care voi insera datele

bool gaseste(vector<int> aux, int val)
{
	int nr = 0;                              // variabila cu care voi numara solutiile gasite
	vector<int>::iterator it;                // iteratorul de parcurgere al tabloului primit ca parametru
	for (it = aux.begin(); it != aux.end(); it++)
	{	
		if (*it == val)
			nr++;
	}

	// conditia de returnare
	if (nr != 0)
		return true;
	else
		return false;
}

int main()
{
	vector<int> A, B, Sol;					// Tablourile pe care urmeaza sa le folosesc
	A.reserve(1024);                        // Rezerv memorie
	B.reserve(1024);                        // Rezerv memorie
	Sol.reserve(1024);                      // Rezerv memorie
	vector<int>::iterator itA, itB, itS;    // Iteratorii de parcurgere a tablourilor
	vector<int>::reverse_iterator its;      // Iteratorul de parcurgere inversa pentru optinerea maximului
	int nrA = 0, nrB = 0, nrS = 0,          // Variabilele in care voi retine numarul elementelor din tablouri
		aux = 0, aux2 = 0;					// Variabila auxiliara
	// Citirea limitelor pentru tablouri
	in >> nrA >> nrB;

	// Citirea datelor pentru tablouri
	aux2 = nrA;
	while (aux2)
	{
		in >> aux;
		A.push_back(aux);
		aux2--;
	}
	aux2 = nrB;
	while (aux2)
	{
		in >> aux;
		B.push_back(aux);
		aux2--;
	}
	
	// Rezolvare
	Sol.push_back(-2500);                   // Adaug un minim in vector pe care urmeaza sa-l sterg la sfarsit
	itS = Sol.begin();                      // Initializez iteratorul pentru tabloul cu solutii ( stanga-dreapta )
	its = Sol.rbegin();
	if (nrA > nrB)
	{
		for (itA = A.begin(); itA != A.end(); itA++)
			for (itB = B.begin(); itB != B.end(); itB++)
			{
				if (gaseste(Sol, *itB) != true)
					if (*itA == *itB)
					{
						Sol.push_back(max(*itB, *its));
						its = Sol.rbegin();
						nrS++;
					}
			}
	}
	else
		for (itB = B.begin(); itB != B.end(); itB++)
			for (itA = A.begin(); itA != A.end(); itA++)
			{
				if (gaseste(Sol, *itA) != true)
					if (*itA == *itB)
					{
						Sol.push_back(max(*itB, *its));
						its = Sol.rbegin();
						nrS++;
					}
			}

	// Tiparirea rezultatului
	out << nrS << '\n';
	for (itS = Sol.begin(); itS != Sol.end(); itS++)
	{
		if (*itS >= 0 )
		out << *itS << ' ';
	}

	// Inchiderea fiserelor
	in.close();
	out.close();
}