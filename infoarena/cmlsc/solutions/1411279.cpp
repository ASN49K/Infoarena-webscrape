/* Sa se determine subsirul de lungime maxima care apare atat in A cat si in B. */
// O(N*M)

/* D[i][j] = este lungimea CMLSC folosind DOAR primele i elemente din v si DOAR
primele j elemente din w */
#include <fstream>
#include <algorithm>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int n,m,nr,v[1050],w[1050],fin[1050]n,d[1050][1050];
int main()
{
    f>>n>>m;
    for (int i=1; i<=n; ++i) f>>v[i];
    for (int i=1; i<=m; ++i) f>>w[i];
    for (int i=1; i<=n; ++i)
       for (int j=1; j<=m; ++j)
            if (v[i]==w[j]) d[i][j]=d[i-1][j-1]+1;
            else d[i][j]=max(d[i][j-1],d[i-1][j]);
    g<<d[n][m]<<'\n';
    int i=n;
    int j=m;
    while (i!=0 && j!=0)
       {
           if (v[i]==w[j])
            {
                ++nr;
                fin[nr]=v[i];
                --i;
                --j;
            }
           else if (d[i-1][j]>d[i][j-1]) --i;
           else --j;
       }
    for (int i=nr; i>=1; --i) g<<fin[i]<<' ';
    g<<'\n';
    f.close(); g.close();
    return 0;
}
