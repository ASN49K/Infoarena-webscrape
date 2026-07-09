#include <iostream>
#include <fstream>
using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

//https://www.infoarena.ro/problema/euclid2
//Cerinta:
//Dandu-se T perechi de numere naturale (a, b),
//sa se calculeze cel mai mare divizor comun al numerelor din fiecare pereche in parte.

//Date de intrare:
//Fisierul de intrare euclid2.in contine pe prima linie numarul T de perechi.
//Urmatoarele T linii contin cate doua numere naturale a si b.

//Date de iesire:
//In fisierul de iesire euclid2.out se vor scrie T linii.
//A i-a linie din acest fisier contine cel mai mare divizor
//comun al numerelor din perechea de pe linia i+1 din fisierul de intrare.

//https://en.wikipedia.org/wiki/Euclidean_algorithm#Euclidean_division
int gcdEuclid(int x1, int x2){
    int gcd;
    int a = min(x1, x2);
    int b = max(x1, x2);

    while(b){
        gcd = b;
        b   = a % b;
        a   = gcd;
    }

    return gcd;
}


int main()
{
    int a[100], b[100], T;

    // Read data:
    f >> T;
    for (int i=0; i<T; i++){
        f >> a[i] >> b[i];
        g << gcdEuclid(a[i], b[i])<<"\n";
    }
    return 0;
}

