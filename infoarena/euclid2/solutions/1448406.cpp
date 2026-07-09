/*
Dandu-se T perechi de numere naturale (a, b), sa se calculeze cel mai mare divizor comun al numerelor din fiecare pereche in parte.
Fisierul de intrare euclid2.in contine pe prima linie numarul T de perechi. Urmatoarele T linii contin cate doua numere naturale a si b.
In fisierul de iesire euclid2.out se vor scrie T linii. A i-a linie din acest fisier contine cel mai mare divizor comun al numerelor din perechea de pe linia i+1 din fisierul de intrare.
Restrictii
1 ≤ T ≤ 100 000
Pentru fiecare pereche, 2 ≤ a, b ≤ 2 * 109
*/

#include <iostream>
#include <fstream>

using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int main()
{
    long t,a,b,aux;
    f>>t;
    for(int i = 1; i <= t; i++)
    {
        f>>a;
        f>>b;
        if(a < b) {
            aux = a;
            a = b;
            b = aux;
        }
        while(b > 0) {
            aux = a%b;
            a = b;
            b = aux;
        }
        g<<a<<"\n";
    }
    return 0;
}
