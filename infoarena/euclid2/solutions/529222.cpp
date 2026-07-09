// Algoritmul lui Euclid

// Determinarea CMMDC

// Algoritm: CMMDC pentru cele t perechi de numere (a,b)

// Restrictii
// 1 <= t <= 100 000
// Pentru fiecare pereche, 2 <= a, b <= 2 * 10^9

#include <iostream.h>
#include <fstream.h>

int a, b, T;

int cmmdc(int a, int b)
{
    if (b==0) return a;
    return cmmdc(b, a % b);
}

int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");

    f>>T;
    for (; T!=0; --T)
    {
        f>>a>>b;
        g<<cmmdc(a,b)<<endl;
    }        

    return 0;
}

