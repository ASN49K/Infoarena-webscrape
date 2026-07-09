/*
Ex :
Fractii

Gigel, intr-o zi cand isi facea temele la matematica, s-a apucat sa scrie pe o foaie de hartie, un sir de fractii ireductibile de forma P/Q cu 1 ≤ P,Q ≤ N, unde N este un numar natural ales de el. De exemplu, pentru N = 4 el a obtinut urmatorul sir:

1/1, 1/2, 1/3, 1/4, 2/1, 2/3, 3/1, 3/2, 3/4, 4/1, 4/3

Gigel s-a apucat apoi sa numere cate fractii a obtinut pentru N = 4 si a vazut ca sunt 11.
Cerinta

Fiind dat un numar natural N, sa se determine cate fractii sunt in sirul de fractii construit dupa regulile de mai sus.
Date de intrare

Fisierul de intrare fractii.in contine pe prima linie numarul natural N.
Date de iesire

Fisierul de iesire fractii.out trebuie sa contina un numar natural pe prima linie care reprezinta cate fractii sunt in sir.
Restrictii si precizari

    1 ≤ N ≤ 1.000.000

*/
#include <iostream>
#include <fstream>
using namespace std;
int cmmdc (int a,int b)
{
        while (a != 0 && b!=0)
        {
            (a > b) ? a%=b : b%=a ;
        }

        if (a != 0)
            return a;
       else
            return b;
}
int main()
{
    fstream f, g;
    long n,m,l;
    f.open("euclid2.in", fstream::in);
    g.open("euclid2.out", fstream::out);
    f >> l;
    for(int i = 0;i<l;i++)
    {
        f>>n;
        f>>m;
        g << cmmdc(n,m);
        g <<endl;

    }
    /*
    long a, c, j, i;
    fstream f;
    f.open("fractii.in", fstream::in);
    f >>a;
    c = 0;
    for(i = 1;i<=a;i++)
    {

        for(j = 1;j<=a;j++)
        {

            if(cmmdc(i,j) == 1)
            {

                c++;
            }

        }
    }
    f.close();
    f.open("fractii.out", fstream::out);
    f << c;
    return 0;
    */
}

