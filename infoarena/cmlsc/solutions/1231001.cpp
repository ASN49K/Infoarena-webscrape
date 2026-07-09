/*
  Cerinta:Fie v un vector cu N elemente. Se numeste subsir de lungime K al vectorului v un nou
  vector v' = (vi1, vi2, ... viK), cu i1 < i2 < ... < iK. De exemplu, vectorul v = (5 7 8 9 1 6)
  contine ca subsir sirurile (5 8 6) sau (7 8 1), dar nu contine subsirul (1 5). Se dau doi
  vectori A si B cu elemente numere naturale nenule. Sa se determine subsirul de lungime maxima
  care apare atat in A cat si in B.
*/
//Genial
//Metoda programarii dinamice
#include <fstream>
#include <iostream>

#define NMax 1024
using namespace std;

int m,n, a[NMax], b[NMax], D[NMax][NMax], sir[NMax], bst;

int maxim(int a,int b)
{
    if (a>b)
        return(a);
        else return(b);
}

int main()
{
    int i, j;

    ifstream f("cmlsc.in");
    ofstream g("cmlsc.out");

    f>>m>>n;
   for (i=1; i<=m; i++)
       f>>a[i];
   for (i=1; i<=n; i++)
       f>>b[i];

   f.close();

    //Determinare inceput Second property
    for (i=1; i<=m; i++)
        for (j=1; j<=n; j++)
            if (a[i] == b[j])
                D[i][j] = 1 + D[i-1][j-1];
            else
                D[i][j] = maxim(D[i-1][j], D[i][j-1]);

   //Determinare sfarsit First property

    bst=0;
    for (i = m, j = n; i; )
        if (a[i] == b[j])
            {
                bst=bst+1;
                sir[bst] = a[i];
                i=i-1;
                j=j-1;
            }
        else if (D[i-1][j] < D[i][j-1])
            j=j-1;
        else
            i=i-1;


    g<<bst<<"\n";
    for (i = bst; i>=1; --i)
        g<<sir[i]<<" ";


    g.close();
    return 0;
}
