#include <iostream>
#include <fstream>

using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

const int N = 1026;

int a[N], b[N], d[N][N], n, m;

void subsir( int i, int j )
{
    if ( i == 0 || j == 0 )
        return;
    if ( a[i] == b[j] )
    {
        subsir(i-1, j-1);
        out << a[i]<<' ';
        return;
    }
    if ( d[i-1][j] > d[i][j-1] )
        subsir(i-1, j);
      else subsir(i, j-1);
}

int max( int x, int y )
{
    if ( x < y )
        return y;
    return x;
}

int main()
{
    int i, j;
    in >> n >> m;
    for ( i = 1; i <= n; i++ )
        in >> a[i];
    for ( i = 1; i <= m; i++ )
        in >> b[i];
    for ( i = 1; i <= n; i++ )
    {
        for ( j = 1; j <= m; j++ )
        {
            if ( a[i] == b[j] )
                d[i][j] = 1+ d[i-1][j-1];
            else d[i][j] = max(d[i-1][j], d[i][j-1]);
        }
    }
    out << d[n][m]<<'\n';
    subsir(n, m);
    return 0;
}
///cmlsc, edist
///d[i][j] = lung celui mai lung subsir comun format cu primele i din a si primele j din b
///d[i][j] = 1+d[i-1][j-1]               daca a[i] = b[j]
///          max( d[i-1][j], d[i][j-1])  daca a[i]!= b[j]
