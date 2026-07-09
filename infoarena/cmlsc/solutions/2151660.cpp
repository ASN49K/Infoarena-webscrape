#include <iostream> //subsir de lungime maxima
#include <fstream>  //care apare atat in A cat si in B
#define NMAX 1026 //LCS != cea mai lunga subsecventa.
#define si short int

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

si n, m;
si a[NMAX], b[NMAX];
si d[NMAX][NMAX];

void citire(si v[], si n)
{
    si i;
    for(i=1;i<=n;++i)
        f>>v[i];
}

short int CMLSC()
{
    si i, j;
    for(i=1;i<=n;++i)
        for(j=1;j<=m;++j)
            if(a[i]==b[j])d[i][j]=d[i-1][j-1] + 1;
            else d[i][j] = max(d[i][j-1], d[i-1][j]);
    return d[n][m];
}

void afis(si i, si j)
{
    if(i==0 || j==0)return;

    if(a[i]==b[j]){
        afis(i-1, j-1);
        g<<a[i]<<' ';
    }
    else if(d[i][j-1] > d[i-1][j]) afis(i, j-1);
    else afis(i-1, j);
}

int main()
{
    f>>n>>m;
    citire(a, n);
    citire(b, m);

    g<<CMLSC()<<'\n';
    afis(n, m);

    return 0;
}
