#include <iostream>
#include <fstream>

using namespace std;

ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");

struct pereche
{
    int nr1;
    int nr2;
};
pereche v[100001];

int a, b, r, n, i ;

int main ()
{
    fin >> n;

    for ( i = 1; i <= n; i ++)
    {
        fin >> v[i].nr1 >> v[i].nr2;

        a = v[i].nr1;
        b = v[i].nr2;

        if ( v[i].nr2 > v[i].nr1)
            b = v[i].nr1;
            a = v[i].nr2;

        while (b)
        {
            r = a % b;
            a = b;
            b = r;
        }    
        fout << a << "\n";

    }


return 0;
}