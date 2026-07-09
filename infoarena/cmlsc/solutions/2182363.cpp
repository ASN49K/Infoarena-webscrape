#include <bits/stdc++.h>

using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int n, m, k;
int a[1030], b[1030], v[1030];
int d[1030][1030];

int main()
{
    in>>n>>m;
    for( int i = 1; i <= n; i++ )
        in>>a[i];
    for( int i = 1; i <= m; i++ )
        in>>b[i];

    for( int i = 1; i <= n; i++ )
        for( int j = 1; j <= m; j++ )
            if( a[i] == b[j] )
                d[i][j] = 1 + d[i-1][j-1];
            else
                d[i][j] = max( d[i-1][j], d[i][j-1] );

    out<<d[n][m]<<"\n";

    int i = n;
    int j = m;

    while( i >= 1 && j >= 1 )
    {
        while( d[i][j] == d[i-1][j] )
            i--;
        while( d[i][j] == d[i][j-1] )
            j--;

        if( i >= 1 && j >= 1 )
            v[++k] = a[i];

        i--;
        j--;
    }

    while( k >= 1 )
    {
        out<<v[k]<<" ";
        k--;
    }

    return 0;
}
