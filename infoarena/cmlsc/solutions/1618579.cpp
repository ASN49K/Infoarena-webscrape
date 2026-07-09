/* Sa se determine subsirul de lungime maxima care apare atat in A cat si in B. */
// O(N*M)

/* D[i][j] = este lungimea CMLSC folosind DOAR primele i elemente din v si DOAR
primele j elemente din w
   Cel mai lung subsir comun folosind primele i caractere din v
   si primele j caractere din w este:
    1) Daca v[i] == w[j] => ca mai adaug un caracter la cel mai lung subsir
                            folosind primele i-1/j-1 caractere
    2) Daca v[i] != w[j] => ca folosesc doar unul dintre cele doua caractere
            - Daca folosesc pe v[i] si NU pe w[j]=> ca trebuie sa stiu pe D[i][j-1]
            - Daca folosesc pe w[j] si NU pe v[i]=> ca trebuie sa stiu pe D[i-1][j]
            Deci voi alege minimul.
    */
#include <fstream>11
#include <algorithm>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int n,m,nr,v[1050],w[1050],sol[1050],d[1050][1050];

int main()
{
    f>>n>>m;
    for (int i=1; i<=n; ++i) f >> v[i];
    for (int i=1; i<=m; ++i) f >> w[i];

    for (int i=1; i<=n; ++i)
       for (int j=1; j<=m; ++j)
            if (v[i]==w[j]) d[i][j] = d[i-1][j-1]+1;
            else d[i][j] = max(d[i][j-1],d[i-1][j]);

    g<<d[n][m]<<'\n'; // rezultatul

    // reconstituirea - unei solutii (pot fi mai multe)
    // presupune sa va cum a fost calculat d[n][m] => d[n1][m1] => ....
    int i=n;
    int j=m;
    while (i!=0 && j!=0)
       {
           if (v[i]==w[j]) // caractere egale
            {
                ++nr;
                sol[nr]=v[i];
                --i;
                --j;
            }
           else if (d[i-1][j]>d[i][j-1]) --i;
           else --j;
       }

    // soluti a fost generata invers
    for (int i=nr; i>=1; --i) g<<sol[i]<<' ';
    g<<'\n';
    f.close(); g.close();
    return 0;
}
