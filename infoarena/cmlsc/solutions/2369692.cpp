#include <bits/stdc++.h>
#define dim 1030

using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int b[dim], c[dim], sub[dim], k;
int a[dim][dim], n, j, i, m;
int main()
{
    f >> n >> m;
    for ( i = 1 ; i <= n ; i++ )
        f >> b[i];

    for ( i = 1 ; i <= m ; i++ )
        f >> c[i];

    for (i = 1 ; i<=n; i++)
    {
        for ( j= 1 ; j <= m ; j++)
        if ( b[i] == c[j] )
            a[i][j] = a[i-1][j-1]+1;
        else
            a[i][j] = max(a[i-1][j], a[i][j-1]);
    }
    i= n  , j =m;
    while ( a[i][j] )
    {
        if ( a[i][j] == a[i-1][j])
        i--;
        if ( a[i][j] == a[i][j-1])
            j--;

        k++;
        sub[k] = b[i];

        i--;
        j--;

    }

    g << a[n][m] <<"\n";
    for ( i= k; i >= 1; i--)
        g << sub[i] << " ";
    return 0;
}
