#include <iostream>
#include <fstream>

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

#define maxx(a,b) (a>b?a:b)

int a[1100], b[1100], c[1100][1100], i, j, n, m, d[1100], k ;

int main()
{
    f >> n >> m;

    for( i = 1; i <= n; i ++ )
        f >> a[i];

    for( j = 1; j <= m; j ++ )
        f >> b[j];

    for( i = 1; i <= n; i ++ )
        for( j = 1; j <= m; j ++ )
            if( a[i] == b[j] )
                c[i][j] = c[i-1][j-1] + 1;
            else
                c[i][j] = maxx( c[i-1][j], c[i][j-1]);




    g << c[n][m] << '\n';
    i = n;
    j = m;
    while ( i > 0 && j > 0)
    {
        if( a[i] == b[j] )
        {
            d[ ++ k ] = a[ i ];
            i --;
            j --;
        }
        else if( c[i-1][j] > c[i][j-1] )
            i--;
        else
            j--;
    }

    for( i = k; i>= 1; i -- )
        g << d[i] << " ";
    f.close();
    g.close();
    return 0;
}
