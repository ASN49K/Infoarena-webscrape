/*
Algoritmul lui Euclid
Cel mai mare divizor comun dintre doua numere naturale a si b este cel mai mare numar natural pozitiv d care divide ambele numere.

Cerinta
Dandu-se T perechi de numere naturale (a, b), sa se calculeze cel mai mare divizor comun al numerelor din fiecare pereche in parte.

Date de intrare
Fisierul de intrare euclid2.in contine pe prima linie numarul T de perechi. Urmatoarele T linii contin cate doua numere naturale a si b.

Date de iesire
In fisierul de iesire euclid2.out se vor scrie T linii. A i-a linie din acest fisier contine cel mai mare divizor comun al numerelor din perechea de pe linia i+1 din fisierul de intrare.

Restrictii
1 ≤ T ≤ 100 000
Pentru fiecare pereche, 2 ≤ a, b ≤ 2 * 109
*/
#include <bits/stdc++.h>

using namespace std;

ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");

int cmmdc ( int a, int b );

int main()
{
    int n, x, y;

    fin >> n;
    while ( n-- ) fin >> x >> y, fout << cmmdc ( x, y ) << '\n';

    return 0;
}

int cmmdc ( int a, int b )
{
    int r = a % b;

    while ( r )
    {
        a = b;
        b = r;
        r = a % b;
    }

    return b;
}
