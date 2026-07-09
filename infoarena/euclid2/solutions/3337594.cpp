/**
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
**/

#include <fstream>

using namespace std;

int main()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    int T;
    long long a,b,r;
    fin>>T;
    for(int i=1;i<=T;i++){
        fin>>a>>b;
        while(b!=0){
            r=a%b;
            a=b;
            b=r;
        }
        fout<<a<<endl;
    }
    return 0;
}
