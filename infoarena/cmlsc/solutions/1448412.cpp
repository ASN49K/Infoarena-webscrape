/*
Fie v un vector cu N elemente. Se numeste subsir de lungime K al vectorului v un nou vector v' = (vi1, vi2, ... viK),cu i1 < i2 < ... < iK.
De exemplu, vectorul v = (5 7 8 9 1 6) contine ca subsir sirurile (5 8 6) sau (7 8 1), dar nu contine subsirul (1 5). Se dau doi
vectori A si B cu elemente numere naturale nenule. Sa se determine subsirul de lungime maxima care apare atat in A cat si in B.

Fisierul de intrare cmlsc.in contine pe prima linie M si N, numarul de elemente pentru vectorul A, respectiv pentru B. A doua linie
contine M numere naturale, elementele vectorului A. A treia linie contine descrierea vectorului B sub acelasi format.

Fisierul de iesire cmlsc.out va contine pe prima linie MAX, lungimea maxima a unui subsir comun. A doua linie va contine MAX numere
ce reprezinta un subsir comun pentru A si B. Daca exista mai multe solutii se poate afisa oricare.

1 ≤ M, N ≤ 1024
Numerele din cei doi vectori nu depasesc 256
*/

#include <iostream>
#include <fstream>

using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int main()
{
    int m,n,k = 0,a[256],b[256],c[256];
    f>>n>>m;

    for(int i = 0; i < n; i++)
        f>>a[i];
    for(int j = 0; j < m; j++)
        f>>b[j];
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(a[i] == b[j])
            {
                c[k] = a[i];
                k++;
            }
        }
    }
    g<<k<<"\n";
    for(int i = 0; i < k; i++)
        g<<c[i]<<" ";
    return 0;
}
