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
#include <set>

using namespace std;

fstream in("cmlsc.in", ios::in);
fstream out("cmlsc.out", ios::out);


int main()
{
	set<int> A, B,                          // Multimea ce-mi va retine unul dintre cele 2 siruri initiale
		C;                                  // Multimea in care voi retine subsirul
	set<int>::iterator itA, itB, itC;	    // iteratorii de parcurgere ( stanga-dreapta )
	set<int>::reverse_iterator ita, itb;    // iteratorii de parcurgere ( dreapta-stanga )

	short nA, nB;                           // Variabila in care voi retine numarul maxim de cifre dintr-o multime anume
	int aux = 0,                            // Variabila auxiliara
		nrA = 0, nrB = 0, nrC = 0;          // Variabila in care voi retine numarul de elemente din fiecare multime
	// Citirea limitelor pentru cele 2 multimi
	in >> nA >> nB;
	nrA = nA; nrB = nB;

	// Citirea din fisier a valorilor, si introducerea acestora, in prima multime
	while (nA)
	{
		in >> aux;
		A.insert(aux);
		nA--;
	}

	// Citirea din fisier a valorilor, si introducerea acestora, in cea de-a doua multime
	while (nB)
	{
		in >> aux;
		B.insert(aux);
		nB--;
	}

	// Din moment ce in heap voi avea ambele multimi ordonate crescator trebuie decat sa verific unde incepe si unde se termina subsirul
	// Iar din moment ce stiu dimensiunile acestora, pot pune anumite conditii pentru a nu consuma memorie aiurea
	itA = A.begin();
	itB = B.begin();
	ita = A.rbegin();
	itb = B.rbegin();

	if (nrA < nrB)
	{
		// caut in multimea B elementele multimii A
		while (nrB)
		{
			if (B.find(*itA) != B.end())
			{
				if (B.find(*ita) != B.end())
				{
					// ambele conditii sunt indeplinite deci introduc datele si ies cu break din while
					for ( ; itA != A.end(); itA++)
					{
						C.insert(*itA);
						nrC++;
					}
					break; // ies fortat din while deoarece am gasit solutia
				}
				else
					ita++;
			}
			else
				itA++;
			nrB--;
		}
	}
	else
	{	
		// caut in multimea A elementele multimii B
		while (nrA)
		{
			if (A.find(*itB) != A.end())
			{
				if (A.find(*itb) != A.end())
				{
					// ambele conditii sunt indeplinite deci introduc datele si ies cu break din while
					for ( ; itB != B.end(); itB++)
					{
						C.insert(*itB);
						nrC++;
					}
					break; // ies fortat din while deoarece am gasit solutia
				}
				else
					itb++;
			}
			else
				itB++;
			nrA--;
		}
	}

	// inserarea rezultatului in fisier
	out << nrC << '\n';
	for (itC = C.begin(); itC != C.end(); itC++)
		out << *itC << ' ';

	// inchiderea fiserelor
	in.close();
	out.close();
}