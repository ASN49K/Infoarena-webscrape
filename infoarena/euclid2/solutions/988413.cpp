//Algoritmul lui Euclid
//	Cel mai mare divizor comun dintre doua numere naturale a si b este cel mai mare numar natural pozitiv d care divide ambele numere.
//
//	Cerinta
//	Dandu - se T perechi de numere naturale(a, b), sa se calculeze cel mai mare divizor comun al numerelor din fiecare pereche in parte.
//
//	Date de intrare
//	Fisierul de intrare euclid2.in contine pe prima linie numarul T de perechi.Urmatoarele T linii contin cate doua numere naturale a si b.
//
//	Date de iesire
//	In fisierul de iesire euclid2.out se vor scrie T linii.A i - a linie din acest fisier contine cel mai mare divizor comun al numerelor din perechea de pe linia i + 1 din fisierul de intrare.
//
//	Restrictii
//	1 ≤ T ≤ 100 000
//	Pentru fiecare pereche, 2 ≤ a, b ≤ 2 * 109
//	Exemplu
//	euclid2.in	euclid2.out
//	3
//	12 42            6
//	21 7			 7
//	9 10			 1
//

#include <iostream>
#include <fstream>
#include <set>

using namespace std;

fstream in("euclid2.in", ios::in);    // fisierul din care extrag datele
fstream out("euclid2.out", ios::out); // fisierul in care scriu datele

void citesc_date(int &aux1, int &aux2)
{
	in >> aux1;
	in >> aux2;
}

void verific_divizor(set<int> &multime, int valoare)  // functia cu care voi verifica ( si insera ) divizorii 
{
	set<int>::iterator k;  // iteratorul cu care voi parcurge multimea
	int z;                 // variabila cu care voi parcurge for-ul
	for (z = valoare; z >= 1; z--)
	{	
		if (valoare % z == 0)
			multime.insert(z);
	}
}

int caut_cmmdc(set<int> multime1, set<int> multime2)  // functia cu care voi returna valorea cmmdc-ului
{
	int aux = 0;           // variabila in care voi retine cmmdc
	set<int>::iterator it; // iteratorul cu care voi parcurge multimea
	for (it = multime2.begin(); it != multime2.end(); it++)
		if (multime1.find(*it) != multime1.end())
			aux = *it;
	return aux;
}

void main()
{
// VARIABILE
	int tin_minte = 0,  // variabila in care voi retine divizorul maxim
		i = 0,          // variabila de parcurgere a vectorilor
		nr1 = 0,        // variabila in care voi retine primul numar
		nr2 = 0,        // variabila in care voi retine cel de-al doilea numar
		aux = 0;        // variabila auxiliara

	set<int> primul_nr, // setul de numere din prima multime
		al_doilea_nr;   // setul de numere din a doua multime

	set<int>::iterator it, // iteratorul de pargurgere
		it2;               // iteratorul de rezerva pentru parcurgere

// ALGORITM & APELAREA FUNCTIILOR
	in >> aux;

	while ( i < aux )
	{	
		// citirea perechii care urmeaza a fi verificata
		citesc_date(nr1, nr2);

		// introduc datele in cele 2 multimi
		verific_divizor(primul_nr, nr1);
		verific_divizor(al_doilea_nr, nr2);

		// cautarea celui mai mare divizor comun
		aux = caut_cmmdc(primul_nr, al_doilea_nr);

		// il scriu in fisier
		out << aux << endl;

		// sterg cele 2 multimi pentru a putea introduce totul de la inceput
		it = primul_nr.begin();
		it2 = primul_nr.end();
		primul_nr.erase(it, it2);
		it = al_doilea_nr.begin();
		it2 = al_doilea_nr.end();
		al_doilea_nr.erase(it, it2);

		//incrementez contorul
		i++;
	}


	system("PAUSE");
}