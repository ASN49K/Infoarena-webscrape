//#include <iostream>
//#include<fstream>
//using namespace std;
//ifstream fin ("euclid2.in");
//ofstream fout ("euclid2.out");

 /* cod initial :
Cel mai mare divizor comun dintre doua numere naturale a si b este cel mai mare numar natural pozitiv d care divide ambele numere.
Fisierul de intrare euclid2.in contine pe prima linie numarul T de perechi. Urmatoarele T linii contin cate doua numere naturale a si b.
In fisierul de iesire euclid2.out se vor scrie T linii. A i-a linie din acest fisier contine cel mai mare divizor comun al numerelor din perechea de pe linia i+1 din fisierul de intrare.


int main()
{   int t,a,b;
    fin>>t;
    while(t) {
        fin>>a>>b;
        while(a!=b) {

            if(a>b) a=a-b;
            else b=b-a;
        }

     fout<<a<<"\n";
    t--;
    }


return 0;
}

*/
#include <stdio.h>

int T, A, B;

int gcd(int a, int b)
{
    if (!b) return a;
    return gcd(b, a % b);
}

int main(void)
{
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);

    scanf("%d", &T);
    for (; T; --T)
    {
        scanf("%d %d", &A, &B);
        printf("%d\n", gcd(A, B));
    }

    return 0;
}


