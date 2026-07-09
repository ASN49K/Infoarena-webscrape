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

using namespace std;

fstream in("euclid2.in", ios::in);    // fisierul din care extrag datele
fstream out("euclid2.out", ios::out); // fisierul in care scriu datele

int cmmdc(int nr1, int nr2)
{
	// caz in care nr2 este cmmdc-ul celor 2 numere, nu are rost sa folosesc memorie in plus, deci trebuie verificat primul
	if (nr1 % nr2 == 0)
		return nr2;

	// iar daca nu, folosindu-ma de recursivitate apel iar functia pana gasesc ceea ce caut
	return cmmdc(nr2, nr1%nr2);
}

int main()
{ 
	int contor = 0,                    // variabila care va retine prima linie din 
		nr1,                           // variabila in care citesc primul numar din pereche
		nr2,                           // variabila in care voi citi al doilea numar din pereche
		aux;                           // variabila in care voi retine rezultatul intors de cmmdc
	in >> contor;
	while (contor)
	{
		in >> nr1 >> nr2;
		aux = cmmdc(nr1, nr2);
		out << aux << endl;
		contor--;
	}
	in.close();
	out.close();
}